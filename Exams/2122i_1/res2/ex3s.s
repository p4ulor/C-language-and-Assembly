.text
.global get_pincfg

# rdi -> config
# rsi -> state
# rdx -> pin

get_pincfg:
    mov     8(%rdi, %rsi, 8), %rcx
    mov     (%rcx, %rdx, 8), %r8
    