#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


int make_mask(int position, int size){
    int res = 0;
    for(int i = 0; i < size; i++)
        res = res | (1 << position + i - 1);
    return res;
}

int main(){
    printf("%d",make_mask(2, 3));
}