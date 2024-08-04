# Resume
Generally, the main() method will have the tests and calls to the implemented methods for the exercise
## Ex 1
Create the function:
`int print_integer(char *str, int value, int base)`

Which converts the number `value` into the number that corresponders to it in the `base` provided. And the result in stored in the `*str` and the lenght of it is returned

### Methods:
Main methods:
- int main()
- void print_integer_console(int value, int base)
- int print_integer(char* str, int value, int base)

Auxiliary methods:
- void reverseString(char* str, unsigned char l)
- unsigned char getSizeOfNumberInGivenBase(int n, int base)
- unsigned char getLenghtOfCharPointer(char* str)

### Output example of the test:
Setup:
```c
print_integer_console(65423231, 16);
printf("\n");
...
```
Output:
```
The number 65423231 in base 16 is represented with 7 digits
Like this: 3e6477f

The number 65423231 in base 36 is represented with 6 digits
Like this: 12y8vz

The number 65423231 in base 10 is represented with 8 digits
Like this: 65423231

The number 65423231 in base 2 is represented with 26 digits
Like this: 11111001100100011101111111
```
___
## Ex 2
Create the function:
`int print_float(char *str, float value)`

Which converts `value` into string format (in decimal base) and stores it in `*str`. **Do not use sprintf(char\*
str, const char \*format) or any other means that already do this.**

## Methods:
Main methods:
- int main()
- void print_this_float(float value, unsigned char i)
- int print_float(char* str, float value)

Auxiliary methods:
- unsigned char getLenghtOfCharPointer(char* str)
## Output example of the debug-test(I edited the spaces here to look better):
Setup:
```c
print_this_float(22.0F,1);
print_this_float(22.4F,2);
...
```
Output:
```
1->  whole: 22,     whole size: 2, fractional: 0,      frac size: 0, RESULT: String size: 4,  string:  22.0 
2->  whole: 22,     whole size: 2, fractional: 399999, frac size: 6, RESULT: String size: 10, string:  22.0399999 
3->  whole: 223,    whole size: 3, fractional: 29998,  frac size: 5, RESULT: String size: 10, string:  223.029998 
4->  whole: 223,    whole size: 3, fractional: 30105,  frac size: 5, RESULT: String size: 10, string:  223.030105 
5->  whole: 223,    whole size: 3, fractional: 1998,   frac size: 4, RESULT: String size: 9,  string:  223.01998 
6->  whole: 223344, whole size: 6, fractional: 62500,  frac size: 5, RESULT: String size: 11, string:  223344.0625 
7->  whole: 223344, whole size: 6, fractional: 62500,  frac size: 5, RESULT: String size: 11, string:  223344.0625 
8->  whole: 223,    whole size: 3, fractional: 1998,   frac size: 4, RESULT: String size: 10, string: -223.01998 
9->  whole: 223,    whole size: 3, fractional: 2304,   frac size: 4, RESULT: String size: 10, string: -223.02304 
10-> whole: 223,    whole size: 3, fractional: 2304,   frac size: 4, RESULT: String size: 10, string: -223.02304 
11-> whole: 223,    whole size: 3, fractional: 2304,   frac size: 4, RESULT: String size: 10, string: -223.02304 
12-> whole: 223,    whole size: 3, fractional: 3097,   frac size: 4, RESULT: String size: 10, string: -223.03097 
13-> whole: 223,    whole size: 3, fractional: 98999,  frac size: 5, RESULT: String size: 11, string: -223.098999 
14-> whole: 223,    whole size: 3, fractional: 99899,  frac size: 5, RESULT: String size: 11, string: -223.099899 
15-> whole: 223,    whole size: 3, fractional: 100006, frac size: 6, RESULT: String size: 12, string: -223.0100006 
16-> whole: 223,    whole size: 3, fractional: 99990,  frac size: 5, RESULT: String size: 10, string: -223.09999 
17-> whole: 223,    whole size: 3, fractional: 99090,  frac size: 5, RESULT: String size: 10, string: -223.09909 
18-> whole: 223,    whole size: 3, fractional: 99090,  frac size: 5, RESULT: String size: 10, string: -223.09909
```
___
## Ex 3
Create the function:
`int mini_sprintf(char *str, const char *format, ...)`

Which functions the same way as [sprintf](https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm) but limited to the specifiers %c, %s, %d, %x and %f.
**Do not use sprintf from the libraries ofc**

Use va_arg, va_list, va_end and va_start(from <stdarg.h>) in order to extract the data from the variable argument '...'
## Methods:
Main methods:
- int main()
- int mini_sprintf(char* str, const char *format, ...)

Auxiliary methods:
- int lenHelper(unsigned x)
- int print_float(char* str, float value)
- int print_integer(char* str, int value, int base)
- void reverseString(char* str, unsigned char l)
- unsigned char getLenghtOfCharPointer(char* str)
## Output example of the test:                  
Setup:
```c
char str[1000] = {0};
memset(str, 1, 1000);
int strLenght = mini_sprintf(str, "%c, %s, %d, %x, %f",   'a', "bcd", 10, 11, 12.2);
printf("String lenght: %d\n%s\n", strLenght, str);
``` 
Output:
```
String lenght: 25
a, bcd, 10, b, 12.0199999
```
___
## Ex 4
Create the function:
`size_t extract_data(Person *people[], size_t people_size,char *text)`

Given:
```c
struct date {
    int day, month, year;
};

typedef struct person {
    char name[100];
    truct date date;
    int nif;
} Person;
```

Which 
## Methods:
Main methods:
- int main()
- size_t extract_data(Person *people[], size_t people_size, char *text)

## Output example of the test:
Setup:
```c
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
```
Output:
```
Number of persons: 2
Person Nr: 1
Name: Manuel
Date: 15 / 3 / 2002
NIF: 125645045

Person Nr: 2
Name: Joaquim
Date: 25 / 4 / 1974
NIF: 122003088
```
___
## Ex 5
Create a program that searches a word in a txt file. The lines that contain the chosen word, are fully written in an output txt file, along with it's line number in the order they are found in the input txt file.

The program works like a terminal, like this:

- $ find_in_file <options> <word>

The input <options> can contain any sequence of the following possible inputs(including being empty or not present):
- -o <file> -> provides the name of the output file. If not provided, the output will be to stdout(console)
- -i <file> -> provides the name of the input file. If not provided, the input will be the stdin(the rest of whatever is written after <word>
- -c -> If written, the word search will be uppercase and lowercase sensitive. If not, it will be insensitive
- -w -> If written, the search will only pickup exact word matches. If not, words contains the word will also be picked up.

Use [getopt](https://pubs.opengroup.org/onlinepubs/9699919799/) for the processing of the options. 

Resources:
- https://en.wikipedia.org/wiki/Getopt
- https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
- https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/
- https://man7.org/linux/man-pages/man3/getopt.3.html

## Methods:
Main methods:
- int main()

Auxiliary methods:
- unsigned int getLenghtOfCharPointer(char* str)

## Output example of the test:
Setup:
```c
```
Output:
```
```

# Logic break downs:
## Ex 1:
## Ex 2:
## Ex 3:

First of, we need to be aware that for us to perform the proper operations we want for %x and %f we need to use **print_integer** and **print_float** that we made in ex1 and ex2 respectively.

You could put in block comment the methods: getLenghtOfCharPointer, reverseString, print_integer in ex3.c and the main() in ex1.c and compile like this:
- gcc ex3.c ex1.c -o ex3.out -lm
Or even add ex2.c. But I decided to just copy and paste the method definitions.
## Ex 4:
## Ex 5: