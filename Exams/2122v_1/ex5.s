	.file	"ex5.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.1) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu ex5.c -mtune=generic
# -march=x86-64 -Og -fverbose-asm -fasynchronous-unwind-tables
# -fstack-protector-strong -Wformat -Wformat-security
# -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec
# -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
# -fdefer-pop -fdelete-null-pointer-checks -fdwarf2-cfi-asm
# -fearly-inlining -feliminate-unused-debug-types -fforward-propagate
# -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm -fgnu-runtime
# -fgnu-unique -fguess-branch-probability -fident -finline -finline-atomics
# -fipa-profile -fipa-pure-const -fipa-reference
# -fipa-reference-addressable -fipa-stack-alignment -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-constants
# -fmerge-debug-strings -fomit-frame-pointer -fpeephole -fplt
# -fprefetch-loop-arrays -freg-struct-return -freorder-blocks
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop
# -fstack-clash-protection -fstack-protector-strong -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftoplevel-reorder
# -ftrapping-math -ftree-builtin-call-dce -ftree-ccp -ftree-ch
# -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim -ftree-dce
# -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr -ftree-ter
# -funit-at-a-time -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.globl	cmp
	.type	cmp, @function
bubble_sort:
.LFB36:
	.cfi_startproc
	endbr64	
	pushq	%r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 64
	movq	%rdi, %r15	# tmp90, base
	movq	%rdx, %r14	# tmp92, elem_width
	movq	%rcx, %r13	# tmp93, cmp
# ex5.c:9:   for(size_t i = num_elems - 1; i>=1;i--){
	lea 	-1(%rsi), %r12	#, i
# ex5.c:9:   for(size_t i = num_elems - 1; i>=1;i--){
	jmp	.L6	#
.L7:
# ex5.c:12:       if(cmp(p,  p+elem_width) > 0)
	leaq	(%rdi,%r14), %rbp	#, _1
# ex5.c:12:       if(cmp(p,  p+elem_width) > 0)
	movq	%rbp, %rsi	# _1,
	call	*%r13	# cmp
# ex5.c:11:     for(size_t j = 0; j< i; j++) {
	addq	$1, %rbx	#, j
# ex5.c:14:         p+=elem_width;
	movq	%rbp, %rdi	# _1, p
.L8:
# ex5.c:11:     for(size_t j = 0; j< i; j++) {
	cmpq	%rbx, %r12	# j, i
	ja	.L7	# ,
# ex5.c:9:   for(size_t i = num_elems - 1; i>=1;i--){
	subq	$1, %r12	#, i
.L6:
# ex5.c:9:   for(size_t i = num_elems - 1; i>=1;i--){
	testq	%r12, %r12	# i
	je	.L11	#,
# ex5.c:10:     char *p = (char *)base;
	movq	%r15, %rdi	# base, p
# ex5.c:11:     for(size_t j = 0; j< i; j++) {
	movl	$0, %ebx	#, j
	jmp	.L8	#
.L11:
# ex5.c:17: }
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 56
	popq	%rbx	#
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE36:
	.size	bubble_sort, .-bubble_sort
	.globl	swap
	.type	swap, @function