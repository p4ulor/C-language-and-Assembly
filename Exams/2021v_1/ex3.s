length = 0
items = 8
label = 4
NULL = 0

find_first: # ItemColl *ic, int key
	mov $0, %rdx

	for:
	cmp %rdx,length[%rdi]
	jbe for_end
	mov item[%rdi,%rdx,8], %rax
	cmp key[%rax],%rsi
	jne ifend 
	lea label[%rax], %rax
	ret

if_end:
	inc %rdx
	jmp for

for_end:
	mov $NULL, %rax
	ret 