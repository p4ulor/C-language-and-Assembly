#include <stdio.h>
#include <math.h>

// for compiling, use "-lm" because of <math.h>

//alternative, not using log2:
int count_trailing_zeros(unsigned long word){
    unsigned char size = word & -word;
    unsigned char indexes = -1;
	while(size!=0){
        size = size >> 1;
        indexes++;
    }
		
	return indexes;
}

int count_trailing_zeros2_log(unsigned long word){ //simpler but probably requires more computing (more expensive) because of many multiplications
    return log2(word & -word);
}


int main(){

    printf("%u\n", count_trailing_zeros(8)); //1000 -> 3
    printf("%u\n", count_trailing_zeros(12)); //1100 -> 2
    printf("%u\n", count_trailing_zeros(13)); //1101 -> 0
    printf("%u\n", count_trailing_zeros(14)); //1110 -> 1
    printf("%u\n", count_trailing_zeros(15)); //1111 -> 0
    printf("%u\n", count_trailing_zeros(16)); //1 0000 -> 4
    printf("%u\n", count_trailing_zeros(32)); //10 0000 -> 5
    printf("%u\n", count_trailing_zeros(2112)); //1000 0100 0000 -> 6

    printf("Log2:\n");

    printf("%u\n", count_trailing_zeros2_log(8)); //1000 -> 3
    printf("%u\n", count_trailing_zeros2_log(12)); //1100 -> 2
    printf("%u\n", count_trailing_zeros2_log(13)); //1101 -> 0
    printf("%u\n", count_trailing_zeros2_log(14)); //1110 -> 1
    printf("%u\n", count_trailing_zeros2_log(15)); //1111 -> 0
    printf("%u\n", count_trailing_zeros2_log(16)); //1 0000 -> 4
    printf("%u\n", count_trailing_zeros2_log(32)); //10 0000 -> 5
    printf("%u\n", count_trailing_zeros2_log(2112)); //1000 0100 0000 -> 6
    return 0;
}