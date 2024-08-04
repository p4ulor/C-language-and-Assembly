#include <stdio.h>


int main() {
    char movie[] = "The return of"
                    "buckyman";
    //movie = "ok"; //doesn't work because movie is considered a constant
    char * movie2 = "bucky is awesome"; //movie 2 is not a constant, movie2 stores the adress of when the string begins
    
    puts(movie2);
    
    movie2 = "new"; 
    puts(movie2);

	return 0;
}
