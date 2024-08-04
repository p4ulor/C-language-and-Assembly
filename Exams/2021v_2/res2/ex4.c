#include <stdio.h>
#include <string.h>

void vector_conditional_insert(void **vector, size_t size, void *new,
                                            int (*compar)(const void *, const void *)) {
    void **last = vector + size;
    for (void **current = vector ; current < last; current++)
        if ((*compar)(*current, new)) {
            memmove(current + 1, current, (last - current) * sizeof *current);
            *current = new;
            return;
        }
}

int main(){

}