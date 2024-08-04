#include <stdio.h>
//#include <limits.h>
#include <stdlib.h>
#define CHAR_BIT sizeof(char)*8
#define LONG_BIT sizeof(unsigned long)*8
/*
Retorna o maior valor positivo que pode ser armazenado pelo número de bits
equivalente ao número de bits de um char(CHAR_BIT). Vezes o valor indicado pelo parâmetro nchars.
Se o valor não for representável num unsigned long, deve retornar zero
*/

unsigned long max_value(size_t nchars){
	unsigned short dimension = nchars * CHAR_BIT; 
	printf("\nWith %ld chars, the dimension will be a total of %hd bits.\n", nchars, dimension); //%hd will convert the char to (short) number automatically
	if(dimension > LONG_BIT || dimension<1) return 0;
	else {
		unsigned long res = 1;
		for(char i = 0; i<dimension-1; i++){
			res = res << 1;
		}
		return res-1;
	}
}

int main() {
	//printf("Note: the dimention of unsigned long is %lu \n", LONG_BIT);
	//printf("Note: the dimention of char: is %ld \n", CHAR_BIT);
	printf("Enter a number of chars(max 99): \n");
	
	signed char input;
	scanf("%hhi", &input); //https://en.wikipedia.org/wiki/C_data_types  for chars-> %c (or %hhu for numerical output)
	if(input<1 || (input/100)!=0) {
		printf("The value is inferior to 1 or way to big for the context of the problem, try again\n");
		main();
	}
	unsigned long res = max_value(input);
	printf("Thus, the max positive value is %lu. ", res);
	if(res==0) printf("(Can't be represented with a unsigned long)\n");
	main();
    return 0;
}
