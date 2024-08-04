#include <stdio.h>

int reverse_bits( int value ){
    int count = 0;
    int res = 0;
    for(int st = value; st != 0; st >>= 1, count++);
    int mask = 1;
    for(int i = count; i > 0; i--){
        if(mask & value){
            res = res | (1 << i - 1);
        }
        mask <<= 1;
    }
    return res;
}


int main(){
    printf("cena -> %d\n",reverse_bits( 232 ));
}