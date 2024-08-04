#include <stdio.h> //in order to use printf()
#include <stdlib.h>
#include <math.h> //in order to use pow()
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#include <string.h>
//execute with gcc ex4.c -o ex4.out 


struct date {
	int day, month, year;
};

typedef struct person {
	char name[100];
	struct date date;
	int nif;
} Person;

size_t extract_data(Person *people[], size_t people_size, char *text){
	int nPeople = 0;
	Person* repointer = *people; //orpeople[0];
	char* string = malloc(100*sizeof(char));
	memset(string, 1, 100); //or the while loop doesnt even run cuz its all zeros or \0
	char* s = string;
	
	
	char* day = malloc(2*sizeof(char));
	char* d = day;
	memset(day, 1, 2);
	
	char* month = malloc(2*sizeof(char));
	char* m = month;
	memset(month, 1, 2);
	
	char* year = malloc(4*sizeof(char));
	char* y = year;
	memset(year, 1, 4);
	
	char* nif = malloc(sizeof(int)*sizeof(char)*8); //32
	char* n = nif;
	memset(nif, 1, sizeof(int)*8);
	
	while(*text!='\0' && people_size!=nPeople){
		
		while(*string!='\0'){
			if(*text!=',' ) *string++ = *text++;
			else string++;
		}
		//*string='\0'; //or strcpy doesnt work
		strcpy((*people)->name, s);
		
		text++; //skip ','
		
		
		while(*text!=',' && *day!='\0' && *text<='9' && *text>='0') {
			*day++ = *text++;
		}
		*day='\0';
		(*people)->date.day = atoi(d);
		
		text++; //skip ','
		
		
		while(*text!=',' && *month!='\0' && *text<='9' && *text>='0') {
			*month++ = *text++;
		}
		*month='\0';
		(*people)->date.month = atoi(m);
		
		text++; //skip ','
		
		
		while(*text!=',' && *year!='\0' && *text<='9' && *text>='0') {
			*year++ = *text++;
		}
		*year='\0';
		(*people)->date.year = atoi(y);
		
		text++; //skip ','
		
		
		while(*text!='\n' && *nif!='\0' && *text<='9' && *text>='0') {
			*nif++ = *text++;
		}
		*nif='\0';
		(*people)->nif = atoi(n);
		
		string = s; day = d; month=m; year=y; nif=n;
		
		text++; //skip '\n'
		(*people)++;
		nPeople++;
	}
	people[0] = repointer;
	return nPeople;
}



int main(){
	int sizeOfPersons = 2;
	Person* persons = malloc(sizeOfPersons * sizeof(Person));
	int nPeople = extract_data(&persons, sizeOfPersons, "Manuel,15,3,2002,125645045\nJoaquim,25,4,1974,122003088\n");
	printf("Number of persons: %d\n", nPeople);
	for(int i = 0; i<nPeople; i++){
		printf("Person Nr: %d\n", i+1);
		printf("Name: %s\n", persons->name);
		printf("Date: %d / %d / %d\n", persons->date.day, persons->date.month, persons->date.year);
		printf("NIF: %d\n\n", persons->nif);
		persons++;
	}

	
	return 0;
}