#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>



void bubble_sort(void *base, size_t num_elems, size_t elem_width, int (*cmp)(const void *, const void *)){
  for(size_t i = num_elems - 1; i>=1;i--){
    char *p = (char *)base;
    for(size_t j = 0; j< i; j++) {
      if(cmp(p,  p+elem_width) > 0)
        swap(p, p+elem_width, elem_width);
        p+=elem_width;
    }
  }
}

void swap(char *p, char *d, size_t elem_width){
  
}

int *cmp(const char *a, const char *b){
    if (strcmp(a, b) > 0)
		return 1;
    else 
	    return 0;
}

int main(){

    char *a = "ola";
    char *b = "ate";
    char *c = "ter";
    char *d = "ver";

    char *array = {a, b, c, d};

    bubble_sort(array, 4, 3, cmp);
}