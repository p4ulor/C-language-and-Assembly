#include<stdio.h>

void rotate_right(unsigned long value[], size_t n); 

int main() { //gcc ex1.c ex1_asm.s
    printf("Values from most significant to least significant:\n");

    unsigned long v1[] = {0, 1}; //little-endian (least significant to most significant)
    printf("v1: %ld, %ld\n", v1[1], v1[0]);
    rotate_right(v1, 64);
    printf("v1 shifted right 64 positions: %ld, %ld\n", v1[1], v1[0]);

    unsigned long v2[] = {1, 0};
    printf("v2: %ld, %ld\n", v2[1], v2[0]);
    rotate_right(v2, 1);
    printf("v2 shifted right 1 position: %ld, %ld\n", v1[1], v2[0]);

    unsigned long v3[] = {0, 1}; 
    printf("v3: %ld, %ld\n", v3[1], v3[0]);
    rotate_right(v3, 1);
    printf("v3 shifted 1: %ld, %ld\n", v3[1], v3[0]);
    rotate_right(v3, 1);
    printf("v3 shifted 1: %ld, %ld\n", v3[1], v3[0]);
    rotate_right(v3, 62);
    printf("v3 shifted 62: %ld, %ld\n", v3[1], v3[0]);
    rotate_right(v3, 1);
    printf("v3 shifted 1: %ld, %ld\n", v3[1], v3[0]);


    return 0;
}