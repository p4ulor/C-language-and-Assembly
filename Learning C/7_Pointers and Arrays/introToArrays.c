#include <stdio.h>

int main() {
	int array[5];
    int array2[5] = {1,2,3,4,5};
	int array3[] = {1,2,3,4,5,6,7};
	char string[] = "ayok";
	//number arrays don't have the string terminator! that is: \n. They have \0
	
	//Calculating array lenghts

	//this prints the number of bytes occupied by the array
	printf("%ld\n",sizeof(array)); //prints 20bytes = 4 bytes(int) *5

	printf("%ld\n", sizeof(array)/sizeof(*array)); //calculates the lenght

	//since the calculation above is common, programs often have the macro:
	//#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

	printf("%ld\n", sizeof(string)/sizeof(*string)-1); //calculates the lenght, -1 because of \0
	
	return 0;
}

//https://stackoverflow.com/questions/19331941/why-dont-numeric-arrays-end-with-a-0-or-null-character

