#include <stdio.h> //in order to use printf()
#include <stdlib.h>
#include <math.h> //in order to use pow()
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define FLOAT_SIZE sizeof(float)*8
#define PRECISION 6
//execute with gcc ex2.c -o ex2.out -lm                 add -lm because we use pow() from math.h


unsigned char getLenghtOfCharPointer(char* str){ //or use strlen() from <string.h>
	unsigned char size = 0;
	while(*str++ != '\0')
		size++;
	return size;
}

int print_float(char* str, float value){        //we're going to have to bet the str has the proper size
	//printf("size of str: %d", getLenghtOfCharPointer(str));
	int i = 0;
	int mask;
	
	if(value<0.0) {
		str[i++]='-';
		value = 0 - (value);                    //make value positive to ease our next operations
	}
	
	int valueWhole=value;	                    // extracting whole number(since valueWhole is an int, it cuts the decimals)  
	printf("whole: %d, ", valueWhole);
	//if(str[i-1]=='-') printf("its negative, ");
	
	unsigned char wSize = 0;                    //size of the whole part of value
	while(valueWhole / pow(10,wSize) > 1){
		wSize++;
	}
	
	printf("whole size: %hhu, ", wSize);
	
	wSize = wSize - 1;
	while(1){ 
		mask = valueWhole/(pow(10,wSize)); 
		//printf("mask: %d, ", mask);
		str[i++] = (mask % 10 ) + '0';          //'0' == 48 https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html 
		//printf(" ay:%c ", str[i-1]);
		if(wSize==0) break;
	    wSize--;             
	}
	
	
	str[i++] = '.';
	
	

	int valueDecimal = (value - valueWhole) * pow(10,PRECISION);
	printf("fractional: %d, ", valueDecimal);
	
	unsigned char fSize = 0;                    //size of the whole part of value
	while(valueDecimal / pow(10,fSize) > 1){
		fSize++;
	}
	
	printf("fractional size: %hhu, ", fSize);
	
	wSize = wSize - 1;
	while(1){ 
		mask = valueDecimal/(pow(10,fSize)); 
		//printf("mask: %d, ", mask);
		str[i++] = (mask % 10 ) + '0';         
		//printf(" ay:%c ", str[i-1]);
		if(fSize==0) break;
	    fSize--;             
	}
	
	unsigned char x = i-1; //cuz of x++
	while(str[x]=='0' && str[x-1]!='.'){      //delete unnecessary zeros
		str[x--] == '\0';
	}
	i = x+1; //cuz of x--
	
	str[i] = '\0';
	return i;                                 //it counts with the dot
}

void print_this_float(float value, unsigned char i){
	printf("%hhu -> ", i);
	//			+1 cuz of \n and another +1 for a possible minus ('-') signal
	char string[FLOAT_SIZE+1+1];
	/* printf("float size: %ld", FLOAT_SIZE);
	for(unsigned i = 0; i < FLOAT_SIZE+1; i++){
		string[i]='0';
	} */
	string[FLOAT_SIZE+1]='\0';
	
	int size = print_float(string, value);
	printf("   RESULT: String size: %d, string: %s \n", size, string);
}

int main(){
	print_this_float(22.0F,1);
	print_this_float(22.4F,2);
	print_this_float(223.03F,3);
	print_this_float(223.0301F,31);
	print_this_float(223.002F,4);
	print_this_float(223344.0566F, 5); 
	print_this_float(223344.062500F, 6);
	print_this_float(-223.002F, 7);
	print_this_float(-223.0023F, 8);
	print_this_float(-223.00230F, 9);
	print_this_float(-223.00231F, 10);
	print_this_float(-223.0031F, 11);
	print_this_float(-223.099F, 12);
	print_this_float(-223.09990F, 13);
	print_this_float(-223.099999F, 14); 
	print_this_float(-223.099994F, 141); 
	print_this_float(-223.09909F, 15); 
	print_this_float(-223.099090F, 16); 
	return 0;
}