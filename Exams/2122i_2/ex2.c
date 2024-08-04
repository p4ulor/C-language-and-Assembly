#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *strrstr(char *str1, char *str2){
    char *ptr = strstr(str1, str2);
    if(ptr == NULL) return NULL;
    char *res = ptr;
    for(; ptr != NULL; ptr = strstr(ptr + 1, str2))
        res = ptr;
    return res;
}

int main(){
    char c[50] = "name_cenas_name_cenas";
    char v[50] = "name";
    printf("cena -> %s\n", strrstr(c, v));
}