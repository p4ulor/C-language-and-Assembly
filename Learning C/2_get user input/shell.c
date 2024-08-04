#include <stdio.h>
#include <stdlib.h>

const size_t BUFFERSIZE = 100;

char **splitLine(char *line){
  
}

int main() {
  char* line=NULL;
  size_t lineSize = 0;
  size_t len = 0;

  char** args;
  int status;
  char* buffer = malloc(BUFFERSIZE);
  

    do {
        printf("\n$ ");	
        lineSize = getline(&buffer, &len, stdin);
        buffer[lineSize-1]='\0';
        lineSize--;
        //args = splitLine(line);
        printf("You typed %s. Lenght: %ld, linesize: %ld", buffer, len, lineSize);
        //status = cmd_execute(args,0);
        free(line);
        //free(args);
    } while (status);

  return 0;
}