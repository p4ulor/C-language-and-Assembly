.text
.global get_val_ptr

# rdi -> items
# rsi -> item_idx
# rdx -> data_idx
# rcx -> val_idx
# r8 -> mask
# r9 -> items[item_idx]

get_val_ptr:
    push    %r10
    push    %r11

    mov     (%rdi, %rsi, 8), %r9
    mov     $2, %r10
    mov     (%r9, %r10, 8), %r10
    cmp     $0, (%r10)
    je      if_2

    mov     8(%r9, %rdx, 8), %r10
    mov     4(%r10), %r11
    cmp     (%r11), %rcx
    jae     if_2

    and     (%r10), %r8
    cmp     $0, %r8
    je      if_2

    mov     8(%r10, %rcx, 8), %rax
    pop     %r11
    pop     %r10
    ret
if_2:
    mov     $0, %rax
    pop     %r11
    pop     %r10
    ret