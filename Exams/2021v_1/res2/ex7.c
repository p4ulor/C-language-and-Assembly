


typedef struct data { 
    int key; 
    size_t length; 
    uint32_t data[]; 
} Data;

typedef struct data_node { 
    struct data_node *next;
     Data *data; 
} NodeData;

NodeData *array_to_list_by_key(Data *data[], size_t length, int key){
    NodeData *head = NULL;
    NodeData *tail = NULL;
    
    for(int i = 0; i < length; i++){
        if(data[i]->key == key){
            size_t size = sizeof (struct data) + data[i]->length * sizeof data[0];
            Data *new = malloc(size);
            memcpy(new, data[i], size);

            NodeData *node = malloc(sizeof *node);
            node->next = NULL;
            node->data = new;

            if(head == NULL)
                head = node;
            else
                tail->next = node;
            tail = node;
        }
    }
    return head;
}


void free_data_list(NodeData *data_list){
    NodeData *prev = data_list;
    NodeData *p = data_list->next;
    for(; prev != NULL; p = p->next){
        free(prev->data)
        free(prev)
        if(p == NULL) break;
        prev = p;
    }
}