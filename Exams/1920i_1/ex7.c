#include <stdlib.h> //for size_t

typedef struct data_node {
    struct data_node *next;
    size_t length;
    void *data;
} DataNode;


DataNode *list_copy(DataNode *list){
    DataNode *head = NULL;
    DataNode *tail = NULL;
    DataNode *curr = list;

    while(curr != NULL){
        DataNode *node = malloc(sizeof *node);
        node->next = NULL;
        node->length = curr->length;
        node->data = malloc(node->length);
        memcpy(node->data, curr->data, node->length);

        if(head == NULL) head = node;
        else tail->next = node;
        tail = node;
        curr = curr->next;
    }

    return head;
}

void list_destroy(DataNode *list){
    DataNode *prev = list;
    DataNode *curr = list->next;
    while(prev != NULL){
        free(prev->data);
        free(prev);
        prev = curr;
        curr = curr->next;
        if(curr == NULL) break;
    }
}
