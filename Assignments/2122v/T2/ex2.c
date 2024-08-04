#include <stdio.h>
#include <string.h>

void *mymemmove(void *dst, const void *src, size_t len);

int main() {
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

    //bigger string but lenght is inferior than actual
    char str3a[] = "Olaola";
    char str4a[] = "Adeusssssssssss";
    mymemmove(str3a, str4a, strlen(str4a)+1);
    printf("%s\n", str3a);

    return 0;
}