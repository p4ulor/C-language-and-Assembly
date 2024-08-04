


typedef struct fragment { size_t size; unsigned char *data; } Fragment;

typedef struct pack_node { struct pack_node *next; Fragment *frag; } PackNode;

PackNode *append(PackNode *packet, const char *data, size_t size){

    Fragment *new = malloc(sizeof (Fragment));
    new->size = size;
    new->data = malloc(size);
	memcpy(new->data, data, size);

    PackNode *node = malloc(sizeof *node);
    node->next = NULL;
    node->frag = new;

    if(packet == NULL) return node;

    PackNode *curr = packet;
    while(curr->next != NULL)
        curr = curr->next;
    
    curr->next = node;

    return packet;
}


PackNode *trim_ahead(PackNode *packet, char *buffer, size_t buffer_size, size_t *size){
    
}
