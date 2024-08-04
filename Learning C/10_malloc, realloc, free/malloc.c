#include <stdio.h>
#include <stdlib.h>

int main() {
    int * pPoints;
    pPoints = malloc(sizeof(*pPoints)*5);
    free(pPoints);


    int howMany;
    int total=0;
    float average = 0.0;
    int * pointsArray;

    printf("How many numbers do u want to average");
    scanf("%d", &howMany);

    pointsArray = malloc(sizeof(*pointsArray) * howMany);

    printf("Provide them:");

    for(int i = 0; i<howMany; i++){
        scanf("%d", &pointsArray[i]);
        total = total + pointsArray[i];
    }

    average = (float)total / (float)howMany;
    printf("Average is %f\n", average);

	return 0;
}


//https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc