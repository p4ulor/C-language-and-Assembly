

push 8
push 4
push 3

pop rax
call _printRAXDigit
pop rax
call _printRAXDigit
pop rax
call _printRAXDigit
ret

_printRAXDigit
    add rax, 48
    mov [digit], al
    mov rax, 1
    mov rdi, 1
    mov rsi, digit
    mov rdx, 2
    syscall
    ret