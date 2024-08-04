#include <stdio.h>
#include <stdint.h>

uint64_t reverse(uint64_t val) {

    uint64_t result = 0;
    char currentIndex = 0;
    uint64_t valCopy = val;

    while(1){  
       valCopy = valCopy >> 1;  
       if(valCopy==0) break;
       currentIndex++;  
    }  

    char indexCount = currentIndex;

    uint64_t bit;
    while(currentIndex!=-1){
        printf("Current index: %d. ", currentIndex);
        bit = val >> currentIndex;
        bit = bit & 0x1;
        bit = bit << (indexCount-currentIndex);
        printf("Bit: %ld. ", bit);
        
        result = result | bit;
        printf("Result: %ld\n", result);
        
        currentIndex--;
    }
    return result;
}

int main() {
    printf("%d -> %lu\n", 197, reverse(197));
    printf("%d -> %lu\n", 2, reverse(2));
    printf("%d -> %lu\n", 5, reverse(5));
    printf("%ld -> %lu\n", 0x8000000000000000, reverse(0x8000000000000000));

    return 0;
}