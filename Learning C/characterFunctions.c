#include <stdio.h>
#include <ctype.h>

int main() {
    int tuna = 'A'; //C works with letters and numbers like they are similar things

    if(isalpha(tuna)){
        if(isupper(tuna)){
            printf("%c is an upper letter\n", tuna);
            printf("Now its lower letter: %c\n", tolower(tuna));

        } else {
            printf("%c is a lower letter\n", tuna);
            printf("Now its upper letter: %c\n", toupper(tuna));
        }
    } else {
        if(isdigit(tuna)){
            printf("%c is a number\n", tuna);
        } else {
            printf("%c is a symbol\n", tuna);
        }
    }

    return 0;
}