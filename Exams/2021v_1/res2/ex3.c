#include <stdio.h>
#include <stdlib.h>

typedef struct item { int key; char label[16]; } Item;

typedef struct item_coll { size_t length; Item *items[]; } ItemColl;

char *find_first(ItemColl *ic, int key); /*{
    for (size_t i = 0; i < ic->length; i++)
        if (ic->items[i]->key == key)
            return ic->items[i]->label;
    return NULL;
}*/

int main() {
    Item fruits[] = {
        {10, "Apple"},
        {12, "Pear"},
        { 8, "Banana"},
        { 2, "Grape"},
        {15, "Watermelon"}
    };
    size_t nfruits = sizeof fruits/sizeof *fruits;  /* avoid magic-numbers */
    /* allocate storage for basket + nfruits pointers */
    ItemColl *basket = malloc (sizeof *basket + 
                                nfruits * sizeof *basket->items);
    if (!basket) {  /* validate allocation succeeded */
        perror ("malloc-basket+5_item_coll");
        return 1;
    }
    basket->length = nfruits;   /* assign length */

    for (size_t i = 0; i < nfruits; i++)  /* assign addresses to structs */
        basket->items[i] = &fruits[i];

    char *label = find_first(basket, 12);  /* save return */
    if (label)  /* validate not NULL before printing */
        printf ("%s\n", label);

    free (basket);  /* don't forget to free the memory you allocate */

    return 0;
}
