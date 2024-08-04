	.file	"ex3.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.1) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu ex3.c -mtune=generic
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
	.globl	get_val_ptr
	.type	get_val_ptr, @function
get_val_ptr:
.LFB36:
	.cfi_startproc
	endbr64	
# ex3.c:12:     return (items[item_idx].valid && val_idx < items[item_idx].data[data_idx]->length) 
	leaq	(%rsi,%rsi,8), %rax	#, tmp103
	salq	$4, %rax	#, tmp104
	addq	%rax, %rdi	# tmp104, _2
# ex3.c:15:                 : NULL;
	cmpl	$0, 136(%rdi)	#, _2->valid
	je	.L3	#,
# ex3.c:12:     return (items[item_idx].valid && val_idx < items[item_idx].data[data_idx]->length) 
	movq	8(%rdi,%rdx,8), %rdx	# _2->data, _4
# ex3.c:12:     return (items[item_idx].valid && val_idx < items[item_idx].data[data_idx]->length) 
	movzwl	(%rdx), %eax	# *_4, tmp108
	sar		$6, %ax	#, tmp108
	movswq	%ax, %rax	# tmp108, _6
# ex3.c:12:     return (items[item_idx].valid && val_idx < items[item_idx].data[data_idx]->length) 
	cmpq	%rcx, %rax	# val_idx, _6
	jbe	.L4	#,
# ex3.c:13:                     && (items[item_idx].data[data_idx]->flags & mask) 
	movzbl	(%rdx), %eax	# *_4, tmp122
	sall	$2, %eax	#, tmp112
	sarb	$2, %al	#, tmp113
	movsbl	%al, %eax	# tmp113, _8
# ex3.c:13:                     && (items[item_idx].data[data_idx]->flags & mask) 
	movswl	%r8w, %r8d	# mask, mask
# ex3.c:13:                     && (items[item_idx].data[data_idx]->flags & mask) 
	testl	%eax, %r8d	# _8, mask
	je	.L5	#,
# ex3.c:14:             ? &(items[item_idx].data[data_idx]->vals[val_idx])
	addq	%rcx, %rcx	# _12
# ex3.c:15:                 : NULL;
	movq	%rcx, %rax	# _12, _12
	addq	8(%rdx), %rax	# _4->vals, _12
	ret	
.L3:
	movl	$0, %eax	#, <retval>
	ret	
.L4:
	movl	$0, %eax	#, <retval>
	ret	
.L5:
	movl	$0, %eax	#, <retval>
# ex3.c:16: }
	ret	
