/* 
string aren't already present in the language. Using arrays, we can define strings. 
Which are arrays of characters


All strings terminate with null character: \0

printf("ay \0 nao");
Will only print "ay"

initializing:

char myString[20]
myString can take 19 characters (+1 for \0)

char s[100];    declaration
s = "hello"; doesnt work
strcpy(s, "hello");

displaying string:
printf( %s, message); message has to be \0 terminated, to be valid for printf

inputting string:
char input[10];
printf("Name? ");
scanf("%s", input);

strcmp to compare strings

constant strings:
#DEFINE AY "ay"

const is more flexible than #DEFINE
 - it lets you declare a type
 - allows better control over which parts of the program its usable
 const char message[] = "its final";
 
String functions:
strlen(string)
strcpy(destination, source) doesnt check the size between source and destination
strncpy(destination, source, 10) until 10 characters of source 




 
strcat(tobeAdded, addString)  //the 2nd string isnt altered, only the 1st
and strncattobeAdded, addString, 10) stops on the 10th character

strcmp and strncmp
0 if equal,
-1 if cmp "A" with "B"
1 if cmp "B" with "A"
-1 if cmp "Z" with "a"
1 if cmp "apples" with "apple"



searching, tokanizing and analyzing strings:
searching a string:
 the string.h header file delclares several string searching functions
 for finding a single character or a substring
 strchr(stringtoBeSearched, character)
 returns the pointer to the 1st position in the string where it finds the pointer

 
 and strstr(string toBbeSearched, substring) for searching for substring
  searches one string for the 1st occurence of a substring
  returns a pointer to the position in the first string where the substring is found
  if no match, returns null
 
 tokenizing a string:
 a token is a sequence of characters within a string that is bounded by a delimiter(space, comma, period, etc)
 breaking a sentence into words is called tokenizing
 strtok(string, separatorChar)

analyzing strings:
islower(), isupper(), isalpha(), isdigit()

converting string to uppercase or tolower
for(int i =0; (buf[i] = (char)toupper(buf[i])) != '\0'; ++i);
*/


#include <stdio.h>



int main() {
    char str1[] = "To be";
	char str2[] = "not \n be";
	unsigned int count = 0; //stores the string length

	while(str1[count] != '\0') //increment count till we reach the
	++count;		    //terminating character

	printf("The length of the string \"%s\" is %d characters, \n",str1, count);

	count = 0; //reset count for next string

	while(str2[count] != '\0')
	++count;

	printf("The lenght of the string \"%s\" is %d characters. \n",str2,count);
	
	
	
	char myString[] = "My name is";
	char temp[50];
			//destination
	strncpy(temp, myString, sizeof(temp) -1);
	printf("The string is: %s", temp);

	
	
	if(strncmp("astronomy", "astro", 5)==0){
	printf("Found:astronomy");
	}

	if(strncmp("astounding", "astro", 5)==0){
	printf("Found:astaunding");
	}
	
	
	//searching char
	
	char str[] = "the quick";
	char cha [] = 'q';
	char *gotChar = NULL;
	gotChar = strchr(str, cha); //stores address where cha is found
	
	
	//searching substring, is case sensetive
	char text[] =  "Every dog has his day";
	char words[] = "dog";
	char *pFound = NULL;//^will pointe to
	pFound = strstr(text, words);
	
	
	//tokanizing
	char str[80] = "Hello how are you - my name is";
	const char s[2] = "-";
	char *token;
	
	//get first token
	token = strtok(str,s); //="Hello how are you "
							//2nd call: "my name is"
						
	
	//walk through other tokens
	while(token !=NULL){
		printf(" %s\n", token);
		token = strtok(NULL,s);
	}
	
	
	
	//count the number of letters and digits in a string
	char buff[100]; //input buffer
	int nLetters = 0; //number of letters in input
	int nDigits = 0; //number of digits in input
	int nPunct = 0; //number of punctuation characters
	
	printf("Enter an interesting string of less than %d characters:\n", 100);
	scanf("%s", buff); //read a string into buffer
	
	int i = 0; //buffer index
	while(buff[i]){
		if(isalpha(buff[i]))
			++nLetters; 
		else if(isdigit(buff[i]))
			++nDigits;
		else if(ispunct(buff[i]))
			++nPunct;
		++i;
	}
	printf("\n Your string contained %d letters, %d digits, and %d punctuations characters \n", nLetters, nDigits, nPunct);
	
	
	
	//EQUALS IGNORES CASE:
	
	char text[100]; //input buffer for string to be searched
	char substring[40]; //input buffer for string sought
	
	printf("Enter a string to be searched (less than %d characters)\n", 100);
	scan("%s", text);
	
	printf("\nEnter the string sought(less than %d characters)\n",40);
	scanf("%s", substring);
	
	printf("\nFirst string: %s, second string: %s \n", text, substring);
	
	//convert both string to uppercase
	for(int i = 0; (text[i] = (char)toupper(text[i])) !='\0'; ++i);
	for(int i = 0; (substring[i] = (char)toupper(substring[i])) != '\0'; ++i);
	
	printf("The 2nd string %s found in the first \n", ((strstr(text, substring) == NULL) ? "was not" : "was"));
	return 0;
}
