#include <stdio.h>
#include <string.h>

void* mymemmove(void *dst, const void *src, size_t len){ //  copies len bytes from string src to string ds
    if(dst==src || len<1) return dst;

    //use other vars in order to not alter what the argument pointers point to
    const char *s = (char*)src; 
    char *d = (char*)dst;

    while (len--){
        *d++ = *s++;
    }

    return dst;
}

void ayay(){
    char* ay1 = "ay1";
    char* ay2 = "ay2";
    *ay1 = *ay2;
    ay1++;
    ay2++;
}

int main() {
    
    // library memmove:
    /* //smaller string than destination, lenght properly indicaded
    char str1[] = "Olaola";
    char str2[] = "Adeus";
    printf("%ld\n",  strlen(str1));
    memmove(str1, str2, strlen(str2));
    printf("%s\n", str1);

    //smaller string size but extra lenght indicaded
    char str1b[] = "Olaola";
    char str2b[] = "Adeus";
    memmove(str1b, str2b, strlen(str2b)+1);
    printf("%s\n", str1b);

    //smaller string size but excessive lenght indicaded
    char* str1c = "Olaola";
    char* str2c = "Adeus";
    memmove(&str1c, &str2c, strlen(str2c)+10);
    printf("%s\n", str1c);


    //bigger string but size is lenght is inferior than actual
    char str3[] = "Olaola";
    char str4[] = "Adeusssssssssss";
    memmove(str3, str4, strlen(str4)+1);
    printf("%s\n", str3);

    //stack smashing
    char str5[] = "Um dois tres quatro ";
    char str6[] = "cinco seis";
    //memmove(str5+strlen(str5), str6, strlen(str6)+1); 
    //printf("%s\n", str5); */

    ///////   mymemove   /////////

    //smaller string than destination, lenght properly indicaded
    char str1a[] = "Olaola";
    char str2a[] = "Adeus";
    printf("%ld\n",  strlen(str1a));
    mymemmove(str1a, str2a, strlen(str2a));
    printf("%s\n", str1a);

    //smaller string size but extra lenght indicaded
    char str1ba[] = "Olaola";
    char str2ba[] = "Adeus";
    mymemmove(str1ba, str2ba, strlen(str2ba)+1);
    printf("%s\n", str1ba);

    //smaller string size but excessive lenght indicaded
    char* str1ca = "Olaola";
    char* str2ca = "Adeus";
    mymemmove(&str1ca, &str2ca, strlen(str2ca)+10);
    printf("%s\n", str1ca);


    //bigger string but size is lenght is inferior than actual
    char str3a[] = "Olaola";
    char str4a[] = "Adeusssssssssss";
    mymemmove(str3a, str4a, strlen(str4a)+1);
    printf("%s\n", str3a);

    return 0;
}