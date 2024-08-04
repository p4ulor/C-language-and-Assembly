#include <stdio.h> //in order to use printf()
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
//https://www.rapidtables.com/convert/number/base-converter.html


unsigned char getLenghtOfCharPointer(char* str){ //or use strlen() from <string.h>
	unsigned char size = 0;
	while(*str++ != '\0')
		size++;
	return size;
}

void reverseString(char* str, unsigned char l) { //https://www.geeksforgeeks.org/program-to-reverse-a-string-using-pointers/
    int i;
    char *begin_ptr, *end_ptr, ch;
  
    // Get the length of the string
    //l = strlen(str);
  
    // Set the begin_ptr and end_ptr
    // initially to start of string
    begin_ptr = str;
    end_ptr = str;
  
    // Move the end_ptr to the last character
    for (i = 0; i < l - 1; i++)
        end_ptr++;
  
    // Swap the char from start and end
    // index using begin_ptr and end_ptr
    for (i = 0; i < l / 2; i++) {
  
        // swap character
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;
  
        // update pointers positions
        begin_ptr++;
        end_ptr--;
    }
}


int print_integer(char* str, int value, int base){ //https://www.sanfoundry.com/c-program-convert-decimal-hex/
	if(base > 36 || base < 2) return -1;

	int quotient = value;
	int remainder;
	int j = 0;
    while (quotient != 0) {
        remainder = quotient % base;
        if (remainder < 10) str[j++] = 48 + remainder; //48 is '0' in ASCII https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
        else str[j++] = 97 + remainder - 10; //97 is 'a', but since we entered this else, then the remainer is 10 or greater, so we need to offset this value
        quotient = quotient / base;
    }
	str[j] = '\0';
	int size = getLenghtOfCharPointer(str);
	reverseString(str, size);
	
	return j;
}

unsigned char getSizeOfNumberInGivenBase(int n, int base){ 
	unsigned char i = 0;
    while (n > 0) {
        n = n / base;
        i++;
    }
	return i;
}

void print_integer_console(int value, int base){
	//printf("Size of the string: %hhu\n", getSizeOfNumberInGivenBase(value));
	char string[getSizeOfNumberInGivenBase(value, base)+1]; //given a number, calculate the appropriate string lenght to store that number in a certain base
//										               +1 cuz of \0											
	for(int i = 0; ; i++){
		if(i == ARRAY_SIZE(string)-1) {
			string[i] = '\0';
			//printf("end: %c\n", string[i]);
			break;
		} else string[i] = '-';
		//printf("set string: %c\n", string[i]);
	}

	//printf("string lenght is %ld", ARRAY_SIZE(string));
	
	printf("The number %d in base %d is represented with %d digits\n", value, base, print_integer(string, value, base));
	printf("Like this: %s\n", string);
}

int main(){ 
	//tests
	print_integer_console(65423231, 16);
	printf("\n");
	print_integer_console(65423231, 36);
	printf("\n");
	print_integer_console(65423231, 10);
	printf("\n");
	print_integer_console(65423231, 2);
	return 0;
}