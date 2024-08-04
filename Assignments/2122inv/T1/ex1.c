#include <stdio.h>

int check_for_pattern(int value, int pattern){
    if(value==0 || pattern == 0) return 0; //not acceptable since we only want patterns that have 1's

    while(!(pattern&1)){
        pattern = pattern >> 1;
    }

    int mask = 1;
    while(mask<=pattern){
        mask = mask << 1;
    }
    mask=mask-1; // -> from (per example) 0010 0000 (32) to -> 0001 1111 which is a size of the pattern

    while(value>0){
        if(((value&mask)^pattern)==0) return 1; //extra parentesis because of operator precedence
        value = value >> 1;
    }
    return 0;
}

int main(){
    //                                  val  pat
    printf("1 - %s\n", check_for_pattern(10, 5) ? "true" : "false");

    printf("2 - %s\n", check_for_pattern(12, 3) ? "true" : "false");

    printf("3 - %s\n", check_for_pattern(45, 11) ? "true" : "false");

    printf("4 - %s\n", check_for_pattern(46, 12) ? "true" : "false");

    printf("5 - %s\n", check_for_pattern(128, 1) ? "true" : "false");

    printf("6 - %s\n", check_for_pattern(204, 38) ? "true" : "false");

    printf("7 - %s\n", check_for_pattern(204, 15) ? "true" : "false");

    printf("8 - %s\n", check_for_pattern(120, 248) ? "true" : "false");

    return 0;
}

/*
The search only checks if there's one continuous stream of bits in value which equal to a pattern. 
This pattern must begin and end with a 1.

value:  10 ->  1010
pattern: 5 ->  0101 true

value:  12 -> 1100
pattern: 3 -> 0011 true

value:   45 -> 0010 1101
pattern: 11 -> 0000 1011 true

value:   46 -> 0010 1110     -> 0001 0111
pattern: 12 -> 0000 1100 true ->       11

value:  128 -> 1000 0000
pattern:  1 -> 0000 0001 true

value:  204 -> 1100 1100 -> 1[100 11]00
pattern: 38 -> 0010 0110 -> 00[10 011]0 true

value:  204 -> 1100 1100
pattern: 15 -> 0000 1111 false

value:  120 -> 0111 1000
pattern: 248 -> 1111 1000 false

Given this, we can see that all we need to do is right shift the value until its equal to the pattern
*/