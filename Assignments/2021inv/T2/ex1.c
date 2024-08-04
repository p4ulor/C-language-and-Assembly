#include <stdio.h>


void rotate_left(unsigned long value[], size_t n);

int main(int argc, char *argv[]) {
    unsigned long value[] = { 0xF, 0x10 };
    for (int i = 0; i < 2; ++i) {
        printf("%d: %016lX\n", i, value[i]);
    }
    rotate_left(value, 4);
    for (int i = 0; i < 2; ++i) {
        printf("%d: %016lX\n", i, value[i]);
    }
    return 0;
}
