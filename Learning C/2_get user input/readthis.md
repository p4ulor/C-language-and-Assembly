In this chapter, I will provide blue prints for getting user input. 
"fgets" function is short for file-get-string. And the f in "scanf" is likely to mean file too.

## gets() [NO LONGER CAN BE USED IN RECENT C VERSIONS]
### char * gets ( char * str ) 

Reads characters from the standard input (stdin) and stores them as a C string into str until a newline character
or the End Of File(EOF) reached.

It is not safe to use because it does not check the array bound (compiler may return buffer overflow error) if the char array(buffer) is too small for the input given
It is used to read string from user until newline character not encountered.

"The gets() function was left in the C89 and C99 standards for backward compatibility (but officially deprecated in late revisions of C99). It was removed from the C11 standard and instead a range checking alternative gets_s was introduced. For C++ gets() was deprecated in C++11 and removed from C++14. So you are trying to use a function that was removed from the C standard almost a decade ago."

"gets remained an official part of the language up to the 1999 ISO C standard, but it was officially deprecated by the 2011 standard and removed in the 2014 standard. Most C implementations still support it, but at least gcc issues a warning for any code that uses it."

"The C11 standard ISO/IEC 9899:2011 eliminated gets() as a standard function, which is A Good Thing (it was formally marked as ‘obsolescent’ and ‘deprecated’ in ISO/IEC 9899:1999/Cor.3:2007 — Technical Corrigendum 3 for C99, and then removed in C11). But it will remain in libraries for many years (meaning ‘decades’) for reasons of backward compatibility."

___
## fgets() 
### char *fgets(char *strResult, int numberOfCharsToRead, FILE *streamSource)

Reads chars from a source of data. Can read from stdin, files and other sources. Fgets reads a line from the file and copies this to the output buffer (strResult)

Read more: Difference Between scanf and fgets | Difference Between http://www.differencebetween.net/technology/difference-between-scanf-and-fgets/#ixzz75tExLHNL
It stops when: (n-1) characters are read, or newline character is read or the end-of-file is reached. fgets only reads a line of text at a given time from a file

NOTE: fgets() stores the ‘\n’ character if it is read, so removing that has to be done explicitly by the programmer. It is hence, generally advised that your str can store at least (MAX_LIMIT + 1) characters if your intention is to keep the newline character

##### Use of fgets is discouraged in modern day programming, as it has been left in the C89 and C99 standards that allow backward compatibility. Even so, use of fgets should be very well addressed to ensure that the overall results are codes that can be run. The programmer using fgets must therefore be aware of the maximum upper limit of the number of characters needed to allow for sufficient buffer. This is a difficult challenge with no prior knowledge of the data. It is from this design that a gate that allows for exploitation of computer security is provided in the event of a buffer overflow

___
## scanf()
### int scanf(const char *format, ...)
... -> are a list of variables. Example: var1, var2, number1, stringName);

*format* is a string which will contain the format the output will be processed when received, and what comes after are the names of the variables in which the values inputed will be stored in.

It's used to read the formatted input from stdin by default its the keyboard until it encounters a WHITESPACE, newline(after all variables are inserted) or End Of File(EOF).

Scanf refers to Scan formats. Scanf focuses on the input of the valid tokens and it parses them depending on the format specified. The scanf function returns all the available items that match. It is important to note that it is not all the time that you will get an equal number of the items as requested. The items can be less than those requested. The scanf function then returns the total number of successfully matched items. it also allows for handle conversions into numeric types, coming from string types. scanf is used for the dissection of the data. scanf does not perform bounds checking




Actually we can use scanf() to read entire string. For example we can use %[^\n]s inside scanf() to read entire string. Like:
```c
char* string[20];
int scanf("%[^\n]s", string);

int n;
int m;
scanf("%d", &n);

scanf("%d%d", &n, &n);
```
___
## Scanf vs fgets resume
- While fgets provides a better choice that can allow for evaluation to be done. Scanf can then be used to evaluate the bounds after they have been checked by fgets
- Scanf refers to Scan formats.
- Scanf focuses on the input of valid tokens.
- Scanf parses inputs depending on the format specified.
- Scanf only reads from standard inputs.
- Fgets only reads a line of text at a given time from a file.
- Scanf does not perform bounds checking.
___
## getchar()
### int getchar(void)

Reads one char

Useful to make custom (and thus likely efficient) console-input methods. Also useful to use after the end of an operation and you don't want the program to continue. So you put a getchar(), and the console waits until you press any letter.


## Resources 
- https://www.geeksforgeeks.org/gets-is-risky-to-use/?ref=rp
- https://www.sololearn.com/Discuss/2269383/warning-the-gets-function-is-dangerous-and-should-not-be-used
- https://www.knowprogram.com/c-programming/why-gets-function-is-dangerous-and-should-not-be-used/
- https://stackoverflow.com/questions/1694036/why-is-the-gets-function-so-dangerous-that-it-should-not-be-used
- https://www.geeksforgeeks.org/fgets-gets-c-language/
- https://www.geeksforgeeks.org/difference-between-scanf-and-gets-in-c/?ref=rp
- https://www.geeksforgeeks.org/why-to-use-fgets-over-scanf-in-c/?ref=rp
- https://www.geeksforgeeks.org/problem-with-scanf-when-there-is-fgetsgetsscanf-after-it/?ref=rp
- https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm
- http://www.differencebetween.net/technology/difference-between-scanf-and-fgets/#:~:text=Scanf%2C%20on%20the%20other%20hand,the%20dissection%20of%20the%20data
- https://stackoverflow.com/questions/5406935/reading-a-string-with-scanf
- https://stackoverflow.com/questions/3919009/how-to-read-from-stdin-with-fgets