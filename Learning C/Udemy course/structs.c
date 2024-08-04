#include <stdio.h>


//structures in C provide another tool for grouping elements together
int main() {
	
	struct date{
		int month;
		int day;
		int year;
	}
	
	struct date today;

	//memory is now allocated for the 3 integer values for each variable

	//acessing members in a struct

	//a structure variable name is not a pointer
	//u need a special syntax to acess the members

	today.day = 25;
	today.year = 2015

	printf("Todays date is %i %i %.2i \n", today.month, today.day, today.year %100);
		
	//defining the structure and variable at the same time
	//date can be ommited
	struct date {
	int month;
	int day;
	int year
	} today;
		
	/*
	a disadvantage of the above is that u can no longer define further instances of the structure in another statement

	all the variables of this structure type that u want in your program must be defined in the one statemnet */
	
	//initializing strucutres is similar to an array:
struct date today = {7,2,2015};
struct date dat1 = {7,2}; //also works

//u can also specify the order at which u initilize:

struct date date1 = {.month = 12, .day = 10};

//assgiment with compound literals

today = (struct date) {9,25,2015};

//uc can also specify with .member notation
today = (struct date) { .month = 9, .day = 25};


//arrays of structures
struct date myDate[10];

myDate[1].year=1986;
			//{ can be ommirted, with only commas
struct date myDate[5] = { {12,10,1975}, {12,10,1975}, {12,10,1975} };

struct date myDates[5] = { [2] = {12,10,1975} };
struct date myDates[5] = { [1].month = 12, [1].day = 10};



//structs containing arrays

struct month{
int numberOfDays;
char name[3];
};

struct month aMonth
aMonth.numberOfDays = 31;
aMonth.name[0] = 'J';
aMonth.name[1] = 'a';
aMonth.name[2] = 'n';

struct month aMonth = {31m {'j', 'a', 'n'} };

struct month months[12];





//nested structures
struct dateAndTime{
	struct date sdate;
	struct time stime;
};
struct dateAndTime event;
event.sdate.month = 10;
++event.stime.seconds;
			//     date         time
struct dateAndTime event = { {2,1,2015}, {3, 30,0} };

struct dateAndTime event = { {.month = 2, .day = 1, .year = 2015}, {.hour = 3, .minutes = 30, .seconds = 0}
};









//an array of nested structures
struct dateAndTime events[100];

events[0].stime.hour = 12;
events[0].stime.minutes = 0;
events[0].stime.seconds = 0;

//declaring a structure within a structure
struct Time{
	struct Date {
	int day;
	int month;
	int year;
	} dob;
int hour;
int minutes;
int seconds;
};
//date does not exists outside of Time








//structures and pointers
//C allows for pointers to structures
	
//pointers to structures are easier to manipulate than structures themselves

//in some older implementations, a structure cannot be passed as an argument to a function, but a pointer to as structure can
//and passing a pointer is just more efficient

struct date *datePtr

//the variable dataPtr can be assigned just like other pointers


(*datePtr).day = 21;
datePtr = &todaysDate	
	
//pointers to structres are so often a special operator exists the structure pointer operator ->

(*x).y
//is the same as
x->y
if((*datePtr).month == 12)
if(datePtr->month == 12)

	
	
	
	
	
	
	
//example(strucure should be defined outside of methods to so they can be used anywhere
struct date{
int month
int day;
int year;
};

structure date today, *datePtr;
datePtr = &today;

datePtr->month = 9;
datePtr->day = 25;
datePtr->year = 2015;
printf("Today's date is %i / %i / %.2i \n", datePtr->month, datePtr->day, datePtr->year % 100);









//strucures containing pointers
struct intPtrs{
int *p1;
int *p2;
};

struct intPtrs pointers;

int i1 = 100, i2;

pointers.p1 = &i1; //if it was char, id have to allocate dynamic memory
pointers.p2 = &i2;
*pointers.p2 = -97; //dereferencing a pointer, can't use ->

printf("i1 = %i, *pointers.p1 = %i \n", i1, *pointers.p1);
printf("i2 = %i, *pointers.p2 = %i \n", i2, *pointers.p2);	
	
	
	

	
	
	
	

//character arrays or character pointers?
struct names{
char first[20];
char last[20];
};

//OR

struct pnames{
char* first;
char* last;
};

//u can do both, but the difference is:

struct names veep = {"talia", "summers"};
struct pname treas = {"tali", "ay"};
printf("%s and %s \n", veep.first. treas.first);

//the struct names variable veep
	//strings are stored inside the structure
	//structure has allocatted a total of 40 bytes to hold the 2 names

//the struct pnames variable treas
	//strings are stored whereever the compiler stores string constants
	//the structure holds the 2 addresses, whitch takes a total of 16 bytes on our system
	//the struct pnames structure allocates no space to store strings
	//it can be used only with string that have had space allocated for them elsewhere
	  //such as string constant or strings in arrays, whenever u have pointers inside of a struct, u have to use malloc or calloc
	  // the pointers in a pnames structure should be used only to manage strings that were created and allocated elsewhere in the program
	
	
/*
one instance in whitch it does make sense to use a pointer in a structure to handle a string is if your dynamically allocating that memory
	use a pointer to store the address
	has the advantage that y can ask malloc() to allocate just the amount of space that is needed for a string
 */
	
	
struct namect{
	char* fname; //using pointers instead of arrays
	char* lname;
	int letters;
};

/* 
understand that the 2 strings sare not store in the structure
	stored in the chunk of memory managed by malloc()
	the addresses of the 2 strings are stored in the structure
	addresses are what string-handling functions typically work with
*/



void getInfo(struct namect* pst){
char temp[SLEN];
printf("Please enter your first name. \n");
s_gets(temp, SLEN); //get input

pst -> fname = (char*) malloc(strlen(temp)+1); //allocate memory to hold name, +1 for the null terminator
strcpy(pst->fname, temp); //copy name to allocated memory

printf("Please enter your last name.\n");
s_gets(temp,SLEN);


pst->fnmae = (char*) malloc(strlen(temp)+1); //allocate memory to hold name
strcpy(pst->fname, temp); //copy name to allocated memory



	

	
	
	
//structures and functions

struct Family{
char name[20];
int age;
char father[20];
char mother[20];
};

bool siblings(struct Family member1, struct Family member2){
	if(strcmp(member1.mother, member2.mother) == 0)
		return true;
	else return false;
}
//pointers to structures as function arguments
//u should use a pointer to a structure as an argument
//it can take a bit of time to copy the large structures as arguments, as well as requiring whatever amount of memory to store the copy of the sructure.
//pointers to structures avoid the memory consumption and the copying time(only a copy of the pointer argument is made)

bool siblingss(struct Family *pmember1, struct Family *pmember2){
if(strcmp(pmember1->mother,pmember2->mother) == 0)
	return true
else return false
}

//u can also use the const modifier to not allow any modification of the members of the struct(what the struct is pointing to). By putting "const" after "Family"

bool siblings(Family const *pmember1, Family const *pmember2)

//u can also use the const modifier to now allow any modification of the pointers address 
//any attempt to change those structures will cause an error message during compilation
//now u cant change the value of pmember1, but its redundant because you're passing the copy of the address
//u cant modify the addresses stored in the pointers
//its the pointers that are protected here, not the structures to which they point

bool siblings(Family *const pmember1, Family *const pmember2)





//RETURNING a structure from a function

//the function prototype has to indicate this return value in the normal way

struct Date my_fun(void); //this is a prototype for a function taking no arguments that returns a structure of type Date

//it is often more convenient to return a pointer to a strucure
//when returning a pointer to a structure, it should be created on the heap

struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(struct funds moolah){
return (moolahbankfund + moolah.savefund);
}

int main(void){
struct funds stan = {
	"Garlic-Melon Bank",
	4032.27,
	"Lucky's Saving and Loan",
	8543.94
	};
printf("Stan has a total of $%.2f \n", sum(stan));
return 0;
}



//I mentioned earlier that u should always use pointers when passing structures to a function
//it works on older as well as newer C implementation and that it is quick(u just pass a single address)
//however, u have less protection for your data
   //some operations in the called function could inadvertently affect data in the original structure
   //use const qualifier solves that problem

//advantages of passing structures as arguments
   //the functions works with copies of the original data, which is safer than working with the original data
   //the programming style tends to be clearer

//main disadvantages to passing structures as arguments
  //older implementations might not handle the code
  //wastes time and space
  //especially wasteful to pass large structures to a function that uses only 1 or 2 members of the structure

//programmers use structure pointers as function arguments for reasons of efficiency and use consst when necessary
//passing structures by value is most often done for structures that are small	

	return 0;
}
