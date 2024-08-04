.text
.global for_each

# rdi -> array
# rsi -> size
# rdx -> elem_size
# rcx -> do_it
# r8 -> context

for_each:
    push    %r15
    push    %r14

    mov     $0, %r9
    mov     %rdi, %r15
    mov     %rsi, % r14

for_cond:
    cmp     %rsi, %r9
    jae     return
for:
    mov     (rdi, rdx, %r9), %rdi
    mov     %r8, %rsi
    call    *%rcx
    inc     %r9
    jmp     for_cond
return:
    pop     %r14
    pop     %r15
    ret
