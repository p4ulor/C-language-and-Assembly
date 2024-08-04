    .global my_strlen
# A Unicode character in UTF-8 encoding is between 8 bits (1 byte) and 32 bits (4 bytes) 
# https://stackoverflow.com/questions/22520413/c-strlen-implementation-in-one-line-of-code

#                                         rdi           
my_strlen: # size_t my_strlen(const char *str);
    mov $0, %rax # the "return register"
for:
    cmpb $0, (%rdi, %rax) # must have 'b' at the end so that it compares only the least significant 8 bits. 0 - str[rax] will equal zero when it reaches the string terminator \0
    jz for_end # jump if zero flag is 1 (true)
    add $1, %rax 
    jmp for
for_end:
    ret
