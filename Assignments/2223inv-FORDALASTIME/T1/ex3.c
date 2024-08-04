#include <stdio.h> //in order to use printf()
#include <stdlib.h> //for malloc()
#include <math.h> //for pow()
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define FLOAT_SIZE sizeof(float)*8
#define PRECISION 6
#include <stdarg.h> //cuz of variable ... arguments
#include <string.h> //for memset()

//RUN WITH -lm !!! -> gcc ex3.c -o ex3.out -lm

int print_integer(char* str, int value, int base);

unsigned char getLenghtOfCharPointer(char* str){ //or use strlen from <string.h>
	unsigned char size = 0;
	while(*str++ != '\0')
		size++;
	return size;
}

void reverseString(char* str, unsigned char l) { //https://www.geeksforgeeks.org/program-to-reverse-a-string-using-pointers/
    int i;
    char *begin_ptr, *end_ptr, ch;
    begin_ptr = str;
    end_ptr = str;
    for (i = 0; i < l - 1; i++)
        end_ptr++;

    for (i = 0; i < l / 2; i++) {
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;
        begin_ptr++;
        end_ptr--;
    }
}

int print_integer(char* str, int value, int base){
	if(base > 36 || base < 2) return -1;
	
	int quotient = value;
	int remainder;
	int j = 0;
    while (quotient != 0) {
        remainder = quotient % base;
        if (remainder < 10)
            str[j++] = 48 + remainder; 
        else
            str[j++] = 97 + remainder - 10;
        quotient = quotient / base;
    }
	str[j] = '\0';
	int size = getLenghtOfCharPointer(str);
	reverseString(str, size);
	
	return j;
}

int print_float(char* str, float value){ //copy paste from ex2.c but printf's removed
	int i = 0;
	int mask;
	if(value<0.0) {
		str[i++]='-';
		value = 0 - (value);                   
	}
	int valueWhole=value;	                    
	unsigned char wSize = 0;                 
	while(valueWhole / pow(10,wSize) > 1){
		wSize++;
	}
	wSize = wSize - 1;
	while(1){ 
		mask = valueWhole/(pow(10,wSize)); 
	
		str[i++] = (mask % 10 ) + '0';          

		if(wSize==0) break;
	    wSize--;             
	}
	str[i++] = '.';
	int valueDecimal = (value - valueWhole) * pow(10,PRECISION);
	unsigned char fSize = 0;                    //size of the whole part of value
	while(valueDecimal / pow(10,fSize) > 1){
		fSize++;
	}
	wSize = wSize - 1;
	while(1){ 
		mask = valueDecimal/(pow(10,fSize)); 
		str[i++] = (mask % 10 ) + '0';         
		if(fSize==0) break;
	    fSize--;             
	}
	unsigned char x = i-1;
	while(str[x]=='0' && str[x-1]!='.'){     
		str[x--] == '\0';
	}
	i = x+1; 
	str[i] = '\0';
	return i;                                 
}

int lenHelper(unsigned x) { 
    // this is either a fun exercise in optimization 
    // or it's extremely premature optimization.
    if(x >= 100000) {
        if(x >= 10000000) {
            if(x >= 1000000000) return 10;
            if(x >= 100000000) return 9;
            return 8;
        }
        if(x >= 1000000) return 7;
        return 6;
    } else {
        if(x >= 1000) {
            if(x >= 10000) return 5;
            return 4;
        } else {
            if(x >= 100) return 3;
            if(x >= 10) return 2;
            return 1;
        }
    }
}

//gcc ex3.c -o ex3.out -lm   								add -lm because we use pow() from math.h
int mini_sprintf(char* str, const char *format, ...) { //pagina 156 do livro, pagina 170 do pdf
	va_list ap; // points to each unnamed arg in turn, ap = argument pointer 
	va_start(ap, format); // make ap point to 1st unnamed args
	
	int strLenght = 0;
	for (; *format!='\0'; format++) {
		if(*format != '%') {
			if(*str!='\0') {
				*str++=*format;
				strLenght++;
			}
			else break;
			continue;
		}
		//if (!format) break; //if no more arguments
		++format;
		switch (*format) {
			char valc;
			char* vals;
			int vald;
			float valf;
			
			case 'c':
				valc = va_arg(ap, int);
				if(*str!='\0') {
					*str++=valc;
					strLenght++;
				}
				else return strLenght;
			break;
			
			case 's':
				vals = va_arg(ap, char*);
				
				while(*vals!='\0'){
					if(*str!='\0') {
						*str++=*vals++;
						strLenght++;
					}
					else return strLenght;
				}
			break;
			
			case 'd':
				vald = va_arg(ap, int);
				int l = lenHelper(vald) - 1;
				while(1){
					if(*str!='\0') {
						*str++= ((int) (vald/(pow(10,l--)))  % 10 ) + '0'; 
						strLenght++;
						if(l==-1) break;
					}
					else return strLenght;
				}
			break;
			
			case 'x':
				vald = va_arg(ap, int);
				
				char* string = malloc(16*sizeof(char));
				char* p = string;
				print_integer(string,vald, 16);
				
				while(*string!='\0'){
					if(*str!='\0') {
						*str++=*string++;
						strLenght++;
					}
					else return strLenght;
				}
				free(p);
			break;
			
			case 'f':
				valf = va_arg(ap, double);
				
				char* string2 = malloc(FLOAT_SIZE+1+1);
				char* string2p = string2;
				print_float(string2, valf);
				
				while(*string2!='\0'){
					if(*str!='\0') {
						*str++=*string2++;
						strLenght++;
					}
					else return strLenght;
				}
				free(string2p);
			break;
			default: break;
		}
	}
	*str='\0';
	va_end(ap); //clean up when done	
	return strLenght;
}

int main(){
	char str[1000] = {0};
	memset(str, 1, 1000);
	int strLenght = mini_sprintf(str, "%c, %s, %d, %x, %f", 		'a', "bcd", 10, 11, 12.2);
	printf("String lenght: %d\n%s\n", strLenght, str);
	return 0;
}