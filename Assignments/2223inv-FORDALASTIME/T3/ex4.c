#include <stdio.h>  /* printf*/
#include <stdlib.h> //for malloc
#include <string.h>

#include "main.h"

/*

# How to run ex4
## Make library
- gcc -c -fpic main.c -o main.out
- gcc -shared -o mylib.so main.out
## Incorporate library with ex4 and run
- gcc ex4.c -o ex4.out -L. mylib.so -lcurl -ljansson -Wl,-rpath,"/media/sf_C-language-and-Assembly/Exams and assignments/Trabalhos/2022inv-FORDALASTIME/T3"
- ./ex4.out

*/

int main(){
    char c = 0;
    
    while(1){
        printf("Type the option ->");
        scanf("%c",&c);

        if(c=='u'){
            User* users = user_get();
            User* startingPointerUsers = users;
        
            int n = 30;
            for(int i = 0; i < n; i++){
                //printf("Next name in the list -> %s\n", users[i].name);
                int indexNewTopName = i;
                for(int j = i+1; j < n; j++){
                    char comp = strcmp(users[j].name, users[indexNewTopName].name); //-1 if the first char is smaller (in ASCII) than that of str2.
                    if(comp < 0){ 
                        indexNewTopName = j;
                        //printf("New top name is at index %d. Name = %s \n", j, users[j].name);
                    }
                }

                if(indexNewTopName!=i){ //if a new top name was obtained
                    User* temp = malloc(sizeof(User));
                    temp->id = users[i].id;
                    temp->name = users[i].name;
                    users[i] = users[indexNewTopName];
                    users[indexNewTopName] = *temp;
                }

                //printf("New name on top of the list -> %s\n", users[i].name);
            }

            for(int i = 0; i < n; i++){
                printUser(users++);
            }

            free(startingPointerUsers);
        }


        if(c=='c'){ //Assumiu-se que a "importancia da compra" é o preço (total) de um carrinho
            Cart* carts = carts_get();
            Cart* startingPointerCarts = carts;

            int n = 20;
            for(int i = 0; i < n; i++){
                int indexNewTopCartTotal = i;
                for(int j = i+1; j < n; j++){
                    char comp = carts[j].total > carts[indexNewTopCartTotal].total;
                    if(comp){ 
                        indexNewTopCartTotal = j;
                    }
                }

                if(indexNewTopCartTotal!=i){ //if a new top total was obtained
                    Cart* temp = malloc(sizeof(Cart));
                    temp->id = carts[i].id;
                    temp->n_products = carts[i].id;
                    temp->products = carts[i].products;
                    temp->total = carts[i].total;
                    temp->userId = carts[i].userId;

                    carts[i] = carts[indexNewTopCartTotal];
                    carts[indexNewTopCartTotal] = *temp;
                }

                //printf("New name on top of the list -> %s\n", users[i].name);
            }

            for(int i = 0; i < n; i++){
                printf("Cart -> id: %d, n_products: %ld, total: %d userId: %d\n", carts->id, carts->n_products, carts->total, carts->userId);
                carts++;
            }

            free(startingPointerCarts);

        }

        if(c=='s') break;
        printf("\n");
    }

    return 0;
}