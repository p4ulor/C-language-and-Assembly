#include <stdio.h>


int main() {
    char movie[20];
    char * pMovie = movie;

    fgets(pMovie, 20, stdin);
    puts(pMovie);

	return 0;
}
