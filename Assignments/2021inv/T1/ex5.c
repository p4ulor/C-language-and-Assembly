#include <stdio.h>
#include<stdlib.h>
#define ULONG_BIT sizeof(unsigned long)*8 //64
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define MAX 20

struct tm {
   int tm_sec;
   int tm_min;
   int tm_hour;
   
   int tm_mday;
   int tm_mon;
   int tm_year;  
   
   int tm_wday;  // set to 0
   int tm_yday;	// set to 0
   int tm_isdst;	// set to 0
};

void doThis(char* data, char** string){ //why?????????
    *data++=**string; (*string)++; //incrementar valor que o pointer aponta para
//ou:data[0]=
	*data++=**string; (*string)++; //(os parantesis SAO necessarios!)
	(*string)++;//skip '-' or ' ' or ':'
}


void string_to_time(char *string, struct tm *tm){ //dd-mm-aaaa hh:mm:ss
	char data[5]; data[4]='\0';
	char* pData = data;
	int i;
	doThis(data,&string); //alternativa a isto-> data[0]=*string++; data[1]=*string++ (como fiz em year, mais abaixo) e meter "string++;" dps de todos os "tm->..."
	
    sscanf(data, "%d", &i);
	tm->tm_mday = i;      //day
	
	 
	
	doThis(data,&string);  
    sscanf(data, "%d", &i);
	tm->tm_mon = i;     //month
	
	
	
	data[0]=*string++;
	data[1]=*string++;
	data[2]=*string++;
	data[3]=*string++;
    sscanf(data, "%d", &i);
	tm->tm_year = i;     //year
	data[2]='\0';
	
	string++; //skip '-' or ' ' or ':'
	
	doThis(data,&string); 
    sscanf(data, "%d", &i);
	tm->tm_hour = i;     //hour
	
	
	
	doThis(data,&string);  
    sscanf(data, "%d", &i);
	tm->tm_min = i;     //minutes
	
	
	
	doThis(data,&string); 
    sscanf(data, "%d", &i);
	tm->tm_sec = i;     //seconds
	
	
	//print struct:
	
	printf("\nIn struct: %d %d %d %d %d %d \n",tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_hour, tm->tm_min, tm->tm_sec);
	
}



int main() {
	char *s;
	struct tm tmInput;
	struct tm *pointertmInput = &tmInput;
    s = malloc(256);
    printf("Type a date: \n");
    //scanf("%20s", s); // Don't read more than 20 chars, nao aceita espaços...
	fgets(s, MAX ,stdin); //assim aceita
	string_to_time(s, pointertmInput);
	free(s);
    return 0;
}
