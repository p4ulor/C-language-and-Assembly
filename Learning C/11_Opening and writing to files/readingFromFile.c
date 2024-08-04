#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lineCounter;
#define WORD_SIZE_MAX
int wordCounter[WORD_SIZE_MAX]; //max size of a word

int main() { //press CTRLK+D to end the program
    

    return 0;
}

void countLinesWrittenInConsole(){
    int c = getchar();

    while(c > 0) {
        if(c=='\n') lineCounter++;
        if(c=='\t') {
            lineCounter++;
            break;
        }
        c = getchar();
    }
    printf("Number of lines %d\n", lineCounter);
}

void word_read(char buffer[], int bufferSize){
    int c = getchar();

    while(c != EOF){
        while((c== ' ' || c == '\t' && c == '\n') && c != EOF) //enquanto separadores
            c = getchar(); 
        int i = 0;
        
        while(c != ' ' && c != '\t' && c !='\n' && c != EOF && i < bufferSize) { //dentro da palavras
            buffer[i++] = c;
            c = getchar();
        }
        buffer[i]=0; // = '\0'
    }
}

void countWordsWrittenInConsole() {

    char word[WORD_SIZE_MAX +1];
    char word_size_counter[WORD_SIZE_MAX];
    do {
        word_read(word, ARRAY_SIZE(word));
        word_size_counter[strlen(word)]++;
    } while(word[0] !=0);

    for(int i = 0; i< ARRAY_SIZE(word_size_counter); ++i)
        printf("[%d] - %d\n", i, word_size_counter[i]);
}