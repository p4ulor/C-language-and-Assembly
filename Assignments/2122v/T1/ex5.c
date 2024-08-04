#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXINPUTSIZE 256

int isEscapeSequnceOrSpace(char character){ //https://en.wikipedia.org/wiki/Escape_sequences_in_C
    int ascii = (int) character;
    switch(ascii){
        case 0x20: return 0; break; //  (space)

        case 0x07: return 1; break; // \a
        case 0x08: return 1; break; // \b
        case 0x1B: return 1; break; // \e
        case 0x0C: return 1; break; // \f
        case 0x0A: return 1; break; // \n
        case 0x0D: return 1; break; // \r
        case 0x09: return 1; break; // \t
        case 0x0B: return 1; break; // \v
        case 0x5C: return 1; break; // \\

        case 0x27: return 1; break; // \'
        case 0x22: return 1; break; // \"
        case 0x3F: return 1; break; // \?
    }
    return -1;
}

int main() {
    char inputFileName[MAXINPUTSIZE];
    char* pBuf = inputFileName;
    printf("$ hexdump -C ");
    scanf("%s", inputFileName); //putting a space before %s can be useful in some problematic contexts
	getchar(); // absorb enter

    if(strncmp(inputFileName, "exit", 4)==0) return 0;
    
    FILE * fPointerRead = fopen(inputFileName, "r");

    if (fPointerRead == NULL){
        printf("Error: could not open file %s\n", inputFileName);
        main();
    }

    char character;
    unsigned int n = 0;
    char hex[3];
    char lineBlockWith16Chars[19]; //the |ola..tudo bem...| part. Size = 16 + 2('|') + 1('\0')
    lineBlockWith16Chars[0]='|'; //instead of doing it for multiple lines
    char characterBlockIndex=1;
    
    while ((character = fgetc(fPointerRead)) != EOF) {
        if(n%16==0) printf("%08x", n);
        if(n%8==0) putchar(' '); //extra space in the middle

        putchar(' ');

        char DotOrSpace = isEscapeSequnceOrSpace(character);
        if(DotOrSpace==-1) {
            lineBlockWith16Chars[characterBlockIndex] = character;
        }
        else {
            if(DotOrSpace==1) lineBlockWith16Chars[characterBlockIndex] = '.';
            else lineBlockWith16Chars[characterBlockIndex] = ' ';
        }
        
        sprintf(hex, "%02X", character);
        putchar(tolower(hex[0])); putchar(tolower(hex[1])); 
        
        characterBlockIndex++;
        n++;

        if(n%16==0) { //then its the end of a line
            putchar(' ');
            lineBlockWith16Chars[characterBlockIndex]='|';
            printf(" %s", lineBlockWith16Chars);
            characterBlockIndex=1;
            printf("\n");
        }
    }
    
    char characterIndexCopy = characterBlockIndex;
    while(characterIndexCopy<17){
        putchar(' ');
        if(characterIndexCopy%8==0) putchar(' '); //extra space in the middle
        putchar(' ');putchar(' ');
        characterIndexCopy++;
    }

    lineBlockWith16Chars[characterBlockIndex]='|';
    printf(" %.*s", characterBlockIndex+1, lineBlockWith16Chars); //+1 to count the last bar |

    printf("\n%08x", n);    

    printf("\n\n"); 
    main();
    return 0;
}