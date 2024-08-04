/*
int string_len(char *str) {
eax		rdi
	int len = 0;
		eax
	while (str[len] != 0)
		len++;
	return len;
}
*/
; comment
# comment
	.text
	.global string_len

string_len:
	mov	$0, %eax
while:
	mov	(%rdi, %rax, 1), %cl
	cmp	$0, %cl
	jz	while_end
	inc	%eax
	jmp	while
while_end:
	ret
