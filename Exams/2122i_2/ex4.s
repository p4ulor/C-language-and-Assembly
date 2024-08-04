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
	.globl	merge_sorted_lists
	.type	merge_sorted_lists, @function
merge_sorted_lists:
.LFB36:
	.cfi_startproc
	endbr64	
	pushq	%r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rsi, %rbx	# tmp97, list_b
# ex4.c:9:     if (list_a == NULL)
	testq	%rdi, %rdi	# list_a
	je	.L4	#,
	movq	%rdi, %rbp	# tmp96, list_a
	movq	%rdx, %r12	# tmp98, comparator
# ex4.c:11:     else if (list_b == NULL)
	testq	%rsi, %rsi	# list_b
	je	.L5	#,
# ex4.c:14:     if (comparator(list_a->data, list_b->data) <= 0) {
	movq	8(%rsi), %rsi	# list_b_11(D)->data, list_b_11(D)->data
	movq	8(%rdi), %rdi	# list_a_10(D)->data, list_a_10(D)->data
	call	*%rdx	# comparator
# ex4.c:14:     if (comparator(list_a->data, list_b->data) <= 0) {
	testl	%eax, %eax	# tmp99
	jle	.L7	#,
# ex4.c:19:         result->next = merge_sorted_lists(list_a, list_b->next, comparator);
	movq	(%rbx), %rsi	# list_b_11(D)->next, _6
# ex4.c:19:         result->next = merge_sorted_lists(list_a, list_b->next, comparator);
	movq	%r12, %rdx	# comparator,
	movq	%rbp, %rdi	# list_a,
	call	merge_sorted_lists	#
# ex4.c:19:         result->next = merge_sorted_lists(list_a, list_b->next, comparator);
	movq	%rax, (%rbx)	# tmp101, list_b_11(D)->next
# ex4.c:18:         result = list_b;
	movq	%rbx, %rax	# list_b, <retval>
.L1:
# ex4.c:22: }
	popq	%rbx	#
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp	#
	.cfi_def_cfa_offset 16
	popq	%r12	#
	.cfi_def_cfa_offset 8
	ret	
.L7:
	.cfi_restore_state
# ex4.c:16:         result->next = merge_sorted_lists(list_a->next, list_b, comparator);
	movq	0(%rbp), %rdi	# list_a_10(D)->next, _4
# ex4.c:16:         result->next = merge_sorted_lists(list_a->next, list_b, comparator);
	movq	%r12, %rdx	# comparator,
	movq	%rbx, %rsi	# list_b,
	call	merge_sorted_lists	#
# ex4.c:16:         result->next = merge_sorted_lists(list_a->next, list_b, comparator);
	movq	%rax, 0(%rbp)	# tmp100, list_a_10(D)->next
# ex4.c:15:         result = list_a;
	movq	%rbp, %rax	# list_a, <retval>
	jmp	.L1	#
.L4:
# ex4.c:10:         return list_b;
	movq	%rsi, %rax	# list_b, <retval>
	jmp	.L1	#
.L5:
# ex4.c:12:         return list_a;
	movq	%rdi, %rax	# list_a, <retval>
	jmp	.L1	#

