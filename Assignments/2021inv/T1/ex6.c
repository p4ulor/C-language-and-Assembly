#include <stdio.h>
#include <string.h>
#include <stdlib.h> //cuz of exit(0);
//#include <ctype.h> //cuz of isalpha and isdigit
#define ULONG_BIT sizeof(unsigned long)*8 //64
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define MAX 100
#define DEFAULTFILEOUT "fileOutput.csv"

char* replaceSeparator(const char currentSep,const char newSep, char** contents){
	char* retval = *contents;
	while(**contents!='\0') {
		if(**contents==currentSep) **contents=newSep;
		printf("%c",**contents); 
		(*contents)++; //(os parantesis SAO necessarios!)
		//if(**contents!=EOF) break;
	}
	printf("\nSeparator change done\n");
	return retval;
}

void normalize(char* name){
}

void changeContentsWithPattern(char* name, char* name2, char* contents){
	
}

void deleteColumn(char* name){
	
}

const char changeOutputDestination(char* name){
	char isAFile = 0;
	printf("\nThe name of the output file will be changed to %s\n", name);
	while(*name!='\0'){ 
		if(*name++=='.') isAFile = 1;
	}
	if(isAFile==0) { 
		printf("\nNot valid file destiny provided. It will now be by default %s \n", DEFAULTFILEOUT);  
		return 0; 
	} //if no dot '.' is found, its not a file, exit;
	else return 1;
	
}


int main(int argc, char *argv[]) {
	if(argc<2) { printf("Not enough arguments\n");  exit(0); }
	
	char* fileName = argv[argc-1]; //source filename is supposed to be the last parameter in argv
	printf ("Original file name provided:\n%s\n", fileName);
	char fileNameOutput[ARRAY_SIZE(argv[argc-1])+15]; //or use malloc, +1 cuz of \0
	strcpy(fileNameOutput, fileName); //by default, the fileNameOutput will be the same as the source filename
	
	char isAFile = 0;				//if no dot '.' is found, the name of the source filename is not valid, exit;
	while(*fileName!='\0'){
		if(*fileName++=='.') isAFile = 1;
	}
	if(isAFile==0) { printf("No valid file provided\n");  exit(0); } 

	long length;
	char* contents = 0;       
	//char* contentsBeginPointer;
	FILE* f = fopen(argv[argc-1], "r"); //https://stackoverflow.com/questions/2174889/whats-the-differences-between-r-and-rb-in-fopen

	if (f){								//https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c
	
	  fseek (f, 0, SEEK_END);
	  length = ftell (f);
	  if (length==0) {
        printf("file is empty\n"); exit(0);
      }
	  fseek (f, 0, SEEK_SET); //go back to the beggining of the file
	  contents = malloc (length);
	  
	  if (contents){
		fread (contents, 1, length, f);
	  }
	  
	  
	  fseek (f, 0, SEEK_SET); //go back to the beggining of the file
	  char c;
	  int count = 1;
	  while((c=fgetc(f))!=EOF){
        if (c == '\n') count++;
	  }      
	  printf("The file has %d lines\n ",count); 
	
	  fclose (f);
	}
	
	printf ("Original file has the following content:\n%s\n", contents);
	
	
	
	
	

	printf("\nCommands: \n-o <destiny file>(should be called before the last string, that is the original file name) \n-d <column> (delete column) \n-f <column> <pattern> (select lines with certain chars) \n-n (normalizar) \n-s <old tab char> <new tab char>\n\n"); //instructions
	printf("The last string at the args input, should be the original file name\n\n");
	unsigned char parameterIndex = 1; //ao correr, por exemplo "$ ./ex6 -o file2.csv ...; argv[0] vai ter "./ex6"
	
	while((char)argv[parameterIndex][0]=='-'){
		printf("Encontrado commando: %s\n", argv[parameterIndex]);
		switch(argv[parameterIndex][1]){
			case 'o': 
				if(changeOutputDestination(argv[parameterIndex+1])){
					strcpy(fileNameOutput,argv[parameterIndex+1]);
				} 
				else strcpy(fileNameOutput,DEFAULTFILEOUT);
				break;
			case 'd': deleteColumn(argv[parameterIndex+1]);  break;
			case 'f': changeContentsWithPattern(argv[parameterIndex+1], argv[parameterIndex+2], contents); parameterIndex++; break; //since it takes 2 parameters
			case 'n': normalize(fileNameOutput); break;
			case 's': printf("Will replace %c for %c \nResult:\n",argv[parameterIndex+1][0], argv[parameterIndex+2][0]) ; 
					  contents = replaceSeparator(argv[parameterIndex+1][0], argv[parameterIndex+2][0], &contents); /*contents=contentsBeginPointer; we can either reset the pointer position like this or receive it with a return*/ 
					  parameterIndex++; break; //since it takes 2 parameters, theres an extra: parameterIndex++;
			default: printf("Command not found");
		}
		 parameterIndex=parameterIndex+2;
		 
	} //after this, write content into the assigned file destination
	printf ("\nNew content written to %s:\n%s\n",fileNameOutput, contents);
	f = fopen(fileNameOutput, "w");
	fprintf(f, "%s", contents);
	fclose(f);
	
	
    return 0;
}
