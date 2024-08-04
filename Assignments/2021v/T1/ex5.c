#include <stdio.h> //in order to use printf() and fgets
#include <stdlib.h> //for malloc
#include <math.h> //in order to use pow()
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#include <unistd.h>    // for getopt 
#include <string.h>

#define MAXINPUTLENGTH 400
#define MAXCOMMANDLENGTH 100
#define NUMBEROFCOMMANDS MAXINPUTLENGTH/MAXCOMMANDLENGTH
//usar fopen fgetc and fputc para ler e escrever linhas completas

unsigned int getLenghtOfCharPointer(char* str){ //or use strlen from <string.h>
	unsigned int size = 0;
	while(*str++ != '\0')
		size++;
	return size;
}

int main() {
	int c = 0;
	
	printf("\n$ find_in_file ");
	unsigned int inputIdx = 0;
	char input[MAXINPUTLENGTH];
	fgets(input, MAXINPUTLENGTH, stdin);
	
	char * const argv = input;
	unsigned int size = getLenghtOfCharPointer(input);
	while ((c = getopt(size, &argv, "o:i:cw")) != -1){
		switch (c) {
			case 'o':
			
			break;
			
			case 'i':
			
			break;
			
			case 'c':
			
			break;
			
			case 'w':
			
			break;
			
			case '?':
			printf("\n ?");
			break;
		}
	}
	
	printf("\n");
	return 0;
}