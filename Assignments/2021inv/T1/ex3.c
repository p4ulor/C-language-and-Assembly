#include <stdio.h>
#include <string.h>
#define ULONG_BIT sizeof(unsigned long)*8 //64
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#include <stddef.h>
#include <ctype.h>


size_t string_split(char *text, char *words[], int words_size){
char *p = text;
int numPalavras = 0;

while(1) {
	while(isspace(*p)) p++;

	if(*p == '\0') return numPalavras;

	words[numPalavras++] = p;

	while(!isspace(*p) && *p != '\0') p++;

	if(*p == '\0') return numPalavras;

	*p++ = '\0';

	if(numPalavras >= words_size) return numPalavras;
	}

  /* size_t charNumber= 0; //iterate through text array witch we see as just chars
  size_t letterNumber = 0; //iterate through palavra array witch contains letters
  
  fgets(text,sizeof(text),stdin);

  int length = strlen(text);
  
  
  
  if (text[0] == '\0') return 0;
  for(short a = 0; a<words_size; a++){
	  char palavra[100];
	  for( ; charNumber<length || text[charNumber]!='\n'; charNumber++){
		  if(text[charNumber] != ' ' || text[charNumber] != '\n' || text[charNumber] != '\t'){
			  palavra[letterNumber++]=text[charNumber];
		  } else {
			  words[numOfWords++]=palavra;
			  break;
		  }
		  charNumber++;
	  }
  }
   */
/*  char * token = strtok (text," \t\n");
  printf ("Splitting string \"%s\" into tokens:\n",text);
  fgets(text,sizeof(text),stdin);

  int length = strlen(text);
	 
  while (token != NULL && length!=0 || token!='\0') {
    printf ("%s\n",token);
    token = strtok (NULL ," \t\n");
	length--;
  }
  
  return numOfWords; */
	
}
/*Recebe uma string, e poe cada palavra(ignorando espacos) em cada posicao de um array de strings */

int main() {
	char text[] = "Ola \n tudo bem? \t sim";
	char *words[10];
	int nwords = string_split(text, words, ARRAY_SIZE(words));
	
	for(int i = 0; i < nwords; i++){
		printf("%s\n", words[i]);
	}
    return 0;
}
