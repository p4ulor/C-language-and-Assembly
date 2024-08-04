#include <stdio.h>
#include <string.h>

char * strtrim(char *str, const char *delim){
    char *ptr = str;
    const char *coiso = delim;
    for(int i = 0; i < strlen(str) - 1; i++){
        printf("%c\n", str[i]);
        if(strchr(coiso, str[i]) != NULL){
            ptr = (str+i+1);
        }
        else break;
    }
    str = ptr;
    char * 
    for (int j = 0; j < strlen(str) - 1; j++){
        printf("%c\n", ptr[j]);
        if(strchr(coiso, str[j]) != NULL){
            memcpy(ptr, str, j);
            break;
        }
    }
    
    return ptr;
}

int main(){
    printf("cena -> %s\n",strtrim(", abcd. :", " ,.:"));
}