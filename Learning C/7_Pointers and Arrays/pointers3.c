#include <stdio.h>
#include <stdlib.h>

//counting characters in a string


int stringLength(const char *string);

int main(){
   printf("%d \n", stringLength("stringLength test"));
   printf("%d \n", stringLength(""));
   printf("%d \n", stringLength("jason"));

    return 0;
}

int stringLength(const char *string){
    const char *lastAddress = string;

    while (*lastAddress)
        ++lastAddress;

    return lastAddress - string;
}


//pass by reference
//theres 2 ways to pass parameters to a functions: by value, by reference


//pass by value will not works with primite types, because the value is copied, not the address
int x = 5;
int y = 7;
void swap(int x, int y){
	int temp;
	temp = x;
	x = y;
	y = temp;
	return;
}


void swap(int* x, int* y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return;
}

swap(&x, &y);










void square(int * x);

int main2(){
   int num = 5;

   square(&num);
   printf("The square of the given number is %d\n", num);

   return 0;
}

void square(int * x){
    *x = (*x) * (*x);
}





//dynamic memory allocation
/*
whenever u define a variable in C, he compiler automatically allocates the correct amount of storage for you based on the data type

it is frequently desirable to be able to dynamically allocate storage while a program is running

if u have a program that is designed to read in a set of data from a file into an array in memory u have 3 choices:
define the array to contain the maximum number of possible elements at compile time(nop)
use a variable length array to dimension the size of the array at runtime
allocate the array dynamically using one of the C's memory allocation routines
dynamic memory allocations allows memory for storing data to be allocated ynamically when ur program executes
allocating memory dynamically is possible only because u have pointers available

allocating data dynamically allows u to create pointers at runtime that are just large enought to hold the ammount of data u require for the task



Heap vs stack

dynamic memory allocation reserves space in a memory area called the heap

the stack is another place where memory is allocated
function argument and local variables in a function are stored here
when the execution of a function ends, the space allocated to the store argument and local variables is freed

the memory in the heap is differeant in that it is controlled by u
when u allocate memory on the heap, it is up to u to keep track of when the memory u have allocated is no longer required
u must free the space u have allocated to allow it to be reused


the methods to all of this are:
malloc, calloc and realloc


malloc
need the include the stdlib.h
u specify the number of bytes of memory that u want allocated as the argument
returns the address of the 1st byte of memory that is allocated
because u get an address returned, a pointer is the only place to put it

 */


int *pNumber = (int*)malloc(100);

/* 

in the above, u have requested 100 bytes of memory and assigned the adress of this memory block to pNumber
pNumber will point to the 1st int location of the bgggining of the 100 bytes sthat are allocated
can hold 25 int values on my computer, because they required 4 bytes each
assumes that type int requires 4 bytes

*/

//better way:
int* pNumber = (int*)malloc(25*sizeof(int));


//malloc returns a pointer of type pointer to void, so u have to cast to int since the pointer is of type it


//if the memory that u requested fails, it returns null
//its a good idea to check that its not nul

if(!pNumber){
	//deal with memory allocation failure
}

/*
releasing memory

when u allocate memory dynamically u should always release the memory when it is no longer required

memory that u allocate on the heap will be automatically released when ur program ends
better to explicitly release the memory when u are done with it even if its just before u exist from the program


a memory leak occurs when u allocate some memory and u do not retain the reference to it, so u caant release the memory
often ocrrurs within a loop
because u do not release memory, ur program consumes more and more

to free memory that u have allocated, u must still have acess to the addres 

free(pNumber);
pNumber = NULL;

the free() function has a formal parameter of type void*
u can pass a pointer of any type as argument

as long as pNujmber contains the addres that was returned when the memory was allocated the entire block of memory will be freed for further use

u should always set the pointer to null after the memory that it points to has been freed


calloc //similar to malloc but
it allocates memory as a number of elements of a given size
it initializes the memory that is allocated so that all bytes are zero

calloc function requires 2 arguments
number of data items for which space is required
size of each data item

is declared in the stdlib.h header

int* pNumber = (int*) calloc(75, sizeof(int));

the return value will be NULL if it was nos possible to allocate the memory requested
simlar to mallioc
but the big plus is that u know the memory area will be initizliaed to 0



 */



/*
realloc() function enables u to reuse or extend memor ythat u previously allocated using malloc or calloc
when u need more memory or less.

expects 2 arguments
a pointer containing an address that was previously returned by a call to malloc or calloc
the size in bytes of the new memory that u want allocated

allocated the ammount of memory u specify by the second argument
transfers the contents of the previously allocated memory referenced by the pointer that u suppply as the first argument o the newly allocated memory
returns a void* pointer to the new memory or NULL if the operation fails for some reason

the most imporant feature of this operation is that contents of the original memory are preserved
 */








char *str;

//INItial memory allocation

str = (char*) malloc(15*sizeof(char));
strcpy(str,"jason");
printf("String = %s, Address = %u\n", str, str);

//reallocating memory

str = (char*) realloc(str, 25*sizeof(char));
strcat(str,".com");
printf("String = %s, Address = %u\n", str, str);

free(str);






//get input from user

#include <stdio.h>
#include <stdlib.h>

int main3(){
   int size;
   char *text = NULL;

   printf("Enter limit of the text: \n");
   scanf("%d", &size);

   text = (char *) malloc(size * sizeof(char));

   if (text != NULL)
   {
       printf("Enter some text: \n");
       scanf(" ");
       gets(text);

       printf("Inputted text is: %s\n", text);
   }

   free(text);
   text = NULL;
   return 0;
}
