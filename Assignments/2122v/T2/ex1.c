#include <stdio.h>
#include <stdint.h>

//compile like: gcc ex1.c ex1_asm.s

uint64_t reverse(uint64_t val);

int main() {
    printf("%d -> %lu\n", 197, reverse(197));
    printf("%d -> %lu\n", 2, reverse(2));
    printf("%d -> %lu\n", 5, reverse(5));
    printf("%ld -> %lu\n", 0x8000000000000000, reverse(0x8000000000000000));

    return 0;
}