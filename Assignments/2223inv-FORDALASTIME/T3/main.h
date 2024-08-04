#include <jansson.h>

typedef struct Product {
    int id;
    float price;
    const char* description;
    const char* category;
} Product;

void printProduct(const Product* product);

typedef struct User {
    int id;
    const char *name;
} User;

void printUser(const User* user);

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

void printCart(Cart* cart);

json_t* http_get_json_data(const char *url);

void extractProduct(json_t* obj, Product* product);

void getProduct(const char *url, Product* product);

Product* products_get();

void extractUser(json_t* obj, User* user);

User* user_get();

void extractCart(json_t* obj, Cart* cart);

Cart* carts_get();

void ex1();

//(doesn't contain everything)