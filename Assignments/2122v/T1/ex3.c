#include <stdio.h>
#include <string.h>

//The method considers that string0 is always greater then string2 and the series of replacements that occur
//can use strncmp, strlen, memmove
void string_find_substitute(char* string, char* string1, char* string2) {
    if(strcmp(string1, string2)==0) return;

    size_t sizeResult = strlen(string)*strlen(string2);
    char result[sizeResult];
    char* pResult = result;
    char* initPointerResult = result;
    
    size_t sizeString1 = strlen(string1);
    size_t sizeString2 = strlen(string2);

    char* initPointerString = string;
    char* initPointerString1 = string1;

    size_t numberOfEqualIndexes;

    while(*string!='\0'){
        numberOfEqualIndexes = 0;
        while(*string==*string1 && *string!='\0'){ //no need to add *string1!='\0'
            numberOfEqualIndexes++;
            string++; string1++;
        }
        if(numberOfEqualIndexes==sizeString1) {
            memmove(pResult, string2, sizeString2);
            pResult+=sizeString2;
            string1 = initPointerString1;
        } else {
            *pResult++ = *string++;
        }
    }
    *pResult = '\0'; 
    memmove(initPointerString, initPointerResult, sizeResult); //since the memory allocated for array result will end after this function, we can't just do string = initPointerResult;
}

int main(){
    
    //simple replacement, occurence and replacement of the same size
    char string0_A[] = "AAAAAaaa"; //original
    char string1_A[] = "aaa"; //occurence to replace
    char string2_A[] = "AAA"; //replacement
    string_find_substitute(string0_A, string1_A, string2_A);
    printf("A -> %s\n", string0_A); //result -> AAAAAAAA

    char string0_B[] = "AAAAAaaa";
    char string1_B[] = "AAAAA";
    char string2_B[] = "aaaaa";
    string_find_substitute(string0_B, string1_B, string2_B);
    printf("B -> %s\n", string0_B); //result -> aaaaaaaa

    //replacement when the replacement string is smaller than the occurence
    //replacing at the beggining
    char string0_C[] = "AAAAAaaa";
    char string1_C[] = "AAAAA";
    char string2_C[] = "aaa";
    string_find_substitute(string0_C, string1_C, string2_C);
    printf("C -> %s\n", string0_C); //result -> aaaaaa

    //replacing at the end and resulting in a smaller string
    char string0_D[] = "AAAAAaaa";
    char string1_D[] = "aaa";
    char string2_D[] = "a";
    string_find_substitute(string0_D, string1_D, string2_D);
    printf("D -> %s\n", string0_D); //result -> AAAAAa

    //replacement when the replacement string is greater than the occurence
    //replacing at the beggining
    char string0_E[] = "1234";
    char string1_E[] = "12";
    char string2_E[] = "0123";
    string_find_substitute(string0_E, string1_E, string2_E);
    printf("E-> %s\n", string0_E); //result -> 012334

    //appending at the end
    char string0_F[] = "12";
    char string1_F[] = "2";
    char string2_F[] = "123";
    string_find_substitute(string0_F, string1_F, string2_F);
    printf("F-> %s\n", string0_F); //result -> 1123

    return 0;
}

/*
https://www.tutorialspoint.com/c_standard_library/c_function_memmove.htm
*/