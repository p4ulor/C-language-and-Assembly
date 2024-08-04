#include <stdio.h>
#include <stdlib.h>

struct word { int counter; char *word; };

void for_each(void *array, size_t size, size_t elem_size,
    void(*do_it)(void *, void *), void *context) {
    for (size_t i = 0; i < size; ++i)
        do_it((char *)array + elem_size * i, context);
}

/*struct word words[] = {
    {10, "aaa"},
    {100,"bbb"},
    {1000,"ccc"}
};

struct word *fword = words;

void do_it(void *a, void *b){
	struct word *p = (struct word *)a;
	struct word **q = (struct word **)b;
	if(p->counter > (*q)->counter)
		*q = p;
}*/

int main(){
    /*for_each(&words[1], 3, sizeof words[0], do_it, &fword);
	printf("word = %s\n",fword->word);*/
}
