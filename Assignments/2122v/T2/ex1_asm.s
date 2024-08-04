    .global reverse

# 'q' is added to make some instructions work with 64bits    
#                                  rdi           
reverse: # uint64_t reverse(uint64_t val)                            
             
    movq $0, %rax  # uint64_t result = 0; (return value in return register)
    mov $0, %rsi  # char currentIndex = 0; (I'm using rsi to filter out higher bits (and avoid using movsbq afterwards to filter them) when I intend to perform shifts)
    mov %rdi, %rdx # uint64_t valCopy = val;

while:
    shrq $1, %rdx
    cmp $0, %rdx
    jz while_end
    add $1, %sil
    jmp while
while_end:

    mov %sil, %cl # char indexCount = currentIndex;

# In summary:
# rax = result, rsi/sil = currentIndex, rdx = "free" will be used for shifts, cl = indexCount
while2:
    cmp $-1, %sil    # while(currentIndex!=-1)
    jz while2_end

    movq %rdi, %rdx # "valueToShift" = val
    mov %rsi, %r9
shiftright:         # had to use loop because shrd %rsi, %rdx wasnt working properly
    cmp $0, %r9
    jz shiftright_end
    shr $1, %rdx    # "valueToShift" -> "shift result" = val >> currentIndex. I use %rsi and shrd because of registertype match
    dec %r9
    jmp shiftright
shiftright_end:
    movq %rdx, %r8  # r8 = bit = val >> currentIndex

    andq $1, %r8    # bit = bit & 0x1
    
    movsbq %cl, %rcx # Save indexCount
    push %rcx 

    sub %sil, %cl # "ammount to shift to" (indexCount) = indexCount-currentIndex
    shlq %cl, %r8 # bit = bit << "ammount to shift to"
    pop %rcx

    or %r8, %rax # result = result | bit;

    dec %sil     # currentIndex--
    jmp while2
while2_end:
    ret 
