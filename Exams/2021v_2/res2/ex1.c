#include <stdio.h>

void setbits(unsigned *pvalue, int position, int nbits, unsigned new_value){
    int mask = 0;
    if(nbits == 0) return ;
    for(; nbits != 0; nbits--)
        mask = (mask << 1) + 1;
    for(; position != 1; position--){
        mask <<= 1;
        //new_value <<= 1;
    }
    int v = (~mask & *pvalue) | (mask & new_value);
    *pvalue = v; 
}

int main(){
    int c = 0xf;
    int *f = &c;
    setbits(f, 2, 2, 2);
    printf("cena -> %d\n",*f);
}