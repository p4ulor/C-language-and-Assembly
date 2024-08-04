#include <stdio.h>

int check_for_pattern(int value, int pattern){
	while(1){
        if(pattern && 0x1)
            break;
        pattern = pattern >> 1;   
    }
    while (value != 0){
        if(pattern && value)
            return 1;
        value = value >> 1;
    }
    return 0;	
}

int main(){
    printf("%d", check_for_pattern(0xa, 5));
    printf("%d", check_for_pattern(0xc, 3));
    printf("%d", check_for_pattern(0xb, 0x2d));
}