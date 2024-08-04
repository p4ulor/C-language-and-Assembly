#include<stdio.h>

void vec24_write(unsigned int vector[], int index, unsigned int value){
    if((index+1)%4==0){
        if(index>3) --index;
        unsigned int p2 = (value & 0xFF0000) << 8;
        unsigned int p1 = (value & 0xFF00) << 16;
        unsigned int p0 = (value & 0xFF) << 24;

        //printf("p2: %u", p2); printf("p1: %u", p1); printf("p0: %u", p0);
        
        vector[index-3] = (vector[index-3] & 0x0FFFFFF) | p2;
        vector[index-2] = (vector[index-2] & 0x0FFFFFF) | p1;
        vector[index-1] = (vector[index-1] & 0x0FFFFFF) | p0;
    } else {
        if(index>3) --index;
        vector[index] = (value & 0x0FFFFFF) | vector[index] & 0xFF000000;
    }
}

unsigned int vec24_read(unsigned int vector[], int index){
    if((index+1)%4==0){
        if(index>3) --index;
        unsigned int p2 = (vector[index-3] >> 8) & 0xFF0000;
        unsigned int p1 = (vector[index-2] >> 16) & 0xFF00;
        unsigned int p0 = (vector[index-1] >> 24) & 0xFF;

        //printf("p2: %u ", p2); printf("p1: %u ", p1); printf("p0: %u ", p0);

        return p2 | p1 | p0;
    } else {
        if(index>3) --index;
        return vector[index] & 0xFFFFFF;
    }
}

int main(){
    unsigned int vector[] = {
        0b01001100100000000000000000000011, //8 388 611 (index=0) [0]
        0b01100110100000000000000000000100, //8 388 612 (index=1) [1]
        0b00110011100000000000000000000101, //8 388 613 (index=2) [2]
        //5 006 899 (index=3)
        0b01001100100000000000000000000110, //8 388 614 (index=4) [3]
        0b01100110100000000000000000000111, //8 388 615 (index=5) [4]
        0b00110100100000000000000000001000 //8 388 616 (index=6) [5]
        //5 006 900 (index=7)
    };
    printf("Index 0 has: %d\n", vec24_read(vector, 0));
    printf("Index 1 has: %d\n", vec24_read(vector, 1));
    printf("Index 2 has: %d\n", vec24_read(vector, 2));
    printf("Index 3 has: %d\n", vec24_read(vector, 3));

    printf("Index 4 has: %d\n", vec24_read(vector, 4));
    printf("Index 5 has: %d\n", vec24_read(vector, 5));
    printf("Index 6 has: %d\n", vec24_read(vector, 6));
    printf("Index 7 has: %d\n\n", vec24_read(vector, 7));

    vec24_write(vector, 2, 8388614);
    vec24_write(vector, 3, 8388614);
    vec24_write(vector, 7, 8388614);

    printf("Index 2 has: %d\n", vec24_read(vector, 2));
    printf("Index 3 has: %d\n", vec24_read(vector, 3));
    printf("Index 7 has: %d\n", vec24_read(vector, 7));

    return 0;
}