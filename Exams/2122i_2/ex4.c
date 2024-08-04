#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


typedef struct node { struct node *next; void *data; } Node;

Node *merge_sorted_lists(Node *list_a, Node *list_b, int (*comparator)(void *, void *)) {
    if (list_a == NULL)
        return list_b;
    else if (list_b == NULL)
        return list_a;
    Node *result;
    if (comparator(list_a->data, list_b->data) <= 0) {
        result = list_a;
        result->next = merge_sorted_lists(list_a->next, list_b, comparator);
    } else {
        result = list_b;
        result->next = merge_sorted_lists(list_a, list_b->next, comparator);
    }
    return result;
}


int main(){

}