#include  <stdlib.h>
#include <string.h>

typedef struct fragment { size_t size; unsigned char *data; } Fragment;

typedef struct pack_node { struct pack_node *next; Fragment *frag; } PackNode;

PackNode *append(PackNode **packet, const char *data, size_t size) {
	PackNode *prev = NULL;
	for (PackNode *node = *packet; node != NULL; prev = node, node = node->next)
		;
	PackNode *pack_node = malloc(sizeof *pack_node);
	pack_node->next = NULL;
	Fragment *frag = malloc(sizeof *frag);
	pack_node->frag = frag;
	frag->size = size;
	frag->data = malloc(size);
	memcpy(frag->data, data, size);
	if (prev == NULL)
		return pack_node;
	else
		prev->next = pack_node;
	return *packet;
}

PackNode *trim_ahead(PackNode *packet, char *buffer, size_t buffer_size, size_t *size) {
	size_t initial_size = buffer_size;
	PackNode *new_packet = packet;
	PackNode *node;
	for (node = packet; node != NULL; node = node->next) {
		if (buffer_size >= node->frag->size) {
			new_packet = node->next;
			memcpy(buffer, node->frag->data, node->frag->size);
			buffer +=  node->frag->size;
			buffer_size -= buffer_size;
			free(node->frag->data);
			free(node->frag);
			free(node);
		}
		else
			break;
	}
	if (node != NULL && buffer_size > 0) {	//cortar um fragmento
		memcpy(buffer, node->frag->data, buffer_size);
		unsigned char *data = malloc(node->frag->size - buffer_size);
		memcpy(data, node->frag->data + buffer_size, node->frag->size - buffer_size);
		free(node->frag->data);
		node->frag->data = data;
		node->frag->size -= buffer_size;
	}
	*size = initial_size - buffer_size;
	return new_packet;
}
