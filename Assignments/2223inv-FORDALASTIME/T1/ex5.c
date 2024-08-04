#include <stdio.h>  /* printf     */
#include <getopt.h> /* getopt API */
#include <stdlib.h> //for malloc and FILE

int main(int argc, char *argv[]){
	int opt;

	char* inputFileContent = malloc(100*sizeof(char));
	char* outputFile = malloc(100*sizeof(char));

	while ((opt = getopt(argc, argv, "o:i:CW")) != -1) {
		switch (opt) {
			case 'i':
			printf("Option a has arg: %s\n", optarg);
			FILE* fptr = fopen(optarg, "r");
			if(fptr == NULL){
				printf("File not found!");   
				exit(1);             
			} else {
				size_t len = 0;
    			ssize_t read;
				char * line = NULL;
				while ((read = getline(&line, &len, fptr)) != -1) {
					printf("Retrieved line of length %zu:\n", read);
					printf("%s\n", line);
				}

				fclose(fptr);
			}

			break;

			case 'o':
			printf("Option b has arg: %s\n", optarg);
			break;

			case 'C':
			printf("Option C was provided\n");
			break;

			case 'W':
			printf("Option W was provided\n");
			break;
			
			case ':':
			printf("Missing arg for %c\n", optopt);
			break;
		}
	}
  
	return 0;
}
