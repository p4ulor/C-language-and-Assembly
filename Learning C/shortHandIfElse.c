#include <stdio.h>

int main() {
   int friends = 10;
   printf("I have %d friend%s", friends, (friends!=1) ? "s" : "");
   return 0;
}
