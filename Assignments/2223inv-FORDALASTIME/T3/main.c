#include <stdio.h>  /* printf     */
#include <stdlib.h> //for malloc
#include <string.h>
#include <errno.h>
#include <math.h>

#include <curl/curl.h>
#include <jansson.h>

CURL *curl;
CURLcode res;
FILE *filePointer;

typedef struct Product {
    int id;
    float price;
    const char* description;
    const char* category;
} Product;

void printProduct(const Product* product){
    printf("Product -> id: %d, price: %f, description: %s, category: %s\n", 
            product->id, product->price, product->description, product->category);
}

typedef struct User {
    int id;
    const char *name;
} User;

void printUser(const User* user) {
    printf("User -> id: %d, name: %s\n", user->id, user->name);
}

typedef struct Products {
    int id;
    size_t quantity;
} Products;

typedef struct Cart {
    int id;
    size_t n_products;
    Products* products;
    /* 
    struct {  //having unnamed/anonymous structs is bad... I couldnt make it work
        int id;
        size_t quantity;
    } products[]; 
    */
   int total; //added for ex4
   int userId; //added for ex4
} Cart;

void printCart(Cart* cart) {
    char products[100] = "";
    
    char stringID[100] = "";
    char stringQuantity[100] = "";

    Products* initPointer = cart->products;

    strcat(products, "[");
    for(int i = 0; i < cart->n_products; i++){
        //printf("((%d))", cart->products[i].id);

        sprintf(stringID,"{id: %d, ", cart->products[i].id);
        strcat(products, stringID);

        sprintf(stringQuantity,"quantity: %ld}", cart->products[i].quantity);
        strcat(products, stringQuantity);
        if(i!=cart->n_products-1) strcat(products, ", ");
        //(cart->products)++;
    }
    strcat(products, "]");
    printf("Cart -> id: %d, n_products: %ld, products: %s\n", cart->id, cart->n_products, products);

    cart->products = initPointer;
}

json_t* http_get_json_data(const char *url){
    filePointer = fopen("response", "w");
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, filePointer); //write to file (I couldnt find a way to store in variable)

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    fclose(filePointer);

    ///////// read the result that was stored in the file /////////

    filePointer = fopen("response", "r");
    if (filePointer == NULL) {
		fprintf(stderr, "fopen: %s\n", strerror(errno));
	}

    json_error_t error;
	json_t *obj = json_loadf(filePointer, JSON_DECODE_ANY, &error);
    if (!json_is_object(obj)) {
		fprintf(stderr, "***error: on line %d: %s\n", error.line, error.text);
		fclose(filePointer);
	}
    return obj;
}

void extractProduct(json_t* obj, Product* product){ //json obj to Product struct
    json_t *id = json_object_get(obj, "id");
	if (!json_is_integer(id)) {
		fprintf(stderr, "name not found\n");
		json_decref(obj);
	}
    product->id = (int) json_integer_value(id);

    json_t* price = json_object_get(obj, "price");
    (*product).price = json_number_value(price);

    json_t* desc = json_object_get(obj, "description");
    const char* description = json_string_value(desc);
    //char* descriptionCopy = malloc(strlen(description)*sizeof(char)); // Previously this was needed to work, now its not needed to work idk why... just to overcome the error:  warning: assignment discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]...
    //strcpy(descriptionCopy, description);
    product->description = description;

    json_t* categ = json_object_get(obj, "category");
    const char* category = json_string_value(categ);
    //char* categoryCopy = malloc(strlen(category)*sizeof(char)); // Previously this was needed to work, now its not needed to work idk why... just to overcome the error:  warning: assignment discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]...
    //strcpy(categoryCopy, category);
    product->category = category;
}

void getProduct(const char *url, Product* product){
    json_t* obj = http_get_json_data(url);
    extractProduct(obj, product);
}

Product* products_get() {
    json_t* obj = http_get_json_data("https://dummyjson.com/products");
    json_t* _length = json_object_get(obj, "limit"); //total = 100, limit = 30
    int length = json_integer_value(_length);
    printf("limit=%d\n", length);
    Product* products = calloc(length, sizeof(Product));
    Product* startingPointerProducts = products;

    json_t* jsonProductsArray = json_object_get(obj, "products");
    json_t* jsonProductsItem;

    for(int i = 0; i < length; i++){
        jsonProductsItem = json_array_get(jsonProductsArray, i);
        if(jsonProductsItem==NULL) break;
        extractProduct(jsonProductsItem, products);
        *(products)++;
    }

    return startingPointerProducts;
}

void extractUser(json_t* obj, User* user){ //json obj to User struct
    json_t *id = json_object_get(obj, "id");
    user->id = (int) json_integer_value(id);

    json_t* nam = json_object_get(obj, "firstName");
    const char* name = json_string_value(nam);
    user->name = name;
}

User* user_get(){
    json_t* obj = http_get_json_data("https://dummyjson.com/users");
    json_t* _length = json_object_get(obj, "limit"); //total = 100, limit = 30
    int length = json_integer_value(_length);
    printf("limit=%d\n", length);
    User* users = calloc(length, sizeof(User));
    User* startingPointerUsers = users;

    json_t* jsonUsersArray = json_object_get(obj, "users");
    json_t* jsonUsersItem;

    for(int i = 0; i < length; i++){
        jsonUsersItem = json_array_get(jsonUsersArray, i);
        if(jsonUsersItem==NULL) break;
        extractUser(jsonUsersItem, users);
        *(users)++;
    }

    return startingPointerUsers;
}

void extractCart(json_t* obj, Cart* cart){ //json obj to Cart struct
    json_t *id = json_object_get(obj, "id");
    cart->id = (int) json_integer_value(id);

    json_t* totalProducts = json_object_get(obj, "totalProducts");
    cart->n_products = json_number_value(totalProducts);

    json_t* jsonProductsArray = json_object_get(obj, "products");
    json_t* jsonProductsItem;

    //(cart->products) = (Products*) calloc(cart->n_products, (sizeof(int) + sizeof(size_t))); //if defining products like-> Products* products;
    cart->products = calloc(cart->n_products, sizeof(Products));
    Products* initPointer = cart->products;
    for(int i = 0; i < cart->n_products; i++){
        jsonProductsItem = json_array_get(jsonProductsArray, i);
        if(jsonProductsItem==NULL) break;

        json_t* id = json_object_get(jsonProductsItem, "id");
        json_t* quantity = json_object_get(jsonProductsItem, "quantity");
        
        (cart->products)->id = (int) json_integer_value(id);
        
        (cart->products)->quantity = (int) json_integer_value(quantity);
        (cart->products)++;
    }
    cart->products = initPointer;
    //printf("---%d\n", (cart->products)->id);

    //Added for ex4:
    json_t *total = json_object_get(obj, "total");
    cart->total = (int) json_integer_value(total);

    json_t *userId = json_object_get(obj, "userId");
    cart->userId = (int) json_integer_value(userId);
}

Cart* carts_get(){
    json_t* obj = http_get_json_data("https://dummyjson.com/carts");
    json_t* _length = json_object_get(obj, "limit"); //total = 100, limit = 30
    int length = json_integer_value(_length);
    printf("limit=%d\n", length);
    Cart* carts = calloc(length, sizeof(Cart) + 5*sizeof(struct Products));
    Cart* startingPointerCarts = carts;

    json_t* jsonCartsArray = json_object_get(obj, "carts");
    json_t* jsonCartItem;

    for(int i = 0; i < length; i++){
        jsonCartItem = json_array_get(jsonCartsArray, i);
        if(jsonCartItem==NULL) break;
        extractCart(jsonCartItem, carts);
        *(carts)++;
    }

    printf("-------%d\n", (startingPointerCarts->products)[0].id);

    return startingPointerCarts;
}

void ex1(){
    Product product = {
        product.id = 0,
        product.price = 0,
        product.description = "",
        product.category = "",
    };
    getProduct("https://dummyjson.com/products/1", &product);
    printProduct(&product);
}

void ex2_1(){
    Product* products = products_get();
    Product* startingPointerProducts = products; //because free() should be called on the starting pointer

    for(int i = 0; i < 30; i++){
        printProduct(products++);
    }

    /* while(products){ //causes segmentation fault
        printProduct(products++);
    } */

    free(startingPointerProducts);
}

void ex2_2(){
    User* users = user_get();
    User* startingPointerUsers = users;

    for(int i = 0; i < 30; i++){
        printUser(users++);
    }

    free(startingPointerUsers);
}

void ex2_3(){
    Cart* carts = carts_get();
    Cart* startingPointerCarts = carts;

    for(int i = 0; i < 20; i++){
        printCart(carts++);
    }

    free(startingPointerCarts);
}

void ex2_csv_products(){
    Product* products = products_get();
    Product* startingPointerProducts = products; //because free() should be called on the starting pointer

    filePointer = fopen("products.csv", "w");

    for(int i = 0; i < 30; i++){
        fprintf(filePointer, "%d, %f, %s, %s\n", products->id, products->price, products->description, products->category);
        products++;
    }

    free(startingPointerProducts);
}

void ex2_csv_users(){
    User* users = user_get();
    User* startingPointerUsers = users;

    filePointer = fopen("users.csv", "w");

    for(int i = 0; i < 30; i++){
        fprintf(filePointer, "%d, %s\n", users->id, users->name);
        users++;
    }

    free(startingPointerUsers);
}

void ex2_csv_carts(){
    Cart* carts = carts_get();
    Cart* startingPointerCarts = carts;

    filePointer = fopen("carts.csv", "w");

    for(int i = 0; i < 20; i++){
        char products[100] = "";
        char stringID[100] = "";
        char stringQuantity[100] = "";

        strcat(products, "[");
        for(int i = 0; i < carts->n_products; i++){
            sprintf(stringID,"{id: %d, ", carts->products[i].id);
            strcat(products, stringID);

            sprintf(stringQuantity,"quantity: %ld}", carts->products[i].quantity);
            strcat(products, stringQuantity);
            if(i!=carts->n_products-1) strcat(products, ", ");
        }
        strcat(products, "]");

        fprintf(filePointer, "%d, %ld, %s\n", carts->id, carts->n_products, products);
        carts++;
    }

    free(startingPointerCarts);
}

// gcc main.c -lcurl -ljansson 
int main(){ //Uncomment to test what you wanna test
    printf("ex1\n"); //Get products/1
    //ex1();

    printf("ex2.1\n"); //Products
    //ex2_1();

    printf("ex2.2\n"); //Users
    //ex2_2();

    printf("ex2.3\n"); //Carts
    ex2_3();

    printf("ex2-CSV\n");
    //ex2_csv_products();
    //ex2_csv_users();
    //ex2_csv_carts();

    fclose(filePointer);

    return 0;
}