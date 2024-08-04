	.file	"ex4.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.1) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu ex4.c -mtune=generic
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
	.globl	vector_conditional_insert
	.type	vector_conditional_insert, @function
vector_conditional_insert:
.LFB34:
	.cfi_startproc
	endbr64	
	pushq	%r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 48
	movq	%rdi, %rbx	# tmp93, vector
	movq	%rdx, %rbp	# tmp95, new
	movq	%rcx, %r12	# tmp96, compar
# ex4.c:6:     void **last = vector + size;
	leaq	(%rdi,%rsi,8), %r13	#, last
.L2:
# ex4.c:7:     for (void **current = vector ; current < last; current++)
	cmpq	%r13, %rbx	# last, vector
	jnb	.L1	#,
# ex4.c:8:         if ((*compar)(*current, new)) {
	movq	%rbp, %rsi	# new,
	movq	(%rbx), %rdi	# *current_7,
	call	*%r12	# compar
# ex4.c:8:         if ((*compar)(*current, new)) {
	testl	%eax, %eax	# tmp97
	jne	.L7	#,
# ex4.c:7:     for (void **current = vector ; current < last; current++)
	addq	$8, %rbx	#, vector
	jmp	.L2	#
.L7:
# ex4.c:9:             memmove(current + 1, current, (last - current) * sizeof *current);
	movq	%r13, %rdx	# last, last
	subq	%rbx, %rdx	# vector, last
# ex4.c:9:             memmove(current + 1, current, (last - current) * sizeof *current);
	leaq	8(%rbx), %rdi	#, _6
# /usr/include/x86_64-linux-gnu/bits/string_fortified.h:40:   return __builtin___memmove_chk (__dest, __src, __len, __bos0 (__dest));
	movq	%rbx, %rsi	# vector,
	call	memmove@PLT	#
# ex4.c:10:             *current = new;
	movq	%rbp, (%rbx)	# new, *current_7
.L1:
# ex4.c:13: }
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 40
	popq	%rbx	#
	.cfi_def_cfa_offset 32
	popq	%rbp	#
	.cfi_def_cfa_offset 24
	popq	%r12	#
	.cfi_def_cfa_offset 16
	popq	%r13	#
	.cfi_def_cfa_offset 8
	ret	
