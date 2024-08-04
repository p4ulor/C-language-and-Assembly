#include <stdio.h>
#include <stdlib.h> //for srand() and rand()
#include <time.h> //for time()

int main() {
	int i = 0;
	/*
	srand(time(0)) lets you set a seed to be used to generate random numbers even if you run the same output file
	If you didn't use srand at all or even if you used srand(rand()) outside the loop, because the number generated
	on execution would be the same, which was defined on the latest compilation. Alternatevely, you can use srand
	inside the loop
	*/
	srand(time(0)); 
	while (i<20) {
	//srand(1+rand()%100); 
	printf("%d\n", 1+rand()%6); //generates random numbers 1 to 6
	i++;
	
	}
	return 0;
}

//https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
//https://youtu.be/qs8vVgy5AMc?list=PL78280D6BE6F05D34