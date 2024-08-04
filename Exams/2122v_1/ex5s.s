.text
.global bubble_sort

# rdi/r10 -> base
# rsi -> num_elems
# rdx -> elem_width
# rcx -> cmp
# r8 -> i
# r9 -> p
# r11 -> j

bubble_sort:
    push    %r10    
    push    %r11
    push    %r12

    dec     %rsi
    mov     %rdi, %r10
    mov     %rsi, %r8

for_cond1:
    cmp     $1, %r8
    jb      return 

    mov     %r10, %r9       #nao sei fazer cast
    mov     $0, %r11
for_cond2:
    cmp     %r8, %r11
    jae     for_dec

    mov     %r9, %rdi
    mov     (%r9, %rdx), %rsi  # ver se faz a soma
    call    *%rcx

    cmp     $0, %eax
    jbe     if_end
    call    swap

if_end:
    add     %rdx, %r9
    jmp     for_cond2

for_dec:
    dec     %r8
    jmp     for_cond1

return:
    pop     %r12
    pop     %r11
    pop     %r10
    ret