.text
.global vector_conditional_insert

# rdi -> vector
# rsi -> size 
# rdx -> new
# rcx -> compar
# r8 -> current
# r9 -> last

vector_conditional_insert:
    push    %r10
    push    %r11

    mov     %rsi, %r9
    add     %rdi, %r9
    mov     %rdi, %r8
    
for_cond:
    cmp     %r9, %r8
    jae     return

if_cond:
    mov     %r8, %rdi
    mov     %rdx, %rsi
    call    *%rcx
    cmp     $1, %rax
    jne      for_end

    mov     $1, %r10
    add     %r8, %r10
    mov     %r10, %rdi
    mov     %r8, %rsi

    mov     %r9, %r11
    sub     %r8, %r11
    mov     %r11, %rdx
    # Complexo

for_end:
    inc     %r8
    jmp     for_cond

return:
    pop     %r11
    pop     %r10
    ret