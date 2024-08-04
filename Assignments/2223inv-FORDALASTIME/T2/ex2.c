#include<stdio.h>

size_t my_strlen(const char *str); 

int main() {
    char a[]  = "Ay";
    char b[]  = "Okok";
    char c[]  = "Ok10";
    char d[]  = "A\0";
    char e[]  = "";
    char f[]  = "\n";
    
    printf("%s -> %ld\n", a, my_strlen(a));
    printf("%s -> %ld\n", b, my_strlen(b));
    printf("%s -> %ld\n", c, my_strlen(c));
    printf("%s -> %ld\n", d, my_strlen(d));
    printf("%s -> %ld\n", e, my_strlen(e));
    printf("%s -> %ld\n", f, my_strlen(f));

    return 0;
}