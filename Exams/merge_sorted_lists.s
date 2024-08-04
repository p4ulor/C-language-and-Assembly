/*typedef struct node { struct node *next; void *data; } Node;
Node *merge_sorted_lists(Node *list_a, Node *list_b, int (*comparator)(void *, void *)) {
    if (list_a == NULL)
        return list_b;
    else if (list_b == NULL)
        return list_a;
    Node *result;
    if (comparator(list_a->data, list_b->data) <= 0) {
        result = list_a;
        result->next = merge_sorted_lists(list_a->next, list_b, comparator);
    } else {
        result = list_b;
        result->next = merge_sorted_lists(list_a, list_b->next, comparator);
    } return result;
}*/

    .text
    .global merge_sorted_lists
    
    .equ NULL, 0
    .equ next, 0
    .equ data, 8
    # Node *list_a -> rdi, Node *list_b ->rsi, int (*comparator)(void *, void *) -> rdx 
merge_sorted_lists:
    push    %r12
    push    %r13
    push    %r14
    push    %r15
    mov     %rdi, %r12 # r12 = list_a
    mov     %rsi, %r13 # r13 = list_b
    mov     %rdx, %r14 # r14 = compatator

    cmp     NULL, r12
    jne     a_not_null
    mov     %r13, %rax
    jmp     return
a_not_null:
    cmp     NULL, r13
    jne     b_not_null
    mov     %r12, %rax
    jmp    return
b_not_null:
    # r15 = result
    mov     data(%r12), %rdi
    mov     data(%r13), %rsi
    call    *%rdx
    cmp     NULL, %rax
    ja      if_end
    mov     %r12, %r15
    mov     next(%r12), %rdi
    mov     %r13, %rsi
    mov     %r14, %rdx
    call    merge_sorted_lists
    mov     %rax, next(%r15)
    jmp     success
if_end
    mov     %r13, %r15
    mov     %r12, %rdi
    mov     next(%r13), %rsi
    mov     %r14, %rdx
    call    merge_sorted_lists
    mov     %rax, next(%r15)
    jmp    success
success:
    mov     %r15, %rax
return:
    push %r15
    push %r14
    push %r13
    push %r12
    ret