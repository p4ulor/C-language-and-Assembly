typedef struct item{
    int id;             //4     4
    char stamp[11];     //12    16
    unsigned info_len;  //4     24
    char *info;         //      32
} Item;

typedef struct  collection {
    unsigned num_items;
    Item items[32];
} Collection;

unsigned get_item(Collection *collection, unsigned index, char **info){
    if(index >= collection->num_items)
        return -1;
    *info = collection->items[index].info;
    return collection->items[index].info_len;
}

int main(){

}