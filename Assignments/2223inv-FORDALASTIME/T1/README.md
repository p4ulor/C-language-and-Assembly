# 44873 Paulo Rosa
## To compile everything with makefile:
```
$ make
```

## Ex 1

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

Setup:
```c
char string0_A[] = "AAAAAaaa"; //original
char string1_A[] = "aaa"; //occurence to replace
char string2_A[] = "AAA"; //replacement
string_find_substitute(string0_A, string1_A, string2_A);
printf("A -> %s\n", string0_A); //result -> AAAAAAAA
...
"AAAAAaaa";
"AAAAA";
"aaaaa";

"AAAAAaaa";
"AAAAA";
"aaa";

"AAAAAaaa";
"aaa";
"a";

"1234";
"12";
"0123";	

"12";
"2";
"123";
```

Output:
```
A -> AAAAAAAA
B -> aaaaaaaa
C -> aaaaaa
D -> AAAAAa
E-> 012334
F-> 1123
*** stack smashing detected ***: terminated
Aborted (core dumped)

```
## I could not find a way to avoid stack smashing...
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
- https://azrael.digipen.edu/~mmead/www/Courses/CS180/getopt.html
- https://en.wikipedia.org/wiki/Getopt
- https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
- https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/
- https://man7.org/linux/man-pages/man3/getopt.3.html

Setup:
```c
```
Output:
```

```