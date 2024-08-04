for_each:
	push %r12
	push %r13
	push %r14
	push %r15
	push %rbx
	push %rbp
	mov %rdi, %r12
	mov %rsi, %r13
	mov %rdx, %r14
	mov %rcx, %r15
	mov %r8, %rbx
	mov $0,%rbp
	cmp %rbp, %r14
	jbe for_end
	mov %rbp, %rax
	mul %r14
	lea [%rax, %r12], %rdi
	mov %rbx, %rsi
	call *%r15
	inc %rbp


for_end:	
	pop %rbp
	pop %rbx
	pop %r15
	pop %r14
	pop %r13
	pop %r12
	ret