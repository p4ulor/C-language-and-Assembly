.text
.global readchar

# rdi -> stream
# rsi -> offset
# rdx -> datap
# rcx -> offset_end
# r8 -> offset_begin
# r9 -> i


readchar:
    mov     $0, %rcx
    mov     $0, %r9

for_cond:
    cmp     (%rdi), %r9
    jae     return

for:
    mov     %rcx, %r8
    mov     8(%rdi, %r9, 8), %r10
    add     (%r10), %rcx

if_cond:
    cmp     %rcx, %rsi
    jae     for_end

    mov     8(%rdi, %r9, 8), %r10
    sub     %rsi, %r8
    mov     8(%r10, %r8), %r10
    lea     (%rdx), %r10 # movb	%al, (%rdx)
    mov     $1, %rax
    ret

for_end:
    inc     %r9
    jmp     for_cond
     
return:
    mov     $0, %rax
    ret