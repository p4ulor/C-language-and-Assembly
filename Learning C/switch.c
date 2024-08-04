#include <stdio.h>

int main() {
    char grade = 'A';

   switch(grade){ 
       case 'A' : printf("That's an A"); break;
       case 'B' : printf("Could've been better"); break;
       case 'C' : printf("I C you didn't study"); break;
       case 'D' : printf("You shouldn't like this D"); break;
       default : printf("what");
   } 
   return 0;
}