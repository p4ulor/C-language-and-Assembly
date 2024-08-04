#include <stdio.h>

int min_size_bits(int value){
    unsigned char n = 0;
    if(value<0) value = 0 - value;
	while(value>0){
        value = value >> 1;
        n++;
    }

	return ++n; //++ because it must have sign bit
}

int main(){
    printf("The value %d requires atleast %d in order to be represented in binary\n", 0, min_size_bits(0));

    //test positive values
    printf("The value %d requires atleast %d in order to be represented in binary\n", 1, min_size_bits(1));
    printf("The value %d requires atleast %d in order to be represented in binary\n", 2, min_size_bits(2));
    printf("The value %d requires atleast %d in order to be represented in binary\n", 4, min_size_bits(4));
    printf("The value %d requires atleast %d in order to be represented in binary\n", 15, min_size_bits(15));

    //test negative values
    printf("The value %d requires atleast %d in order to be represented in binary\n", -1, min_size_bits(-1));
    printf("The value %d requires atleast %d in order to be represented in binary\n", -2, min_size_bits(-2));
    printf("The value %d requires atleast %d in order to be represented in binary\n", -3, min_size_bits(-3));
    printf("The value %d requires atleast %d in order to be represented in binary\n", -4, min_size_bits(-4));
    return 0;
}