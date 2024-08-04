/*writing characters to a txt file
the simplest write operation is provided by the function fputc()
  writes a single character to a text file
*/

int fputc(int ch, FILE* pfile);

/*
the function writes the character specified by the first argument to the file identified by the second argument(file pointer)
  returns the character that was written if successful
  returns EOF is failure

in practice, characters are not usually written to a physical file one by one
   cuz its extremely inefficient

the putc() function is equivalent to fputc()
   requires the same arguments and the return type is the same
   difference between them is that putc() may be implemented in the standard library as a macro, whereas fputc() is a function
 */

//example:
#include <stdio.h>

int main(){
FILE* fp;
int ch;

fp = fopen("file.txt", "w+");
for(ch = 33; ch <= 100; ch++){ //ASCI values
 fputc(ch,fp);
}

fclose(fp);
return(0);
}

//writing a string to a txt file
//u can use the fputs() function to write to any file or stream

int fputs(const char* str, FILE* pfile);

/*
the first argument is a pointer to the character string that is to be written to the file

the second argument is the file pointer

this function will write characters from a string until it reaches a '\0' char
   does not write the null terminator character to the file
       can complicate reading back variable-length strings from a file that have been written by fputs()
       expecting to write a line of text that has a newline char at the end

 */

//example

#include <stdio.h>

int main2(){
FILE* filePointer;

filePointer = fopen("file.txt", "w+");
fputs("This is jason"", filePointer);
fputs("I am", filePointer);

fclose(filePointer);
returns(0);

}

//writing formatted output to a file
//the standard function for formatted output to a stream is fprintf()

int fprintf(FILE* stream, const char* format, ...)
/*
the first argument to this function is the pointer to a FILE object that identifies the stream

the second argument to this function is the format
 a C string that contains one or more of the following items
     a whitespace char
     a non white space char
     format specifiers
     usage is similar to printf, but, to a file

if successful, the total number of characters written is returned, otherwise, a negative number is returned
 */
 //example:

#include <stdio.h>
#include <stdlib.h>

int main3(){
FILE* fp = NULL;
fp = fopen("file.txt", "w+");
if(!fp) fprintf(fp, "%s %s %s %d", "Hello", "my", "Number", "is", 555);
fclose(fp);
return(0);
}

/*file positioning
for many applications, u need to be able to access data in a file other than sequential order

there are 2 aspects to file positioning
   finding out where u are in a file
   moving to a given point in a file

u can acess a file at a random position regardless of whether u opened the file



//finding out where u are
u have 2 functions to tell u where u are in a file
ftell()
fgetpos()

long ftell(FILE* pfile);

this function accepts a file pointer as an argument and returns a long integer value that specifies the current position in the file

long fpos = ftell(pfile);

the fpos variable now holds the current position in the file and u can use this to 
return to this position at any subsequent time
  value is the offset in bytes from the beginning of the file
*/

//example
FILE* fp;
int len;

fp = fopen("file.txt", "r");
if(fp == NULL){
 perror("Error opening file");
return(-1);
}

fseek(fp,0,SEEK_END); //go until the end of the file

len = ftell(fp); //fp gonna be at the end of the file
fclose(fp);
printf("Total size of file.txt = %d bytes \n", len);

//fgetpos(), the second function providing information on the current file position is a little more complicated

int fgetpos(FILE* pfile, fpos_t* position);

/* 
the first aprameter is a file pointer

the second parameter is a pointer to a type that is defined in stdio.h

  fpos_t -> a type that is able to record every position within a file

the fgetpos() function is designed to be used with the positioning function fsetpos()

the fgetpos() function stores the current position and file state information for the file in position and returns 0 if the operation is successful 
  returns a nonzero integer value for failure

fpos_t here; //type variable to store position
fgetpos(pfile, &here);

the above records the current file position in the variable here
u must declare a variable of type fpos_t
  u cannot declare a pointer of type fpos_t because there will not be any memory allocated to store the position date
*/

//example

FILE* fp;
fpos_t position;

fp=fopen("file.txt", "w+");
fgetpos(fp, &position);
fputs("Hello, world!", fp);
fclose(fp);

//setting a position in a file
//as a complement to ftell(), u have to fseek() function

int fseek(FILE* pfile, long offset, int origin);
/*
the first parameter is a pointer to the file u are repositioning
the second and third, define where u want to go in the file
reference point can be one of 3 values that are specified by the predefined names:
SEEK_SET -> defines the beginning of the file
SEEK_CUR -> defines the current position in the file
SEEK_END -> defined the end of the file

for a text mode file, the second argument must be a value returned by ftell()

the 3rd argument for text mode files must be SEEK_SET
  for txt files, all operations with fseek() are performed with reference to the beginning of the file
  for binary files, the offset argument is simply a relative byte count
     can therefore supply positive or negative values for the offset when the reference point is specified as SEEK_CUR
 */

//fseek() example
#include <stdio.h>
int main4(){
FILE* fp;

fp = fopen("file.txt", "w+");
fputs("This is jason", fp);

fseek(fp, 7, SEEK_SET); //move 7 bytes from the beggining, after 7 bytes we can write data to it
fputs("Hellow how are you", fp);
fclose(fp);
return(0);
}

//fsetpos()
//u have the fsetpos() function to go with fgetpos()
int fsetpos(FILE* pfile, const fpos_t* position);
/*
the first parameter is a pointer to the open file
the second is a pointer of the fpos_t type
  the position that is stored at the address was obtained by calling fgetpos()
 */

fsetpos(pfile, &here);

/*
the variable 'here' was previously set by a call to fgetpos()

the fsetpos() returns a nonzero value on error or 0 when it successful

this function is designed to work with a value that is returned by fgetpos()
 u can only use it to get a place in a file that u have been before
 fseek() allows u to go to any position just by specifying the appropriate offset

 */
//fgetpos() example(with all these functions are very useful to position wherever u want in a file
#include <stdio.h>

int main5(){
FILE* fp;
fpos_t position;

fp = fopen("file.txt", "w+");
fgetpos(fp, &position);
fputs("Hello, world!", fp);

fsetpos(fp, &position);
fputs("this is going to override previous content",fp);
fclose(fp);
returns(0);
}

int main(int argc, char *argv[]) {
	return 0;
}
