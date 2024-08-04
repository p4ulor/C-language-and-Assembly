#include <stdio.h>
#include <math.h>
#include <limits.h>

int round_to_ceiling_int(float value) {

    if(value==0) return 0;
    int x=0;
    if(value<0) {
         while(value<x) {
            if(x==INT_MIN) return INT_MIN;
            x--;
        }
    }
    else {
        while(value>x) {
            if(x==INT_MAX) return INT_MAX;
            x++;
        }
    }
}

int round_to_int(float value){
    int integerPart = (int) value;
    unsigned char integerPartSize=0;
    int n = integerPart;
    while(n>0){
        integerPartSize++;
        n=n/10;
    }
    int allNumbers = value * 10;
    unsigned char decimalDigit = allNumbers % 10;
    printf("\nfirstdecimal%d", decimalDigit);
    if(decimalDigit>=5) return ++integerPart;
    if(decimalDigit<5) return integerPart;
    
}

int main(){
    float a = 2.0;
    printf("A -> %d\n", round_to_int(a));

    float b = 23.4;
    printf("B -> %d\n", round_to_int(b));

    float c = 25.5;
    printf("C -> %d\n", round_to_int(c));

    float d = 268.8;
    printf("D -> %d\n", round_to_int(d));

    float e = 2777.89;
    printf("E -> %d\n", round_to_int(e));

    float f = 2777.223;
    printf("E -> %d\n", round_to_int(f));

    //TODO: test with negative numbers

    return 0;
}
