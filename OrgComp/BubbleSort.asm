	.data				# diretiva p/ in?cio do seg de dados
	num: .word  7, 5, 2, 1, 1, 3, 4
	#aux: $t0 
	#max: $t1
	#i: $t2
	#j: $t3
	#address: $t4
	#s0 eh o comeco do vetor num
	#$t5 e $t6 vao ser o num[j-1] e o num[j] respectivamente
	#$t7 registrador auxiliar
	 
	.align 2			#align 2 para salvar os 4 bytes do int
	.text 				# diretiva p/ in?cio do segmento de texto
	.globl main			# diretiva p/ usar rotulo em outro prog.
	
main:
	addi $t1, $zero, 7	#seta o max para 7
	la $t4, num		#armazena o endereco do comeco do vetor
	move $s0, $t4	#salva o comeco do endereco permanetemente
	addi $t2, $t2, -1	#seta o i para -1, pois o i++ do for ira acontecer no comeco da iteracao devido a logica do bubble sort usar o valor de i durante a execucao

forI:
	addi $t7, $t1, -1	#faz o $t7 = max-1 para poder comparar depois
	addi $t2, $t2, 1		#i++, para saber quantas iteracoes tiveram 
	beq $t2, $t7, endFor	#compara o i com o max-1, se for maior significa que rodou o vetor inteiro e acaba o for

	move $t3, $t1	#seta o j para max, pela mesma logica do i, tem que comecar em 1 a mais e nao em max-1
	move $t4, $s0	#reseta o endereco do vetor para o comeco
	addi $t4, $t4, 24	#seta o address pro ultimo inteiro
	
forJ:	
	addi $t7, $t2, 1	#faz o $t7 = i + 1 para poder comparar depois
	beq $t3, $t2, forI	#se o forJ tiver chegado no criterio de parada, compara j com i
	lw $t5, -4 ($t4)	#pega o conteudo do vetor na pos anterior (num[j-1])
	lw $t6,	0 ($t4) 		#pega o conteudo do vetor na pos depois (num[j])
	ble $t5, $t6, endIf		#se num[j-1] <= num[j] entao nao precisa rodar o if

if:	
	sw  $t6, -4 ($t4)		#armazena em num[j-1] o valor de num[j]
	sw $t5, 0 ($t4)		#armazena em num[j] o valor de num[j-1]

endIf:
	addi $t3, $t3, -1		#j--, para saber quantas iteracoes tiveram
	addi $t4, $t4, -4	#diminui o address em 1 int para dar match no j
	j forJ			#volta pro comeco do loop apos o termino da iteracao

endFor:
	move $t2, $zero		#seta o i para sero
	
lastFor:
	beq $t2, $t1, endLastFor	#criterio de parada do ultimo for, comparando i com max
	li $v0, 1			#$v0 = 1 para printar int
	move $a0, $t0			#t0 = numero inicial o qual quer saber o fatorial, foi para a0 para ser printado
	syscall
	addi $t2, $t2, 1		#i++
	j lastFor

endLastFor: