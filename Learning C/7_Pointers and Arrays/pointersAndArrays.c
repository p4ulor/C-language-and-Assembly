#include <stdio.h>


int main() {

    int meatBalls[] = {7, 8, 9, 21, 30};
    printf("Element \t adress \t value \n");
    for(int i = 0; i<5; i++){
        printf("meatBalls[%d] \t %p \t %d \n", i, &meatBalls[i], meatBalls[i]);
    }

    printf("\nmeatBalls \t\t %p \n", meatBalls); //meatBalls is the pointer to the first element
    printf("\nmeatBalls \t\t %d \n", *meatBalls); 

    char meat[] = "Ora boas tudo bem";
    for(int i = 0; i<5; i++){
        printf("meat[%d] \t %p \t %d \n", i, &meat[i], meat[i]);
    }

	return 0;
}