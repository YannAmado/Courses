	.data				# diretiva p/ inicio do seg de dados
	.align 0			# alinha a memoria em 2^0, ou seja, 1 byte
	msgEntrada:	.asciiz "Digite o numero para calcular o fatorial: "	# declaracao de uma string
	msgSaida1: .asciiz "O fatorial de "
	msgSaida2: .asciiz " eh: "

	.align 2			#align 2 para salvar os 4 bytes do int
	.text 				# diretiva p/ inicio do segmento de texto
	.globl main			# diretiva p/ usar rotulo em outro prog.

main:					# r?tulo para ponto de entrada no processo
	li $v0, 4			# $v0 = 4 c?d. para print_str
	la $a0, msgEntrada			# $a0 = endereco da string
	syscall				# chamada de sistema
	

	li $v0, 5			#$v0 = 5 para read_int
	syscall
	move $t0, $v0			#armazena o numero em t0
	move $t1, $t0			#t1 vai servir como o counter, comeca com o valor inicial do numero
	li $t2, 1			#$t2 vai servir para armazenar o valor total, comeca com 1 porque fatorial comeca com 1
	
startLoop:
		beq $t1, 0, endLoop	#if counter == 0, va para endLoop
		mul $t2, $t2, $t1		#t2*t1
		addi $t1, $t1, -1	#counter--
		j startLoop
	
	
endLoop:

	li $v0, 4
	la $a0, msgSaida1		#printa a mensgem "O fatorial de "
	syscall

	li $v0, 1			#$v0 = 1 para printar int
	move $a0, $t0			#t0 = numero inicial o qual quer saber o fatorial, foi para a0 para ser printado
	syscall
	
	li $v0, 4
	la $a0, msgSaida2		#printa a mensgem "eh "
	syscall
	
	li $v0, 1			#$v0 = 1 para printar int
	move $a0, $t2			#t2 = numero do fatorial, foi para a0 para ser printado
	syscall
	
	li $v0, 10			# $ v0 = 10 c?d para exit
	syscall				# chamada de sistema. Fim do prog.
