#include <stdio.h>
#include <stdlib.h>

//global and local variables
//global -> defined outside functions
//local -> defined inside functions

//pass by reference/adress vs pass by value
void passByValue(int i){ //pass by value COPIES the value received
    i = 99;
}

//this receives the actuall adress of the variable, thus, the changes made reflect outside of this scope
//the way around it is that u return and assign the value returned to the variable u want to alter
void passByAddress(int * i){ 
    *i = 5;
}

int main() {
   int j = 10;
   passByValue(j);
   printf("%d\n", j);
   passByAddress(&j);
   printf("%d\n", j);
   return 0;
}

//Passing an array to a function that's like bellow, passing the array throgh the function
//passes the first adress of the array
int sort(int array[], int arraySize);



