    .global rotate_right
#                               rdi           rsi
rotate_right: # (unsigned long value[], size_t n)
    # The parameter 'value' (rdi) is a pointer to the array of values, so we need to extract them
    mov (%rdi), %r10       # least significant (63-0)
    mov 8(%rdi), %r11      # most significant (127-64), 8 is a displacement to access 64(8x1byte) bits ahead. 
for:                # shift n times
    test %rsi, %rsi # performs a bitwise AND and alters ZF (zero flag). Alternative: cmp $0, %rsi
    jz for_end      # jumps if ZF==0
    dec %rsi        # decrement n by 1.

    # clear whatever values there are in r8 and r9 registers
    mov $0, %r8 # Will be used to save carry of least significant
    mov $0, %r9 # Will be used to save carry of most significant


    # shift least significant part 
    shr $1, %r10
    jnc no_carry1   # \
    or $1, %r8      #  alternative, use setc %r8b
no_carry1:          # /
    ror $1, %r8     # Puts this bit in the leftmost position


    # shift most significant part 
    shr $1, %r11
    jnc no_carry2
    or $1, %r9
no_carry2:
    ror $1, %r9


    # Insert the carry in the respective part
    or %r8, %r11 # least significant carry goes to most significant part
    or %r9, %r10 # most significant carry goes to least significant part

    jmp for
for_end:
    movq %r10, (%rdi)
    movq %r11, 8(%rdi)
    ret
