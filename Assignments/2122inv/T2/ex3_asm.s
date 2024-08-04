.equ NULL, 0
.equ calendar, 8
.equ lenght, 0
.equ events, 8

get appointment: # rdi->agenda, rsi->month, rdx->day, rcx->index
	shl $8, %rsi # rsi -> mounth*256
	lea calendar(%rdi, rsi), %rax # (escalar_calendar)agenda+month  -> rax = valor do ponteiro para o inicio do calendar (agenda[month].calendar)
	mov (%rax, %rdx, 8), %rax  # rax -> agenda[month].calendar[day], rax+(rdx*8)
	cmp %NULL, %rax            # if(agenda[month].calendar[day] != NULL)
	jz return_null

	# && index < agenda[month].calendar[day]->length
	cmp lenght(%rax), %rcx
	jnb return_null 

	mov events(%rax), %rax
	shl $4, %rcx # scales index to proper positioning
	lea (%rax, %rcx), %rax
	jmp ret

	
return_null:
	mov $NULL, %rax
	ret