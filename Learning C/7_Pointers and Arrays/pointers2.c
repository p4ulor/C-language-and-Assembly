#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 150;
    int *pNum = NULL;

    pNum = &num;

    printf("num address is:  %p\n", &num);
    printf("Address of pNum: %p\n", &pNum);
    printf("value of the pNum: %p\n", pNum);
    printf("value of what pNum is pointing to: %d\n", *pNum);
	
	
	
	
	int value = 0;
	int* pvalue = &value;
	scanf(%d, pvalue);
	printf("u entered: %d \n", value);
	
	
	//CONSTANT POINTERS:
	long value = 9999L; //cant be changed
	const long* pvalue = &value // defines a pointer to be a constant, so, we cant write to what the pointer points using the pointer itself
	
	*pvalue = 8L; //error, attempt to change const location. 
	//The pointer itself is not a constant, its constant what the pointer points to
	long number = 8L;
	pvalue = &number;
	
	value = 7L; //the value pointed to changed, but u did not use the pointer to make the change 
	
	
	//U might also want to ensure that the address stored in a pointer cannot be changed
	//u can do this by using the const keyword in the declartion of the pointer
	int count = 43;
	int *const pcount = &count;	
	*pcount = 45; //OK
	
	//the abive ensures that a pointer always points to the same thing
	//indicates that the address stored must not be changed
	//compiler will check that u do not inadvertently attempt to change what the pointer pointer elsewhere in ur code
	
	int item = 34;
	pcount = &item //error, attempt to change a constant pointer
	
	const int* //value cannot be changed
	int *const //pointer address cannot change
	
	
	//creating a constant pointer that points to a value that is also constant:
	int item = 25;
	const int *const pitem = &item
	
	//u can only change the value of item directly
	
	
	//VOID POINTERS:
	
	/* void=absence of value
	a void pointer can contain the adress of a data of any typedef
	void* is often used as a parameter type or return value type with functions that deal with daa in a type independent way
	the void pointer does not know what type of object it is pointing to, so it cannot be dereferenced directly
	the void pointer must first be explicitly cast to another proper pointer type before it is dereferenced
	
		*/
	
	int i = 10;
	float f = 2.34;
	char ch = 'k';
	
	void *vptr;
	
	vptr = &i;
	printf("Value of i = %d\n", *(int*)vptr);
	
	vptr = &f;
	printf("value of f = %.2f\n", *(float*)vptr);
	
	vptr=&ch;
	printf("value of ch = %c\n", *(char*)vptr);
	
	
	
	//pointers and arrays. Using pointers with arrays is faster
	int values[100];
	int *valuesPtr;
	valuesPtr = values; //points to the 1st element
	valuesPtr = &values[0];
	
	ar[i] == *(ar+i) //both work for arrays and pointer
	ar++ //only works if ar is pointer
	
	//pointer arithmetic
	
	*(valuesPtr + 3) //points to values[3]
	
	values[10] = 27
	*(valuesPtr + 10) = 27;
	
	//or             *array
	int arraySum(int array[], const int size){
		int sum = 0, *ptr;
		int* const arrayEnd = array + size;
		
		for(ptr = array; ptr < arrayEnd; ++ptr)
			sum = sum + *ptr;
		
		return sum;
	}
	
	int arraySum(int *array, const int size){
		int sum = 0, *ptr;
		int* const arrayEnd = array + size;
		
		for(; array < arrayEnd; ++array)
			sum = sum + array;
		
		return sum;
	}
	int values[10] = {1,2,3,4,5,6,7,8,9,10};
	arraySum(values, 10)
	
	
	int array[3];
	int* pt1, *pt1;
	
	//valid           invalid
	pt1++;            array++;
	pt2 = pt1 +2;     pt2 = pt2 + pt1;
	pt2 = array +1;   pt2 = array * pt1;
	
	
	
	
	
	
	
	char str[] = "a string";
	char *p = str;
	//using array of nums: i < sizeof(arr)/sizeof(multiple[0])
	for(int i = 0; i< strnlen(str,sizeof(str));++i)
		printf("str[%d]=%c *(p+%d)=%c &multiple[%d] = %p p+%d=%p \n", 
			        i,str[i],   i,*(p+i),       i,  &str[i],i,p+i);
	
	
	
	
	
	//array parameter vs char* parameter
	void copyString(char to[], char from[]{
		int i;
		for(i = 0; from[i]!='\0'; ++i)
			to[i] = from[i];
		to[i]='\0';
	}
	
	void copyString(char* to, char* from{
		for(; *from != '\0'; ++from, ++to)
			*to = *from;
		*to='\0';
	}
	
	void copyString(char* to, char* from{ //most optimized
		while(*from) //the null character is equal to the value 0,so it will jump out
			*to++ = *from++;
		*to='\0';
	}
	
	
	char string1[] = "a string to be copied";
	char string2[50];
	copyString(string2, string1);
	
	
	
	

	
	
	
	
	
	
	
	
	
	
    return 0;
}
