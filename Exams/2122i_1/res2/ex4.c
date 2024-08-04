#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


typedef struct list_node { struct list_node *next; void *data; } List_node;

List_node *list_search(List_node *list, const void *data,
                        int (*fcmp)(const void *, const void *)) {
    for (List_node *p = list; p != NULL; p = p->next)
        if (fcmp(p->data, data) == 0)
            return p;
    return NULL;
}


int main(){

}