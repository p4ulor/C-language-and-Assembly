#include <stdio.h>

struct word words[] = {
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
}

int main(){

	foreach(&words[1], 3, sizeof words[0]), do_it, &pword;
	printf("word = %s\n",pword->word);
	
}