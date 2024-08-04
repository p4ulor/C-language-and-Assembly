#include <stdio.h>



int main() {
	int number = 5;
	int* pnumber = &number;
	
	printf("pnumber's size: %d bytes, pointer addr: %p or %p, VALUE OF the pointer(should be the same \n addr of the variable it points to): %p, the value the pointer points: %d \n", 
	         (int)sizeof(pnumber),      (void*)&pnumber, &pnumber,                                                                       pnumber,                          *pnumber); //output size
	printf("\nadress of number: %p", &number);
	return 0;
}
