#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringLenght(char* string){
	int count = 0;
	while(*string++ != '\0')
		count++;
	return count;
}

void concac(char result, const char str[], const char str2[]){
	int i,j;
	for(i = 0; str[i]!='\0'; ++i){
		result[i] = str[i];
	}
	for(j = 0; str2[i]!='\0'; ++i){
		result[i+j]=str2[j];
	}
	result[i+j]= '\0';
}

bool equalStrings(const char str[], const char str2[]){
	int i = 0;
	bool isEquals = 0;
	while(str[i] == str2[i] &&
		  str[i] != '\0'    &&
		  str2[i]!= '\0'    &&
		  ){
		  ++i;
    }
	if(str[i]=='\0' && str2[i]=='\0') isEquals=1;
	return isEquals;
}
	


int main() {
	const char words1[] = "jason";
	printf("%d", stringLength(words1));
	
	const char words2[] = "ay";
	char result[50];
	
	printf("%s", concac(result, words1, words2));
	
	
	//using common string functions(from library)
	char str[100];
	int l,i,n,j;
	
	printf("\n \n, print individual characters of strings in reverse order: \n");
	printf("----------------------------------------\n");
	printf("Input the string:");
	scanf("%s", str);
	
	l = strlen(str);
	printf("the chars in reverse of the string are: \n");
	
	for(i = l; i >=0; i--){
		printf("%c", str[i]);
	}
	
	printf("\n");
	
	
	char name[25][50], temp[25];
	printf("Sort the strings of an array using bubble sort: \n");
	printf("Input the number of strings");
	scanf("%d", &n);
	
	printf("input string %d: \n", n);
	
	for(i=0; i<n;i++){
		scanf("%s",name[i]);
	}
	
	for(i=1;i<=n;i++) //bubble sort, crescent order, -> aaa, bbb, ccc
        for(j=0;j<=n-i;j++)
            if(strcmp(name[j],name[j+1])>0)
            {
                strncpy(temp,name[j], sizeof(temp) - 1);
                strncpy(name[j],name[j+1], sizeof(name[j]) - 1);
                strncpy(name[j+1],temp, sizeof(name[j] + 1) - 1);
            }

    printf("The strings after sorting :\n");

    for (i = 0; i <= n; i++)
        printf("%s\n", name[i]);
	
	
    
	return 0;
}
