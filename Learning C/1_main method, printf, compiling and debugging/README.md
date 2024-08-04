When compiling, if you ommit the -o from the command, the output file will be a file called 'a' by default(but because I dont want to have 'a' files all over the place, I use '-o' to change the name like I have bellow)

You can also compile with a diferent format/order. Like:
- gcc -o wassup.out WassupWorld.c

or(the order may not be relevant):
- gcc WassupWorld.c -o wassup.out

If you ommmit .out, the output file will have no file extensison, but it's still runnable. One advantage is that you can more easily add it to .gitignore. I use github desktop, and if you right click a file without extension, you will not have the option "add all .fileextension to gitignore". But if the file has a file extension, you can, because that can be sorted out.

To execute, open the terminal already set with the same location/directory as the folder as the .c file. Like this: inside the folder, right click and select "Open terminal here" and then run the command:

- ./wassup.out

The dot is meant to represent 'this' directory

## Extra compilation arguments

1. If you add `-g` to the command(preferably at the end), it will allow you to run in debug mode afterwards. And you run in debug mode by running the output file like:
- insight wassup.out

2. if you use <math.h>, you will need to add `-lm` in order to compile. Or the compiler will not recognize functions like pow(x,y)

## How to use .c programs together(linking) and use methods from other .c files

- gcc ex1.c ex2.c -o ex2.out -lm

There should be only 1 .c file with the main() function. And just like the main() function, there shouldn't be functions in the main .c file(the one that contains the main() function) with the same names as the in the other .c files. And the names of the functions used from those .c files should be declared on top of the main .c file after the #include 's

Per example:
- `int print_integer(char* str, int value, int base);`; 

[Good tutorial here](https://randerson112358.medium.com/link-c-programs-7282712fca1f)
___
The function called at program startup is named main. 
The main function can be defined with no parameters or with two parameters (for passing command-line arguments to a program when it begins executing). 
These two parameters are more commonly referred to as `argc` and `argv`, although any names can be used. 
A main function can have the following syntax:

- int main(void) { . . . }

or
- int main() { . . . }
or 

- int main(int argc, char *argv[ ]) { . . . }

The parameters:

- argc: The number of arguments in the command line that invoked the program. The value of argc is nonnegative.

- argv: Pointer to an array of character strings that contain the arguments, one per string. The value of argv[argc] is a null pointer.


## References
https://www.cs.auckland.ac.nz/references/unix/digital/AQTLTBTE/DOCU_056.HTM

https://stackoverflow.com/questions/204476/what-should-main-return-in-c-and-c