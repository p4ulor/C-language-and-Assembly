#include <stdio.h>


int check_for_pattern(int value, int pattern){
    int pattern_mask = 0;
    for(; pattern % 2 == 0; pattern = pattern >> 1);
    for(; value % 2 == 0; value = value >> 1);
    printf("pattern -> %d\n",pattern);
    printf("value -> %d\n",value);
    int n_pattern = pattern;
    while(n_pattern > 0){
        pattern_mask = (pattern_mask << 1) + 1;
        n_pattern >>= 1;
    }
    printf("pattern_mask -> %d\n",pattern_mask);
    while(value > 0){
        if (pattern_mask & value == pattern) return 1;
        value >>= 1;
    }
    return 0;
}

int main(){
    printf("cena -> %d\n",check_for_pattern(0x2d, 0xb));
}


