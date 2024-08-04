#include<stdio.h>

size_t my_strlen(const char *str);

int main() {
    char a[]  = "Ay";
    char b[]  = "Okok";
    char c[]  = "Ok10";
    char d[]  = "A\0";
    
    printf("a -> %ld\n", my_strlen(a));
    printf("b -> %ld\n", my_strlen(b));
    printf("c -> %ld\n", my_strlen(c));
    printf("d -> %ld\n", my_strlen(d));

    return 0;
}