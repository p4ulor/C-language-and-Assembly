#include <stdio.h>

int min_size_bits( int value ){
    int c = 0;
    for(; value != 0; value >>= 1, c++);
    return c;
}

int main(){
    printf("cena -> %d\n",min_size_bits(128));
}