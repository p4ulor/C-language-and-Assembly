#include <stdio.h>
#include <stdlib.h> //for size_t
#include <string.h> //for memcpy
#include <stdint.h> //in order to use uint32_t

typedef struct data { int key; size_t length; uint32_t data[]; } Data;

typedef struct data_node { struct data_node *next; Data *data; } NodeData;

NodeData *array_to_list_by_key(Data *data[], size_t length, int key){
   
   NodeData *previous = NULL;

   for(size_t i = 0; i<length; ++i){
      if( data[i]->key == key){

         size_t dsize = sizeof *data[i] + data[i]->length * sizeof(__UINT32_TYPE__);
         Data *d = malloc(dsize);
         memcpy(d,data[i],dsize);
         NodeData *node = malloc(sizeof *node);
         node->data = d;
         node->next = NULL;
         if(previous != NULL){
            previous->next = node;
         }
         previous = node;
      }
      return previous;
   }
}


void free_data_list(NodeData *data_list){
   NodeData *next;
   for(NodeData *node = data_list;node!=NULL; node = next){
      next = node->next;
      free(node->data);
      free(node);
   }
}

int main(){
   
}
