/*
write a program to find the total number of lines in a txt file
use fgetc function to parse chars in a file until u get to the EOF 
  if EOF increment counter
display as output the total number of lines in the file
*/

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Test.txt"

int main(){
    FILE *fp = NULL;
    char ch;
    int linesCount = 0;

    fp = fopen(FILENAME, "r");

    if(fp == NULL){
        printf("File does not exist\n");
        return -1;
    }

    while((ch=fgetc(fp))!= EOF){
        if(ch=='\n')
            linesCount++;
    }

    fclose(fp);
    fp = NULL;

    printf("Total number of lines are: %d\n", ++linesCount);

    return 0;
}

/* 
write a program that converts all chars of a file to uppercare and write the results out to a temporary file, then rename the temporary file to the original filename and remove the temporary filename

use the fgetc and fputc functions

use the rename and remove functions
use the islower function
can convert a character to upper case by subtracting 32 from it
display the contents of the original file to standart output in uppercase
*/

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Test.txt"

int main2(){
    FILE *fp = NULL;
    FILE *fp1 = NULL;

    char ch = ' ';

    fp = fopen(FILENAME, "r");

    if (fp == NULL)
        return -1;

    // create a temp file
    fp1 = fopen("temp.txt", "w");

    if (fp1 == NULL)
        return -1;

    while ((ch = fgetc(fp)) != EOF) {
        if (islower(ch))
        {
            ch = ch-32; //converts to upper
        }

        fputc(ch, fp1);
    }

    fclose(fp); //we have to close, before renaiming
    fclose(fp1);

    remove(FILENAME);

    // rename temp file to Test.txt file
    rename("temp.txt", FILENAME);

    // remove the temp file
    remove("temp.txt");

    fp = fopen(FILENAME, "r");

    if (fp == NULL)
        return -1;

    while ((ch =fgetc(fp)) != EOF)
        printf("%c", ch);


    fclose(fp);
    fp = NULL;
    fp1 = NULL;

    return 0;
}

/*
write a program that will print the content of a file in reverse order
use the fseek function to seek to the end of the file
use the ftell function to get the position of the file pointer
display as output the file in reverse order
 */
 
 #include <stdio.h>
#include <stdlib.h>

#define FILENAME "Test.txt"

int main3(){
    FILE *fp = NULL;

    int cnt = 0;
    int i = 0;

    fp = fopen(FILENAME, "r");

    if (fp == NULL)
        return -1;

    // moves the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);

    // get the position of the file pointer
    cnt = ftell(fp);

    while (i < cnt) {
        i++; // offset
        fseek(fp, -i, SEEK_END); 
		//i=1, fp=char at lenght-1, i=2, fp=char at length-2
        printf("%c", fgetc(fp));
    }

    printf("\n");
    fclose(fp);
    fp = NULL;

    return 0;
}
