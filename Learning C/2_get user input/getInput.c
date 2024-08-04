#include <stdio.h>
#include <string.h> //in order to use strlen and strcat
#include <stdlib.h> //in order to use malloc and memset
#define MAXINPUTSIZE 15
#define INTROSTRING "Enter a string: "
#define OUTPUTSTRING "String is: %s\n"

unsigned char getLenghtOfCharPointer(char* str){ //or use strlen from <string.h>
	unsigned char size = 0;
	while(*str++ != '\0')
		size++;
	return size;
}

//------------- GETS --------------------------------------------

void getInputGETS(){ // NOT USED !!!!!!!!!!!!!!!!!!!!!!!!!
	char buf[MAXINPUTSIZE];
	printf(INTROSTRING);
	//gets(buf); 
	printf(OUTPUTSTRING, buf);
}

//---------------------------------------------------------------

void getInputGETCHAR(){
   printf("Enter character: ");
   char c = getchar();
   printf("Character entered: ");
   putchar(c);
}

void howGetCharWorks(){ //in runtime, the moment u press the leter, getchar() executes and moves to the next instruction
	char a = getchar();
	char b = getchar();
	char c = getchar();
	putchar(a);
	putchar(b);
	putchar(c);
}

void getInputChar(){
	char c = 0;
	unsigned int size = MAXINPUTSIZE;
	unsigned int i = 1;
	char* string = malloc(MAXINPUTSIZE*sizeof(char));
	char* init_string = string;
	//memset(string, '\0', MAXINPUTSIZE); 
	
	while(1) {
		//if(i>MAXINPUTSIZE) break;
		char c = getchar();
		if(c=='\n') break;
		*string++ = c;
		i++;
		
		if(i>size){
			size = size*2;
			if(size>65535) break;
			string = (char *) realloc(init_string, size*sizeof(char));
			init_string = string;
			if (string == NULL) {
				printf("error");
				return;
			}
			
			unsigned int x = 1;
			while(x!=i){
				string++;
				x++;
			}
		}
	}
	printf("%s\n", init_string);
	printf("Spaced used: %d\n", getLenghtOfCharPointer(init_string));
	printf("maxsize: %u, Space counted: %u\n", size, i-1); //-1 excluding 'enter'
	free(init_string); //you can only free it from the pointer returned by malloc. That is to say, only from the beginning of the block. You can't free a portion of the block from the inside.
}


//---------------------------------------------------------------


void getInputFGETS(){
	char buf[MAXINPUTSIZE];
	printf(INTROSTRING);
    fgets(buf, MAXINPUTSIZE, stdin);
	getchar();
    printf(OUTPUTSTRING, buf);
		
	/* int len = strlen(buf);
	buf[len - 1] = '\0'; */
}


//---------------------------------------------------------------


void getInputOneWordSCANF(){
	char buf[MAXINPUTSIZE];
    printf(INTROSTRING);
    // Here \n indicates that take the input
    // until newline is encountered
    scanf("%[^\n]s", buf);
	
    printf(OUTPUTSTRING, buf);
}

void getInputSCANF(){
	char buf[MAXINPUTSIZE];
    printf(INTROSTRING);
    scanf("%s", buf); //putting a space before %s can be useful in some problematic contexts
	getchar();
    printf(OUTPUTSTRING, buf);
}

int main() {
	getInputSCANF();
	
    return 0;
}


