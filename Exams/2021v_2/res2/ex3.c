#include <stdio.h>
#include <string.h>

typedef struct buffer { size_t size; char *data; } Buffer;

typedef struct stream { size_t n_buffers; Buffer **buffers; } Stream;

char readchar(Stream *stream, size_t offset, char *datap){
    size_t offset_end = 0;
    for (size_t i = 0; i < stream->n_buffers; ++i) {
        size_t offset_begin = offset_end;
        offset_end += stream->buffers[i]->size;
        if (offset < offset_end) {
            *datap = stream->buffers[i]->data[offset - offset_begin];
            return 1;
        }
    }
    return 0;
}

int main(){

}