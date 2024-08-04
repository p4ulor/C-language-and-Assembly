#include <stdio.h>
#include <string.h>

char * strtrim(char *str, const char *delim){
	for( ; strchr(delim, *str) != NULL; ++str){
		;
	}
	char *ptr = str;
	str += strlen(str)-1;

	for( ;strchr(delim, *str) != NULL; --str); //equivalent format
	*(str+1)='\0';
	return ptr;
}

int main(){
    printf("%s\n", strtrim(", abcd. ", " ,.:"));
	getchar();
	return 0;
}