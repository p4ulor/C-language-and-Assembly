#include <stdio.h> //for printf and size_t
#include <string.h>

char *strrev(char *str){ //https://stackoverflow.com/a/29408476/9375488
    if (!str || ! *str) return str;
    int i = strlen(str) - 1, j = 0;
    char ch;
    while (i > j){
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

size_t int_to_string(int value, int base, char buffer[], size_t buffer_size){
    if(base > 36 || base < 2) return -1; //36 because it's the number of letters in alphabet (26) + number of digits (10)

	int quotient = value;
	int remainder;
	int j = 0; //current digit index
    while (quotient != 0) {
        if(buffer_size==j) {
            printf("Warning the limit of the buffer(%ld) was reached!\n", buffer_size);
            break;
        }
        remainder = quotient % base;
        
        //Part of the number will be represented as a digit
        if (remainder < 10) buffer[j++] = 48 + remainder; //48 is '0' in ASCII https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

        //A portion of the number will be represented as letters
        else buffer[j++] = 97 + remainder - 10; //97 is 'a', but since we entered this 'else', then the remainer is 10 or greater, so we need to offset this value back to the baseline which is 'a', which we do by going back 10 positions in the ascii table
        quotient = quotient / base;
    }
	buffer[j] = '\0';
	strrev(buffer);
	return j; 
}

unsigned int getNumOfDigitsToRepresentNumberInGivenBase(int n, int base){ 
	unsigned int i = 0;
    while (n > 0) {
        n = n / base;
        i++;
    }
	return i;
}

void print_integer_console(int value, int base){
	//printf("Size of the string: %hhu\n", getSizeOfNumberInGivenBase(value));
    unsigned int size = getNumOfDigitsToRepresentNumberInGivenBase(value, base)+1; //+1 cuz of \0	
	char string[size];

	for(int i = 0; ; i++){
		if(i == strlen(string)) {
			string[i] = '\0';
			//printf("end: %c\n", string[i]);
			break;
		} else string[i] = '-';
		//printf("set string: %c\n", string[i]);
	}

	//printf("string lenght is %ld", ARRAY_SIZE(string));
	
	printf("The number %d in base %d is represented with %ld digits\n", value, base, int_to_string(value, base, string, size));
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
    printf("\n");

    //error example when the buffer is too small
    int value = 65423231;
    int base = 16;
    int stringSize = 5;
    char string[stringSize];
    printf("The number %d in base %d is represented with %ld digits\n", value, base, int_to_string(value, base, string, stringSize));
	printf("Like this: %s\n", string);

	return 0;
}
