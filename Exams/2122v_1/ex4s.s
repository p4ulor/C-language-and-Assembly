.text
.global get_item

# rdi -> collection
# rsi -> index
# rdx -> info

get_item:
    cmp     (%rdi), %rsi            # %edi
    jb      info
    mov     $-1, %rax               # nao sei representar -1
    ret

info:
    mov     8(%rdi, %rsi), %r8
    mov     $20, %r9                # ou fazer shl
    mov     (%r8, %r9), (%rdx)
    mov     $2, %r9                 # ou fazer shl
    mov     (%r8, %r9, 8), %rax
    ret