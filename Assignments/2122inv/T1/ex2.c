#include<stdio.h>

int get_max_index(int array[], size_t array_size, int *index_ptr){
    int val = array[--array_size];
    *index_ptr = array_size;
    int x;
    while(array_size>0){
        x = array[--array_size]; //cuts 1 process of array indexing at the cost of a variable (int x)
        if(x > val) {
            val = x;
            *index_ptr = array_size;
        }
    }
    
    return val;
}

int main(){
    int array1[5] = {59, 120, 34, 109, 12}; //max->120, idx->1
    int index;
    int max = get_max_index(array1, 5, &index);
    printf("1 -> %d, index -> %d\n", max, index); //we can't put the method call inside printf or the index will always be 0

    int array2[5] = {-3, -138, -34, -21, -4}; //max->-3, idx->0
    max = get_max_index(array2, 5, &index);
    printf("2 -> %d, index -> %d\n", max , index);

    int array3[5] = {1, 1, 4, 4, 912}; //max->912, idx->4
    max = get_max_index(array3, 5, &index);
    printf("3 -> %d, index -> %d\n", max, index);

    int array4[5] = {20000, 1, 32, 2, 4}; //max->20000, idx->0
    max = get_max_index(array4, 5, &index);
    printf("4 -> %d, index -> %d\n", max, index);

    int array5[5] = {3, 0, 123, 21, 4}; //max-> 123, idx->2
    max = get_max_index(array5, 5, &index);
    printf("5 -> %d, index -> %d\n", max, index);

    return 0;
}