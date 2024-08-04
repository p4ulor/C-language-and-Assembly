
#include <stdio.h>
#include <stdlib.h>

#include "structPerson.h"

int main() {
    
    struct Person bucky;
    struct Person emily;

    bucky.userID = 1;
    emily.userID = 2;

    puts("Enter name user 1");

    fgets(bucky.firstName, 25, stdin);

    printf("%s\n", bucky.firstName);

   return 0;
}