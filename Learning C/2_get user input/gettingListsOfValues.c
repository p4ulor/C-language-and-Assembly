#include <stdio.h>

int getNames(){
    int size = 5;
    char meatBalls[size];
    for(int i = 0; i<size; i++){
       printf("How many meatballs you ate in day %d?\n", i+1);
       scanf(" %d", meatBalls[i]);
    }
}

int getNums(){
    int size = 5;
    int meatBalls[size];
    for(int i = 0; i<size; i++){
       printf("How many meatballs you ate in day %d?\n", i+1);
       scanf(" %d", meatBalls[i]);
    }
}

int main() {
    
    return 0;
}
