#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


void strclean(char *str, char *separators){
    char *new = str;
    size_t dim, start = 0;
    for(int i = 0; i < strlen(new); i++){
        if(strchr(separators, str[i]) == NULL){
            if(dim == 0) start = i;
            dim++;
        }
        else {
            memmove(str, new + start);
        }
    }

}

int main(){
    char str[50] = "asd.,.,asd,..,.";
    char delim[50] = ".,:";
    strclean(str, delim);
    printf("%s\n", str);
}