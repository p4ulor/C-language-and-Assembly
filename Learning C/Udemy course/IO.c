#include <stdio.h>

//standart input is the file the file that is read with getchar() and scanf()
//standart out put is with putchar(),puts(), and printf()

/* streams
standart input - normal input device, like keyboard
standart output - your screen
standard erro - screen(this is for the purpose to provide logically distinct place to send error messages

a stream is an abstract representation of any external source or destination for data
the keyboard, command line on your display, files and disk are exemples of things u can work with as streams

the c library providades functions for reading and writing to or from data streams
u use the same input/output functions for reading and writing any external device that is mapped to a stream

*/

/*a program referencea file through a file pointer (or stream pointer, since it works on more than a file)
u associate a file pointer with a file programmatically when the program is run
pointers can be reused to point to different files on different occasions

a file pointer points to a struct of type FILE that represents a stream
 contains information about the file
   wheter u want to read or write or update the file
   the address of the buffer in memory to be used for data
   a pointer to the current position in the file for the next operation
the above is all set via input/output file operations

if u want to use several files simultaneously in a program, u need a separate file pointer for each file
  there is a limit to the number of files u can have open at one time
     defined as FOPEN_MAX in stdio.h
	 
u associate a specific file name with an internal file pointer variable through a process referred to as opening a file 
   via the fopen() function
      returns the file pointer for a specific external file


*/

/*
the fopen() function is defined in stdio.h

FILE *fopen(const char* restrict name, const char* restrict mode);

the first argument to the function is a pointer to a string that is the name of the external file u want to process
  u can specify the name explicitly or use a char pointer that contains the address of the character string that define the file name 
  u can obtain the file name through the command line, as input from the user or defined as a constant in ur program

the second argument to the fopen() function is a character string that represents the file mode
  sepcifies what u want to do with the file
  a file mode specification is a character string between double quotes

assuming the call to fopen() is successful, the function returns a pointer of type FILE* that u can use to reference the file in further input/output operations using other functions in the library

if the file cannot be opened for some reason, fopen() returns NULL
*/

//WRITE MODE:
FILE* pdfile = NULL;
char* filename = "file.txt";
pfile = fopen(filename,"w"); 
if(pfile!=null) printf("failed to open %s, \n", filename);

//if a file with name file.txt doesnt exist, a new file with this name will be created
//if u do not provide path, the file is assubed to be in current dir
//on opening for writing, the position to begin writing will be 0, and overwrite the file

//with append mode u cannot update the existing contents in the file
//if youre going to read a file it already exists

//renaming a file:
rename()
int rename(const char* oldname, const char *newname);

//it cant be open when renaiming. returns 0 if successful

if(rename("myfile.txt","file.txt"))
	printf("failed");
else printf("done");

//closing a file
//when u have finished with a file, u need to tell the OS, so that it can free up the file, with fclose()
/*
it acceps a file pointer as an argument
returns EOF(int) if an error occurs
EOF is a special char called the end of file char
defined in stdio.h as a negative integer that i usually equivalent to the value -1
0 if successful

fclose(pfile); //close the file associated with pfile
pfile = NULL;

the result of calling fclose() is that the connection between the pointer, pfile, and physical file is broken
pfile can no longer be used to access the file

if the file was being written, the current contents of the output buffer are written to the file to ensure that data is not lost(during a thread)

it is good programming practice to close a file as soon as u have finished with it
protects against output data loss


DELETING A FILE
remove("file.txt");
*/

/*Reading characters from a txt file
the fgetc() function reads a char from a text file that has been opened for reading
takes a file pointer as its only argument and returns the character read as type int
*/

int mchar = fgetc(pfile); //reads a char into mchar with pfile a file pointer

//the mchar is type int because EOF will be returned if the end of the file has been reached

/*the function getc(), which is equivalent to fgetc(), is also avaiable
  requires an argument of type FILE* and returns the character read as type int
  virtually identical to fgetc()
  only difference between them is that getc() may be implemented as a macro, whereas fgetc() is a function

u can read the contents of a file again when necessary
  the rewind() function positions the file that is specified by the file pointer argument at the beggining
  of the file, so u can read from beggining

rewind(pfile)
 */
 
//example:

#include <stdio.h>

int main(){
FILE* tp;
int c;

fp = fopen("file.txt", "r");

if(fp == NULL){
perror("Error in opening file");
return(-1);
}

//read a single char
while((c = fgetc(fp)) != EOF) printf("%c", c);

fclose(fp);
fp = NULL;
returns(0);

} //return from main

/*
Reading a string from a text file
u can use the fgets() function to read from any file or stream
 */

char* fgets(char* str, int nchars, FILE* stream)

/*
the function reads a string into the memory area pointed to by str, from the file specified by stream
characters are read until either a '\n' is read or nchars-1 characters have been read from the stream, whichever occurs first

if a newline character is read, its retained in the string
   a '\0' character will be appended to the end of the string

if there is no error, fgets() returns the pointer, str
if there is an error, NULL is returned
reading EOF causes NULL to be returned
*/

//example:

#include <stdio.h>
int main2(){
FILE* fp;
char str[60];

//opening file for reading
fp = fopen("file.txt", "r");

if(fp == NULL){
perror("Error opening file");
return(-1);
}

if(fgets(str,60,fp)!=NULL){
//writing content to stdout
printf("%s", str);
}

fclose(fp);
fp = NULL;
return(0);
}

//reading formatted input from a file
//u can get formatted input from a file by using the standard fscanf() function

int fscanf(FILE* stream, const char* format,...)

/*the first argument to this function is the pointer to a FILE object that identifies the stream

the second argument to this function is the format
 a C string that contains one or more of the following items
 a white-space character
 format specifiers
 usage is similar to scanf, but, from a file 

the function returns the number of input items successfully matched and assigned
*/
//EXAMPLE:

#include <stdio.h>
#include <stdlib.h>

int main3(){
char str1[10], str2[10], str3[10];
int year;
FILE* fp;

fp = fopen("file.txt", "w+"); // reading and writing 
if(fp!=NULL) fputs("Hello how are u", fp);

rewind(fp);

fscanf(fp, "%s %s %s %d", str1,str2,str3, &year);

printf("Read string1 |%s|\n", str1);
printf("Read string2 |%s|\n", str2);
printf("Read string3 |%s|\n", str3);
printf("Read integer |%s|\n", year);

fclose(fp);

return(0);
}

int main(int argc, char *argv[]) {
	
	return 0;
}
