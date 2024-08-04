.text
.global merge_sorted_lists

# rdi -> list_a
# rsi -> list_b
# rdx -> comparator
# rcx -> result

merge_sorted_lists:
    mov     %rdi, %r9
    mov     %rsi, %r8

    cmp     $0, %r9
    mov     %r8, %rax
    je      return

    cmp     $0, %r8
    mov     %r9, %rax
    je      return

    mov     8(%r9), %rdi
    mov     8(%r8), %rsi
    call    *%rdx
    cmp     $0, %rax
    jg      else

    mov     %r9, %rcx
    mov     (%r9), %rdi
    mov     %r8, %rsi
    call    merge_sorted_lists

    mov     %rax, (%rcx)

        mov     %r9, %rcx
    mov     (%r9), %rdi
    mov     %r8, %rsi
    call    merge_sorted_lists

    mov     %rax, (%rcx)


else:


return:

    ret
