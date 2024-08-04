#include <stdio.h>
#include <math.h> // for floor and ceil, needs to add -lm to compilation command
#include <stdlib.h> //for abs, https://stackoverflow.com/a/29577846
/*
As a rule of thumb the mathematical functions that operate on floating point numbers are in math.h,
and the ones that operate on integers are in stdlib.h.
*/
int main() {
   float bacon = 1.2345577;
   float sausage = 13.7;
   printf("bacon is %.2f\n", floor(bacon));
   printf("sausage is %.2f\n", floor(sausage));

   printf("bacon is %.2f\n", ceil(bacon));
   printf("sausage is %.2f\n", ceil(sausage));

   int n = -1;
   printf("%d\n",abs(n));
   return 0;
}