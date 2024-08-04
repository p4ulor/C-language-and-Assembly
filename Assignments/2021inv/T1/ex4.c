#include <stdio.h>
#include <string.h>
#include <math.h>
#define ULONG_BIT sizeof(unsigned long)*8 //64
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define PRECISION 6  
/*
Programe, sem usar operações de float, 
a função print_float, que representa, na forma de string C, o
valor real recebido no parâmetro value. 
A string deve ser depositada no array de caracteres apontado por
buffer, cuja dimensão é indicada em buffer_size. A representação deve ser em notação decimal, com uma
aproximação de seis casas decimais. A função devolve a dimensão da string formada


Nota: na implementação interna da função não podem ser utilizadas operações aritméticas ou lógicas de float
nem funções que operem sobre valores do tipo float. Qualquer operação de vírgula flutuante invalida a
resolução do exercício
 */
 

size_t print_float(char *buffer, size_t buffer_size, float value){
	if(buffer_size<3) return -1; //cuz it must accept atleast 0.0 (or N.N)
	int bIndex = 0;
	if(value<0.0) {
		buffer[bIndex++]='-';
		value=value*-1; //make it possitive
		if(bIndex==buffer_size) return bIndex;
	}
	
	int wholeN=value;	// extracting whole number(since wholeN is an int, it cuts the decimals)  //EXAMPLE: 268.36, wholeN=238
	value=value-wholeN;	// extracting decimal part                                               //E: 268.36 - 268 = 0.36
	
	int p = PRECISION; //E: k = 2;
	int decimalsMask = 0; int remainingWhole;
	while(p>-1){ // find out number of digits in whole number
		decimalsMask = pow(10,p); //10^2 = 100,     
		remainingWhole = wholeN/decimalsMask; // 268/100 = 2.68      
		if(remainingWhole>0) break; //breaks
	    p--;         //ease off the p, so the decimalsMask value is reduced     
	}
	// number of digits in whole number is p+1
	
	int b, c, i;
	for(i=p+1; i>0; i--){ //extracting most significant digit (whole number)
		b = pow(10,i-1);
		c = wholeN/b;
		buffer[bIndex++]=c+48; //number to char
		wholeN=wholeN % b;
		if(bIndex==buffer_size) return bIndex;
	}
	
	buffer[bIndex++] = '.';
	
	for(i=0;i<PRECISION;i++){ //extracting decimal digits till PRECISION
		value=value*10.0;
		b = value;
		buffer[bIndex++]=b+48; //number to char
		value=value-b;
		if(bIndex==buffer_size) return bIndex;
	}

	buffer[bIndex++]='\0';
	
	while (*buffer){ //or *buffer!='\0'
		printf("%c",*buffer++);
	}
	printf("\n");
	
	return bIndex-1; //dimensao da string
}



int main() {
	printf("Type the float value:\n");
	float input;
	scanf("%f", &input);
	
	char buffer[ULONG_BIT];
	char buffer_size = ULONG_BIT;
	printf("String dimension: %ld \n", print_float(buffer, buffer_size, input));
	main();
    return 0;
}
