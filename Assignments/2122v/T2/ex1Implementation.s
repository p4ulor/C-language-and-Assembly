	.file	"ex1Implementation.c"
	.text
	.section	.rodata
.LC0:
	.string	"Current index: %d. "
.LC1:
	.string	"Bit: %ld. "
.LC2:
	.string	"Result: %ld\n"
	.text
	.globl	reverse
	.type	reverse, @function
reverse:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	$0, -24(%rbp)
	movb	$0, -26(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
.L4:
	shrq	-16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L9
	movzbl	-26(%rbp), %eax
	addl	$1, %eax
	movb	%al, -26(%rbp)
	jmp	.L4
.L9:
	nop
	movzbl	-26(%rbp), %eax
	movb	%al, -25(%rbp)
	jmp	.L5
.L6:
	movsbl	-26(%rbp), %eax
	movl	%eax, %esi
			.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movsbl	-26(%rbp), %eax
	movq	-40(%rbp), %rdx
	movl	%eax, %ecx
	shrq	%cl, %rdx
	movq	%rdx, %rax
	movq	%rax, -8(%rbp)
	andq	$1, -8(%rbp)
	movsbl	-25(%rbp), %edx
	movsbl	-26(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %ecx
	salq	%cl, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	orq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movzbl	-26(%rbp), %eax
	subl	$1, %eax
	movb	%al, -26(%rbp)
.L5:
	cmpb	$-1, -26(%rbp)
	jne	.L6
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	reverse, .-reverse
	.section	.rodata
.LC3:
	.string	"%d -> %lu\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$197, %edi
	call	reverse
	movq	%rax, %rdx
	movl	$197, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2, %edi
	call	reverse
	movq	%rax, %rdx
	movl	$2, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$5, %edi
	call	reverse
	movq	%rax, %rdx
	movl	$5, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
