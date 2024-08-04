#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


typedef struct node{
    struct node *next;
    int key;
    size_t data_len;
    void *data;
} Node;

Node *list_select(Node *list, int key){
    Node *head = NULL;
    Node *tail = NULL;

    Node *curr = list;
    for(;curr != NULL; curr = curr->next){
        if(curr->key == key){
            Node *node = malloc(sizeof *node);
            node->next = NULL;
            node->key = key;
            node->data_len = curr->data_len;
            node->data = malloc(curr->data_len);
            memcpy(node->data, curr->data, curr->data_len);

            if(head == NULL)
                head = node;
            else 
                tail->next = node;
            tail = node;
        }
    }
    return head;
}


void list_trim(Node *list, int key){
    Node *curr = list;
    Node *prev = NULL;

    while(curr != NULL){
        Node *next = curr->next;
        if(curr->key == key){
            if(curr == list) 
                list = next;
            else
                prev->next = next;
            free(curr->data);
            free(curr);
            curr = next;
        }
        else {
            prev = curr;
            curr = next;
        }
    }
}