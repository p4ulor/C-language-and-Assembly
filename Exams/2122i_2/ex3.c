#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


typedef struct data { short flags:6; short length:10; short *vals; } Data;
typedef struct info { double ref; Data *data[16]; int valid; } Info;

short *get_val_ptr(Info items[], size_t item_idx,
                    size_t data_idx, size_t val_idx, short mask) {
    return (items[item_idx].valid && val_idx < items[item_idx].data[data_idx]->length) 
                    && (items[item_idx].data[data_idx]->flags & mask) 
            ? &(items[item_idx].data[data_idx]->vals[val_idx])
                : NULL;
}


int main(){
    printf("%ld", sizeof (struct data));
}