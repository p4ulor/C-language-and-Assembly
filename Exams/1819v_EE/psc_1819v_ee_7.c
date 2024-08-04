#include <stdlib.h>

typedef struct {
	unsigned long number: 50;
	unsigned long state: 3;
	unsigned long hlen: 8;
	char holder[];
} Card;

typedef struct node_card { struct node_card *next; Card *card; } NodeCard;

typedef struct { unsigned int ncard; Card *array[]; } ArrayCard;

ArrayCard *list_to_array(NodeCard *list) {
	size_t ncard = 0;
	for (NodeCard *p =list; p != NULL; p = p->next)
		++ncard;

	ArrayCard *array_card = malloc(sizeof *array_card + ncard * sizeof (Card*));
	array_card->ncard = ncard;

	Card **card = array_card->array;

	for (NodeCard *next, *node =list; node != NULL; node = next) {
		next = node->next;
		*card = node->card;
		free(node);
	}
	return array_card;
}

NodeCard *array_to_list(ArrayCard *array) {
	NodeCard *first = NULL, *last = NULL;
	for (size_t index = 0; index < array->ncard; index++) {
		NodeCard *node = malloc(sizeof *node);
		node->card = array->array[index];
		node->next = NULL;
		if (last == NULL)
			first = node;
		else
			last->next = node;
		last = node;
	}
	free(array);
	return first;
}
