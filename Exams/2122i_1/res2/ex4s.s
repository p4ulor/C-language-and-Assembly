.text
.global list_search

# rdi -> list 
# rsi -> data
# rdx -> fcmp
# rcx -> p

list_search:
    mov     %rdi, %rcx # List_node *p = list

for_cond:
    cmp     $0, %rcx
    je      return

    mov     8(rcx), %rdi
    call    *%rdx
    cmp     $0, %rax
    jne     for_end
    mov     %rcx, %rax
    ret

for_end:
    mov     (%rcx), %rcx
    jmp     for_cond

return: 
    mov     $0, %rax
    ret