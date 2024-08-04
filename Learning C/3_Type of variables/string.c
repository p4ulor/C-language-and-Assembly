/*
String Terminator is \0
A string is an array of chars
*/

#include <stdio.h>
#include <string.h>

int main() {
    
    char name[]= "bucky";

    //strcat
    char ham[100] = "Hey, ";
    strcat(ham, "bucky"); //"bucky is appended to ham, starting at its empty space"
    printf("%s\n",ham);

    //strcpy
    strcpy(ham, "bucky -> is awesome");
    printf("%s\n",ham);

   return 0;
}