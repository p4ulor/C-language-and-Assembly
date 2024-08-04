#include <stdio.h>
#include <string.h> //for strlen
#include <ctype.h> //for toupper
#include <stdlib.h> //for malloc

// if it finds a '_' and lower character afterwards, then replace the '_' with that character in uppercase

void modify_style(char* str){
    char* pStr = str;
    char* result = malloc(strlen(str)); //or char result[strlen(str)];
    char* pResult = result;
    while(*str!='\0'){
        if(*str++=='_' && *str!=toupper(*str)){
            *pResult++ = toupper(*str++);
        } else {
            --str;
            *pResult++ = *str++;
        }
        str++;
    }
    *pResult = '\0';
    strcpy(pStr, result);
}

int main(){
    char string1[] = "ay_ok_ta bom_Sim"; //char* string1 = "ay_ok_ta bom_Sim"; will not work //https://stackoverflow.com/questions/6149045/segmentation-fault-when-trying-to-modify-a-string
    modify_style(string1);
    printf("Modified: %s\n", string1);
    return 0;
}