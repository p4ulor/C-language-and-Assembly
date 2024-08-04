#include <stdio.h>
#include <stdlib.h>

/* 
There are 2 different ways to acess files:
sequential, in order
random, store data all over the place

w -> write
r -> read
a -> append AKA add more crap
*/

//https://www.learnc.net/c-tutorial/c-read-text-file/

int main() {
    
   FILE * fPointer = fopen("file.txt", "w"); //automatically creates if it doesnt exist
   fprintf(fPointer, "I love cheerries\n"); //file print format
   fclose(fPointer); //frees up resources and memory

   FILE * fPointerRead = fopen("file2.txt", "r");
   char singleLine[150];
   while(!feof(fPointerRead)){ //feof -> file end of file
        fgets(singleLine, 150, fPointerRead);
        puts(singleLine); //prints contents line by line
   } 

   FILE * fPointerAdd = fopen("file2.txt", "a"); 
   fprintf(fPointerAdd, "\nmade by me");

   fclose(fPointerRead);
   fclose(fPointerAdd);



   //random acess, adds modes 
   //w+ -> open for writing and we can read afterwards
   FILE * fPointerWPlus = fopen("file2.txt", "w+"); 
   fputs("I ate 3 pumpins", fPointerWPlus);


   //the new thing:
    //u can hop to append and write in specific positions

    fseek(fPointerWPlus, 7, SEEK_SET); //sseek set -> start from the beggining of the file
    fputs(" pumpkins and much more", fPointerWPlus);
   

   fseek(fPointerWPlus, 0, SEEK_CUR);
   fputs(".", fPointerWPlus);

   fclose(fPointerWPlus); 
   return 0;
}