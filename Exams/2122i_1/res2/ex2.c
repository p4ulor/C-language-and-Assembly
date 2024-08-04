#include <stdio.h>
#include <string.h>
#include <ctype.h>

void modify_style(char *str){

    char *ptr = strchr(str, '_');
    while(ptr != NULL){
        printf("%s\n", (ptr ));
        if( !isdigit(ptr[1]) ){
            memmove(ptr, ptr + 1, strlen(ptr) - 1);
            memcpy(ptr + strlen(ptr) - 1, "\0", 1);
            ptr = strchr(ptr, '_');
        }
        else ptr = strchr(ptr + 1, '_');   
    }
}

int main(){
    char c[50] = "name_and_digit_2";
    modify_style(c);
    printf("cena -> %s\n",c);
}