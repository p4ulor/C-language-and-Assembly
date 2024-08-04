	.file	"ex2Implementation.c"
	.text
	.globl	mymemmove
	.type	mymemmove, @function
mymemmove:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	cmpq	-32(%rbp), %rax
	je	.L2
	cmpq	$0, -40(%rbp)
	jne	.L3
.L2:
	movq	-24(%rbp), %rax
	jmp	.L4
.L3:
	movq	-32(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L5
.L6:
	movq	-16(%rbp), %rdx
	leaq	1(%rdx), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	leaq	1(%rax), %rcx
	movq	%rcx, -8(%rbp)
	movzbl	(%rdx), %edx
	movb	%dl, (%rax)
.L5:
	movq	-40(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, -40(%rbp)
	testq	%rax, %rax
	jne	.L6
	movq	-24(%rbp), %rax
.L4:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	mymemmove, .-mymemmove
	.section	.rodata
.LC0:
	.string	"ay1"
.LC1:
	.string	"ay2"
	.text
	.globl	ayay
	.type	ayay, @function
ayay:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC0(%rip), %rax
	movq	%rax, -16(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-16(%rbp), %rax
	movb	%dl, (%rax)
	addq	$1, -16(%rbp)
	addq	$1, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	ayay, .-ayay
	.section	.rodata
.LC2:
	.string	"%ld\n"
.LC3:
	.string	"Olaola"
.LC4:
	.string	"Adeus"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	subq	$176, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$1868655695, -133(%rbp)
	movw	$24940, -129(%rbp)
	movb	$0, -127(%rbp)
	movl	$1969579073, -157(%rbp)
	movw	$115, -153(%rbp)
	leaq	-133(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-157(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	-133(%rbp), %rsi
	leaq	-157(%rbp), %r8
	andb	$-1, %ah
	movl	%eax, %edx
	testl	%edx, %edx
	je	.L10
	movl	$0, %eax
.L9:
	movl	%eax, %ecx
	movzbl	(%r8,%rcx), %edi
	movb	%dil, (%rsi,%rcx)
	addl	$1, %eax
	cmpl	%edx, %eax
	jb	.L9
.L10:
	leaq	-133(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1868655695, -126(%rbp)
	movw	$24940, -122(%rbp)
	movb	$0, -120(%rbp)
	movl	$1969579073, -151(%rbp)
	movw	$115, -147(%rbp)
	leaq	-151(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	1(%rax), %rcx
	leaq	-126(%rbp), %rdx
	leaq	-151(%rbp), %rax
	movq	%rdx, %rdi
	movq	%rcx, %rdx
	movq	%rax, %rsi
	call	memcpy@PLT
	leaq	-126(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, -192(%rbp)
	leaq	.LC4(%rip), %rax
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	10(%rax), %rcx
	leaq	-192(%rbp), %rdx
	leaq	-184(%rbp), %rax
	movq	%rdx, %rdi
	movq	%rcx, %rdx
	movq	%rax, %rsi
	call	memcpy@PLT
	movq	-192(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1868655695, -119(%rbp)
	movw	$24940, -115(%rbp)
	movb	$0, -113(%rbp)
	movabsq	$8319119876411450433, %r14
	movabsq	$32496562017104755, %r15
	movq	%r14, -80(%rbp)
	movq	%r15, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	1(%rax), %rcx
	leaq	-119(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rdi
	movq	%rcx, %rdx
	movq	%rax, %rsi
	call	memcpy@PLT
	leaq	-119(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movabsq	$2338328558677552469, %rax
	movabsq	$7022643578143076980, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$544174708, -32(%rbp)
	movb	$0, -28(%rbp)
	movabsq	$7310222282934085987, %rax
	movq	%rax, -91(%rbp)
	movw	$29545, -83(%rbp)
	movb	$0, -81(%rbp)
	movl	$1868655695, -112(%rbp)
	movw	$24940, -108(%rbp)
	movb	$0, -106(%rbp)
	movl	$1969579073, -145(%rbp)
	movw	$115, -141(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-145(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rdx
	leaq	-145(%rbp), %rcx
	leaq	-112(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	mymemmove
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1868655695, -105(%rbp)
	movw	$24940, -101(%rbp)
	movb	$0, -99(%rbp)
	movl	$1969579073, -139(%rbp)
	movw	$115, -135(%rbp)
	leaq	-139(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	1(%rax), %rdx
	leaq	-139(%rbp), %rcx
	leaq	-105(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	mymemmove
	leaq	-105(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, -176(%rbp)
	leaq	.LC4(%rip), %rax
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	10(%rax), %rdx
	leaq	-168(%rbp), %rcx
	leaq	-176(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	mymemmove
	movq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1868655695, -98(%rbp)
	movw	$24940, -94(%rbp)
	movb	$0, -92(%rbp)
	movq	%r14, -64(%rbp)
	movq	%r15, -56(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	1(%rax), %rdx
	leaq	-64(%rbp), %rcx
	leaq	-98(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	mymemmove
	leaq	-98(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	movq	-24(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	addq	$176, %rsp
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
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
