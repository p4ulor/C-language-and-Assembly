#include <stdio.h>


int main() {

    int tuna = 10;
    printf("Adress \t\t Name \t Value\n");

    printf("%p \t %s \t %d \n", &tuna, "tuna", tuna);

    int *  pTuna = &tuna;

    printf("%p \t %s \t %d \n", pTuna, "tuna", tuna);

    printf("%p \t %s \t %d \n", &pTuna, "tuna", tuna);

    printf("\n*pTuna: %d \n", *pTuna); //dereferencing a pointer

    *pTuna = 19;

    printf("\n*pTuna: %d \n", *pTuna); //dereferencing a pointer
    printf("\nTuna %d \n", tuna);

    //video 44
	return 0;
}
