#include <stdio.h>



int main() {
	int inte = 100;
	float flo = 31.793;
	double dou = 8.44e+11;
	char cha = 'w';
	bool boo = 0;
	
	printf("%i \n", inte);
	printf("%.2f %f \n", flo, flo);
	printf("%e \n", dou);
	printf("%g \n", dou);
	printf("%c \n", cha);
	printf("%i \n", boo);
	return 0;
}
