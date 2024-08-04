Subtraçoes de stack pointer devem ser multiplas de 8

stack pointer começa no topo, e vai-se alocando espaço para baixo

add %rax, %rcx, %rdx # nao existe
mas com o lea, pode dar:
lea (%rax, %rcx), %rdx # assim
lea (%rax, %rcx, 8), %rdx # rdx -> rax + (rcx *8)

push e pop, so faz push e pop de secçoes/barras de de 64 bits, o que pode levar a desperdiço/nao utilizaçao de memoria

enquanto que usando o stack pointer, acedesse às variaveis de uma forma mais constante/fixa e controlada

parametros mais à direita, ficam no topo do stack