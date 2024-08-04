#include <stdio.h>
#include <stdlib.h>

//DEMONSTRATION, declaring and initializing a struct

struct employee {
char name[30];
char date[15];
float salary;
};

int main(){
   /*declare and initialization of structure variable*/
	struct employee emp={"Mike","7/16/15",76909.00f};

	printf("\n Name: %s"	,emp.name);
	printf("\n Hire Date: %s"		,emp.date);
	printf("\n Salary: %.2f\n",emp.salary);

	printf("\nEnter new employee information to change to: \n");

	printf("Name: ");
	scanf("%s", emp.name);

	printf("\nHire Date: ");
	scanf("%s", emp.date);

	printf("\nSalary: ");
	scanf("%f", &emp.salary);

	printf("\n Name: %s"	,emp.name);
	printf("\n Hire Date: %s"		,emp.date);
	printf("\n Salary: %.2f\n",emp.salary);

    return 0;



//DEMONSTRATION, structure pointers and functions

#include <stdio.h>
#include <stdlib.h>

struct item
{
    char *itemName;
    int qty;
    float price;
    float amount;
};

void readItem(struct item *i);
void printItem(struct item *i);

int main2(){
    struct item itm;
    struct item *pItem;

    pItem = &itm;

    pItem->itemName = (char *) malloc(30 * sizeof(char)); //or (*pItem).amount =

    if(pItem == NULL)
        exit(-1);

    // read item
    readItem(pItem);

    // print item
    printItem(pItem);

    free(pItem->itemName); //we only want to free the memory we allocated, that is itemname

    return 0;
}

void readItem(struct item *i) //aka write to item{
    printf("Enter product name: ");
    scanf("%s", i->itemName);

    printf("\nEnter price: ");
    scanf("%f", &i->price); //since price is not a pointer, it needs &

    printf("\nEnter quantity: ");
    scanf("%d", &i->qty);

    i->amount = (float)i->qty * i->price;
}

void printItem(struct item *i){
    /*print item details*/
	printf("\nName: %s",i->itemName);
	printf("\nPrice: %.2f",i->price);
	printf("\nQuantity: %d",i->qty);
	printf("\nTotal Amount: %.2f",i->amount);
}
