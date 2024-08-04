.text
.global find_first

# RDI -> ic
# RSI -> key
# RDX -> i
# R8 -> ic->items[0]

find_first:
    mov     $0, %rdx
    mov     (%rdi), %r9
    mov     $0, %rcx
    mov     $0, %rax

for_cond:
    cmp     %r9, %rdx
    jae     return

for:
    mov     8(%rdi, %rdx, 8), %rcx
    cmp     %esi, (%rcx)
    jne     incr
    lea     4(%rcx), %rax
    ret

incr:
    inc     %rdx
    jmp     for_cond

return:
    ret
    
    