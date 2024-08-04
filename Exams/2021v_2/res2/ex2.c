#include <stdio.h>
#include <string.h>

char *parse_uri(char *uri){
    
    char *ptr = strchr(uri, '?');
    char *str = strstr(ptr, "%20");
    
    int len = strlen(str) - 3;
    int c = str - ptr; 
    
    printf("len -> %d\n", len);
    printf("ptr -> %s\n", ptr);
    printf("str -> %s\n", str);

    memcpy(ptr + c, " ", 1);
    memmove(ptr + c + 1 , str + 3, len);
    memcpy(ptr + c + 1 + len, "\0", 1);

    return (ptr + 1);
}


int main(){
    char c[50] = "/cgi-bin/age?ana%20maria";
    printf("cena -> %s\n",parse_uri(c));
}