    .global mymemmove

#                   rdi              rsi         rdx      
mymemmove: # (void *dst, const void *src, size_t len)
    cmp %rdi, %rsi
    jz return
    cmp $1, %rdx  # len-1, len<1 
    js return         # jump sign, jump if negative

    # use other vars in order to not alter what the argument pointers point to
    mov %rsi, %rcx # char* s
    mov %rdi, %r8 # char* d

while:
    cmp $0, %rdx
    jz return

    mov (%rcx), %r9b    # *s
    mov %r9b, (%r8)     # *d = *s

    inc %rcx
    inc %r8

    dec %rdx # --len 
    jmp while
return:
    ret
