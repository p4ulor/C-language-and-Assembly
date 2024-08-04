int check_for_pattern(int value, int pattern){
    while(!pattern&1){ //skip zero bits como diz no enunciado
        pattern >>=1;
    }
    int val = pattern;
    int digitsInPattern = 1;
    while(val){
        digitsInPattern = digitsInPattern << 1;
        val--;
    }
    while(value){
        if((value & digitsInPattern) ^ pattern ==0) return 1;
        value = value >> 1;
    }
    return 0;
}

//prof

int check_for_pattern(int value, int pattern){
    if(value==0 || pattern==0) return 0;
    while(!pattern&1){
        pattern >>=1;
    }
    int i;
    for(i=0; pattern>0; ++i){
        pattern <<=1;
    }
    i = 32-i;
    int mask = (1 << i) -1;
    while(value > 0){
        if((value & mask)==pattern){
            return  1;
        }
    }
    return 0;
}


// Ex2
#include <string.h>
char * strtrim(char *str, const char *delim){
    for(; strchr(delim, *str)!=NULL; ++str);

    char* ptr = str;
    str += strlen(str)-1;
    for(; strchr(delim, *str)!=NULL; --str);

    *(str+1)=0;
    return ptr;
}


// 3
.equ NULL, 0
lenght = 0
items = 8
label = 4
find_first:
mov $0, %rdx
for:
cmp %rdx, lenght[%rdi]
jbe for_end
mov items[%rdi, %rdx, 8], %rax
cmp key[%rax], %esi
jne if_end
lea label[%rax], %rax

if_end:
    inc %rdx //inc i
    jmp for
for_end:
mov $NULL, %rcx
ret

//4
//a
for_each:
push %r12
push %r13
push %r14
push %r15
push %rbx
push %rbp

mov %rdi, %r12
mov %rdi, %r13
mov %rdx, %r14
mov %rcx, %r15
mov %r8, %rbx
mov %$0, %rbp

cmp %rbp, %r14
jbe for_end

mov %rbp, %rax
mul %r14
lea[%rax, %r12], %rdi
mov %rbx, %rsi
call * %r15 //* -> call-e indireto, sem
inc %rbp
for_end:
    pop %rbp
    pop %rbx
    pop %r15
    pop %r14
    pop %r13
    pop %r12
    ret

//b

struct word words[] = {
    {10, "aaa"},
    {100, "bbb"},
    {1000, "ccc"}
};

struct word * pword = words;

void do_it(void* a, void* b){
    struct word* p = (struct word*) a; 
    struct word** q = (struct word**) b;
    if(p->counter>(*q)->counter)
        *q = p;
}

int main(){
    foreach(&words[1], 3, sizeof words[0], do_it &pword);

    printf("word=%s\n", pword->word);
}

//5
//a
f1 
a C
b b
X T 
d U 
c U 
maint T 
y U 

f2 
a D 
b D 
d D 
c C 
y T 
x U

//b
o linker nao da erro pq nao tem informaçao de tipo
no momento de linkagem, o linker nao olha para os tipos, so olha para os nomes

//6        8
    |    _____ -> size=64
    |    _____
256 |
    |
    |
64*8*256

//7

NoteData * array_to_list_by_key(Data* data[], size_t lenght, int key){
    NodeData* previous = NULL;
    for(size i = 0; i<lenght, ++i){
        if(data[i]->key==key){
            size_t dsize = sizeof * date[i]+data[i]->length * sizeof(__UINT32_TYPE__)
            Data* d = malloc(dsize)
            memcpy(d, data[i])
            NodeData* node = malloc(sizeof *node);
            node->data = d;
            node->next=NULL;
            if(previous!=NULL)
                previous->next = node;
            previous = node
        }
    }
    return previous;
}

void_free_data_list(NodeData* data_list ){
    NodeData* next;
    for(NodeData* node = data_list; node!=NULL; node = next){
        next = node->next;
        free(node->data);
        free(node);
        
    }
}