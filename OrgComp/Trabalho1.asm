.data

#mensagens a serem utilizadas
.align 0
mensagemBaseF:.asciiz"Digite a base do numero de entrada\n"
mensagemNum:.asciiz"\nDigite o número que deseja converter\n"
mensagemConv:.asciiz"Insira a base de conversão\n"
mensagemRes:.asciiz"\no número convertido "
mensagemErro:.asciiz "Número digitado não é válido\n"
mensagemRes3:.asciiz"é "
mensagemErroBaseInv:.asciiz "Base inserida é inválida, verifique se utilizou B, D ou H como bases"
#numero
OutNum:.space 34
VetAux:.space 34
InsertNum:.space 34

#bases de insercao e conversao
.align 2
DecimalWord: .word
vetorBinario: .word

.text
.globl main
main:
	#carrega os valores de D, B e H
	li $t1, 68
	li $t2, 66
	li $t3, 72
	#97 que é a primeira letra minuscula em ascii, vai servir depois para saber se eh letra maiuscula ou nao
	li $s3, 97
	
	#printa a mensagem que pede a primeira base
	li $v0, 4
	la $a0, mensagemBaseF
	syscall

	#le a primeira base como char
	li $v0, 12
	syscall
	
	#Base lida
	move $t0, $v0
	
	#verifica se a base eh minuscula
	jal VerificaBase
	
	#printa a mensagem que pede o primeiro numero
	li $v0, 4
	la $a0, mensagemNum
	syscall
	
	#comparacao das bases com D (decimal) B (binário) H (hexadecimal)
	beq $t0, $t1 LeIntDec
	beq $t0, $t2 LeStringBin
	beq $t0, $t3 LeStringHex
	j ErroBaseInvalida



LeIntDec:
	#ler valor a ser convertido em int
	li $v0, 5
	syscall 

	#mover valor para $s1
	move $s1, $v0
	
	#carrega os valores de D, B e H
	li $t1, 68
	li $t2, 66
	li $t3, 72
	#97 que é a primeira letra minuscula em ascii, vai servir depois para saber se eh letra maiuscula ou nao
	li $s3, 97
	
	#mensagem que pede pra digitar a 2 base
	li $v0, 4
	la $a0, mensagemConv
	syscall
	
	#leitura da base
	li $v0, 12
	syscall
	
	#mover para $t0
	move $t0, $v0
	
	jal VerificaBase
	
	beq $t0, $t1 PrintnEnd
	beq $t0, $t2 DecToBin
	beq $t0, $t3 DecToHex
	j ErroBaseInvalida
	
LeStringBin:
	
	#carrega os valores de D, B e H
	li $t1, 68
	li $t2, 66
	li $t3, 72
	#97 que é a primeira letra minuscula em ascii, vai servir depois para saber se eh letra maiuscula ou nao
	li $s3, 97
	
	#ler valor a ser convertido
	li $v0, 8
	la $a0, InsertNum
	la $a1, 34
	syscall
	
	j VerificaBin

LerBaseBin:

	li $v0, 4
	la $a0, mensagemConv
	syscall
	
	#leitura da base
	li $v0, 12
	syscall
	
	#mover para $t0
	move $t0, $v0
	
	jal VerificaBase
	
	beq $t0, $t1 BinToDec
	beq $t0, $t2 PrintStringnEnd
	beq $t0, $t3 BinToHex
	j ErroBaseInvalida


VerificaBin:
	
	#enderco do binario
	la $t5, InsertNum
	
	#valores 1 e 0
	li $t6, 48
	li $t7, 49
	li $s6, 10	
	
LoopVerificaBin:

	lb $t8, 0 ($t5)
	
	beq $t8, $s6, LerBaseBin
	blt $t8, $t6, Erro
	bgt $t8, $t7, Erro
	
	addiu $t5, $t5, 1
	j LoopVerificaBin

	
VerificaBase:
	bge $t0, $s3, BaseMaiuscula
	jr $ra
	
BaseMaiuscula:
	addiu $t0, $t0, -32
	jr $ra
			
LeStringHex:
	
	#carrega os valores de D, B e H e 97 que é a primeira letra minuscula em ascii
	li $t1, 68
	li $t2, 66
	li $t3, 72
	li $s3, 97
	
	#ler valor a ser convertido
	li $v0, 8
	la $a0, InsertNum
	la $a1, 34
	syscall
	
	li $v0, 4
	la $a0, mensagemConv
	syscall
	
	#leitura da base
	li $v0, 12
	syscall
	
	#mover para $t0
	move $t0, $v0
	
	jal VerificaBase
	
	beq $t0, $t1 HexToDec
	beq $t0, $t2 HexToBin
	beq $t0, $t3 PrintStringnEnd
	j ErroBaseInvalida
	

####################################################################  Dec To Hex  ###################################################################################
DecToHex:
	#carregar registrador $t0 com 16 para a divisão 
    	li $t0, 16
    
    	#carregar endereço do vetor1 em $t1
    	la $t1, OutNum
    
    	#carregar endereço do vetor1 em $t8
    	la $t8, VetAux
    
    	#carrega em $t9 o parametro para desvio
    	li $t9, 58
    
    	#$t5 será o contador
    	move $t5, $zero
    
    
    
    #Armazena Dec%16 em OutNum, convertendo ints ascii
    #$s1 =  valor Decimal
    #$t0 = base 16
    #$t1 = enderco de Recebe Mod16
    #$t8 = endereço VetAux
    #$t9 = parametro de desvio (verificar se eh maior que '9' ->58)
    #$t5 = contador
    CreateVetMod:
    
    	#condição de parada
    	beq $s1, $zero, endCreateVetMod
    
    	#divide $s1 por 16
    	divu $s1, $t0
    
    	#salvar inteiro em $s1 e resto em $t2
    	mflo $s1
    	mfhi $t2
    
    	#converter valor para representar o digito de acordo com a tabela ascii
    	addiu $t2, $t2, 48 
    
    	#se o valor do digito for menor que 10 desvia
    	blt $t2, $t9 , pulaDH
    	addiu $t2, $t2, 7
    pulaDH: 
    
    	#armazena t2 no OutNum
    	sb $t2, 0 ($t1)
    
    	#incrementa t1
    	addiu $t1, $t1, 1
    
    	#incrementa $t5
    	addiu $t5, $t5, 1
    
    	j CreateVetMod
    
    endCreateVetMod:
    
    	#se o contador for 0 imprime valor final como 0
    	beq $t5, $zero, PrintStringnEnd
    
    # Inverte o vetor OutNum($t1) armazenando ele no vetor VetAux($t8)
    #$t5 = contador/parametro do branch
    #recebe o valor da posicao de OutNum e armazena em VetAux
    InverteMods:
    
    	#anda com a posicao de t1
    	addiu $t1, $t1, -1
    
    	#decrementa o contador
    	addiu $t5, $t5, -1
    
    	#ve se o contador chegou em 0
    	blt $t5, $zero, PrintVetAuxnEnd
    
    	#pega o valor de $t4 (OutNum)
    	lb $t4, 0 ($t1)
    
    	#armazena em $t8(VetAux)
    	sb $t4, 0 ($t8)
    
    	#anda com a posicao de $t8
    	addiu $t8, $t8, 1
    
    
    	j InverteMods
    	
####################################################################  Dec To Bin  ###################################################################################
DecToBin:
	#carregar registrador $t0 com 2 para a divisão 
    	li $t0, 2
    
    	#carregar endereço em $t1
    	la $t1, vetorBinario
    
    	#$t5 será o contador
    	move $t5, $zero
    
    	#como na proxima label o resultado vai começar a ser impresso, as mensagens de resposta ja são impressas aqui
    	li $v0, 4
	la $a0, mensagemRes
	syscall

    	li $v0, 4
	la $a0, mensagemRes3
	syscall
    
    #divide o número decimal fornecido por 2 
    #o quociente se torna o novo decimal
    #o resto de cada divisão é armazenado no vetorBinario
    # e repete o processo até o quociente for 0
    #$s1 terá o decimal
    # $t0 será o divisor(2)
    #$t1 o endereço do vetorBinario
    #$t5 contará quantas vezes o processo foi realizado
    ConvertBinario:
    
    	#condicao para parada do loop -> desvia se o quociente em $s1 for igual a 0
    	beq $s1, $zero, endConvertBinario
    
    	# divide $s1 por 2
    	divu $s1, $t0
    
    	#salvar inteiro em $s1 e resto em $t2
    	mflo $s1
    	mfhi $t2
    
    	#armazena resto t2 no vetorBinario
    	sw $t2, 0 ($t1)
    
    	#incrementa posicao do vetorBinario em t1
    	addiu $t1, $t1, 4
    
    	#incrementa contador $t5
    	addiu $t5, $t5, 1
    
    	#retorna para o inicio do loop
    	j ConvertBinario
    
    #fim do loop 
    endConvertBinario:
    
    	#verificar se o contador for 0 -> se for o valor binario final será 0 e encerra o programa
    	beq $t5, $zero, zero
    
    #vetorBinario possui o número binário invertido	-> imprimir digitos do fim para o inicio
    # $t4 pega o valor no vetor e imprime	
    ImprimeBinario:
    
    	#anda com a posicao de t1
    	addiu $t1, $t1, -4
    
    	#decrementa contador
    	addiu $t5, $t5, -1
    
    	#condicao de parada -> contador atinge -1
    	blt $t5, $zero, endImprimeBinario
    
    	#acessa valor no vetorBinario
    	lw $t4, 0 ($t1)
    
    	#imprime valor
    	li $v0, 1
    	move $a0, $t4
    	syscall 
	
	#retorna para o inicio do loop
	j ImprimeBinario

    #fim do loop e encerre programa
    endImprimeBinario:

	    li $v0, 10
	    syscall
	    
    #move para o registrador padrão para a label de print 
    zero:
	    move $s1, $t5
            j PrintnEnd

####################################################################  Bin To Dec  ###################################################################################	
BinToDec:
	#$t2 será o contador
	move $t2, $zero
	
	#carregar endereço string
	la $t1, InsertNum
	
	#carregar 10 para o registrador $s0
	li $t3, 10	
	
	
	#Le o binario até encontrar o \n
	# $t1 = endereco da string inNumBin
	# t$2 = comeca com 0 e será o contador
	# $t3 = 10
	# $t4 = caracter atual da string

	# while (inNumBin[i] != '\n'){
	#	char = inNumBin[i]
	#	i++
	#}
	#
    loopToEnter:
    
    	#pegar char da string
    	lb $t4, 0($t1)
    
    	#Condicao de parada se t4 for igual a \n
    	beq $t4, $t3, endLoopToEnter
    
    	#somar 1 no reg $t1 para andar nas casas
    	addiu $t1, $t1, 1
    
    	#contador de casas
    	addiu $t2, $t2, 1
    
    	j loopToEnter
    
    
    endLoopToEnter:
    
    
    	#carregar registrador $t6 com 2 para a pontenciação
    	li $t6, 2
    
    	#responsavel por fazer o papel da "potencia" 
    	li $s0, 1
    
    	#Valor decimal
    	li $s1, 0
    
    	li $t3, -1
    
    
    #Loop de conversõ binário para decimal
    #t6 = 2 2^(posicao)
    #$s0 = 1 e vai sendo multiplicado por 2 ao
    #$t3 = -1 codicao de parada
    #$s1 = valor decimal
    # for (int i = strlen(nuBin); i > 0; i--) {
    #	aux = numBin[i];
    #	aux *= mult;
    #	mult *=2;
    #	total +=aux;
    #}
    loopBinToDec:
    
    	#Andar com o numero e o contador pra -1
    	addiu $t1, $t1, -1
    
    	addiu $t2, $t2, -1
    
    	#verifiva se ja estamos na posicao final
    	beq $t2, $t3 , PrintnEnd
    
    	#acessar caracter atual
    	lb $t4, 0($t1)
    
    	#conversão de número ascii pra numeros inteiros
    	addiu $t4, $t4, -48
    
    	#Char[posicao] * mult
    	mulu $t4, $s0, $t4
    
    	#mult aumenta a potencia (2*2)
    	#atualiza mult: mult *=2
    	mulu $s0, $t6, $s0
    
    	#Total = Total + (Char[posicao] * mult)
    	addu $s1, $s1, $t4
    
    	j loopBinToDec
    	

####################################################################  Bin To Hex  ###################################################################################  	
    	
BinToHex:
    #binario para decimal
    BinToDecBH:

    	#$t5 será o contador
    	move $t2, $zero
    
    	#carregar endereço string
    	la $t1, InsertNum
    
    	#carregar 10 para o registrador $s0
    	li $t3, 10	
    
    loopToEnterBH:

    	#pegar char da string
    	lb $t4, 0($t1)
    
    	#Condicao de parada se t4 for igual a \n
    	beq $t4, $t3, endLoopToEnterBH
    
    	#somar 1 no reg $t1 para andar nas casas
    	addiu $t1, $t1, 1
    
    	#contador de casas
    	addiu $t2, $t2, 1
    
    	j loopToEnterBH
    

    endLoopToEnterBH:


    	#carregar registrador $t6 com 2 para a pontenciação
    	li $t6, 2
    
    	#responsavel por fazer o papel da "potencia" 
    	li $s0, 1
    
    	#Valor decimal
    	li $s1, 0
    
    	li $t3, -1
    
    
    #Loop de conversõ binário para decimal
    #t6 = 2 2^(posicao)
    #$s0 = 1 e vai sendo multiplicado por 2 ao
    #$t3 = -1 codicao de parada
    #$s1 = valor decimal
    # for (int i = strlen(nuBin); i > 0; i--) {
    #	aux = numBin[i];
    #	aux *= mult;
    #	mult *=2;
    #	total +=aux;
    #}
    loopBinToDecBH:
    
    	#Andar com o numero e o contador pra -1
    	addiu $t1, $t1, -1
    
    	addiu $t2, $t2, -1
    
    	#verifiva se ja estamos na posicao final
    	beq $t2, $t3 , DecToHexBH
    
    	#acessar caracter atual
    	lb $t4, 0($t1)
    
    	#conversão de número ascii pra numeros inteiros
    	addiu $t4, $t4, -48
    
    	#Char[posicao] * mult
    	mulu $t4, $s0, $t4
    
    	#mult aumenta a potencia (2*2)
    	#atualiza mult: mult *=2
    	mulu $s0, $t6, $s0
    
    	#Total = Total + (Char[posicao] * mult)
    	addu $s1, $s1, $t4
    
    	j loopBinToDecBH


    DecToHexBH:
    
    	#carregar registrador $t0 com 16 para a divisão 
    	li $t0, 16
    
    	#carregar endereço do OutNum em $t1
    	la $t1, OutNum
    
    	#carregar endereço do VetAux em $t8
    	la $t8, VetAux
    
    	#carrega em $t9 o parametro para desvio
    	li $t9, 58
    
    	#$t5 será o contador
    	move $t5, $zero
    
    
    
    #Armazena Dec%16 em OutNum, convertendo ints ascii
    #$s1 =  valor Decimal
    #$t0 = base 16
    #$t1 = enderco de OutNum
    #$t8 = endereço VetAux
    #$t9 = parametro de desvio (verificar se eh maior que '9' ->58)
    #$t5 = contador
    CreateVetModBH:
    
    	#condição de parada
    	beq $s1, $zero, endCreateVetModBH
    
    	# divide $s0 por 16
    	divu $s1, $t0
    
    	#salvar inteiro em $s0 e resto em $t2
    	mflo $s1
    	mfhi $t2
    
    	#converter valor para representar o digito de acordo com a tabela ascii
    	addiu $t2, $t2, 48 
    
    	#se o valor do digito for menor que 10 desvia
    	blt $t2, $t9 , pulaBH
    	addiu $t2, $t2, 7

    pulaBH: 
    
    	#armazena t2 no OutNum
    	sb $t2, 0 ($t1)
    
    	#incrementa t1
    	addiu $t1, $t1, 1
    
    	#incrementa $t5
    	addiu $t5, $t5, 1
    
    	j CreateVetModBH
    
    endCreateVetModBH:

    	#se o contador for 0 imprime valo decimal
    	beq $t5, $zero, PrintStringnEnd


    # Inverte o vetor OutNum($t1) armazenando ele no vetor VetAux($t8)
    #$t5 = contador/parametro do branch
    #recebe o valor da posicao de OutNum e armazena em VEtAux
    InverteModsBH:

    	#anda com a posicao de t1
    	addiu $t1, $t1, -1
    
    	#decrementa o contador
    	addiu $t5, $t5, -1
    
    	#ve se o contador chegou em 0
    	blt $t5, $zero, PrintVetAuxnEnd
    
    	#pega o valor de $t4 (OutNum)
    	lb $t4, 0 ($t1)
    
    	#armazena em $t8(VetAux)
    	sb $t4, 0 ($t8)
    
    	#anda com a posicao de $t8
    	addiu $t8, $t8, 1
    
    
    	j InverteModsBH
	
#############################################################  Hex To Dec  #################################################################################
HexToDec:
    	#carregar enderço da InsertNum em $t0
    	la $t0, InsertNum
    
    	#carrega parametro para o $t2
    	li $t2, 10

    	#contador será $t4
    	li $t4, 0
    
    	#carrega endeço do DecimalWord em $t8
    	la $t8, DecimalWord
    
    #Pega caracter a carter da InsertNum e converte para seu valor da tabela ascii ou seja '1' -> 1
    #ou seja um vetor de '0'-'F', vira um vetor de 0-15
    #$t0 = Enderco InsertNum
    #$t2 = 10, serve para compara com o \n->10(ascii)
    #$t8 = enderco da word DecimalWord
    #$t4= contador
    ConvertCharToInt:

    	#carrega um dos caracteres para o $t1
    	lb $t1, 0 ($t0)
    
    	#desvia caso alcance o ultimo caracter, ja que qualquer char abaixo de 10 na tabela ascii é um controle (ou seja nao printável na tela)
    	ble $t1, $t2, endConvertCharToInt
    
    	#transformar caracter no valor que ele representa na tabela ascii
    	addiu $t1, $t1, -48
    
    	#se o valor do digito for menor que 10 desvia pra pula
    	blt $t1, $t2, pula
    	addiu $t1, $t1, -7
    

    #arnazena o valores 0-15 na word e anda com a string e volta pro loop
    pula:

    	#armazena valor achado no DecimalWord 
    	sw $t1, 0 ($t8)
    
    	#incrementa $t4
    	addiu $t4, $t4, 1
    
    	#incrementa $t0
    	addiu $t0, $t0, 1
    
    	#incrementa $t8
    	addiu $t8, $t8, 4
    
    	j ConvertCharToInt
    
    endConvertCharToInt:

    	# $t3 recebera 16 para a pontenciação
    	li $t3, 16

    	#$t9 servira de paramentro para o fim do loop2
    	li $t9, 0

    #Pega o valor do caracter e calcula 16^(posicao) e soma
    #$t1 = valor da posicao
    #$t3 = 16 base da potenciacao
    #$t9= parametro de comparaco pra fim do loop(CaLcularDec)
    #$t8 = enderco da word DecimalWord
    #$t4= contador (parametro para o branch)
    #$t5= recebe valor da potenciacao	
    CaLcularDec:
    	addiu $t8, $t8, -4
    
    	#não desvia enquanto $t9 for menor que $t4
    	beq $t9, $t4, PrintnEnd
    
    	#pega o digito de uma posição do DecimalWord
    	lw $t1, 0 ($t8)
    
    	#$t5 começa com 1
    	li $t5, 1
    
    	# $t6 recebe $t9
    	move $t6, $t9
    
    #Funcao de Potenciacao
    #$t3 = base
    #$t6 = expoente
    #$t5 resultado
    #resultado = b^e
    Potenciacao:

    	#desvia apenas quando $t6 é igual 0 
    	beq $t6, $zero, endPotenciacao
    
    	#multiplica $t5 por 16
    	mulu $t5, $t5, $t3
    
    	#decrementa $t6
    	addiu $t6, $t6 -1
    
    	j Potenciacao
    
    #fim da potencicaco
    #Total($t1) = posicao($t1) * [16^(posicao)]($t5)
    #decFinal($s1) += ($t1)
    endPotenciacao:
    
    	#multiplica valor de $t1 por $t5
    	mulu $t1, $t1, $t5
    
    	#$s1 soma com $t1
    	addu $s1, $s1, $t1
    
    	#incrmenta $t9
    	addiu $t9, $t9, 1
    
    	j CaLcularDec
	
####################################################################  Hex To Bin  ###################################################################################	
HexToBin:
	#carregar enderço da string em $t0
    	la $t0, InsertNum
    
    	#carrega parametro para o $t2
    	li $t2, 10
    
    	#carrega endeço do vetor em $t8
    	la $t8, DecimalWord
    
    	#contador será $t4
    	li $t4, 0
    
    #Pega caracter a carter da InsertNum e converte para seu valor da tabela ascii ou seja '1' -> 1
    #ou seja um vetor de '0'-'F', vira um vetor de 0-15
    #$t0 = Enderco String Hexa
    #$t2 = 10, serve para compara com o \n->10(ascii)
    #$t8 = enderco da word DecimalWord
    #$t4= contador	
    ConvertCharToIntHB:
    
    	#carrega um dos caracteres para o $t1
    	lb $t1, 0 ($t0)
    
    	#desvia caso alcance o ultimo caracter
    	beq $t1, $t2, endConvertCharToIntHB
    
    	#transformar caracter no valor que ele representa na tabela ascii
    	addiu $t1, $t1, -48
    
    	#se o valor do digito for menor que 10 desvia
    	blt $t1, $t2, pulaHB
    	addiu $t1, $t1, -7
    
    #arnazena o valores 0-15 na Decimalword e anda com a string e volta pro loop	
    pulaHB:
    
    	#armazena valor achado no vetor 
    	sw $t1, 0 ($t8)
    
    	#incrementa $t4
    	addiu $t4, $t4, 1
    
    	#incrementa $t0
    	addiu $t0, $t0, 1
    
    	#incrementa $t8
    	addiu $t8, $t8, 4
    
    	j ConvertCharToIntHB
    
    endConvertCharToIntHB:
    
    	# $t3 recebera 16 para a pontenciação
    	li $t3, 16
    
    	#$t9 servira de paramentro para o fim do loop2
    	li $t9, 0
    
    #Pega o valor do caracter e calcula 16^(posicao) e soma
    #$t1 = valor da posicao
    #$t3 = 16 base da potenciacao
    #$t9= parametro de comparaco pra fim do loop(CaLcularDec)
    #$t8 = enderco da word DecimalWord
    #$t4= contador (parametro para o branch)
    #$t5= recebe valor da potenciacao	
     CaLcularDecHB:
    
     	#anda a posicao do vetor
    	addiu $t8, $t8, -4
    
    	# não desvia enquanto $t9 for menor que $t4
    	beq $t9, $t4, endCaLcularDecHB
    
    	#pega o digito de uma posição do vetor
    	lw $t1, 0 ($t8)
    
    	#$t5 começa com 1
    	li $t5, 1
    
    	# $t6 recebe $t9
    	move $t6, $t9
    
    #Funcao de Potenciacao
    #$t3 = base
    #$t6 = expoente
    #$t5 resultado
    #resultado = b^e
    PotenciacaoHB:
    
    	#desvia apenas quando $t6 é igual 0 
    	beq $t6, $zero, endPotenciacaoHB
    
    	#multiplica $t5 por 16
    	mulu $t5, $t5, $t3
    
    	#decrementa $t6
    	addiu $t6, $t6 -1
    
    	j PotenciacaoHB
    
    #fim da potencicaco
    #Total($t1) = posicao($t1) * [16^(posicao)]($t5)
    #decFinal($t7) += ($t1)	
    endPotenciacaoHB:
    
    	#multiplica valor de $t1 por $t5
    	mulu $t1, $t1, $t5
    
    	#$t7 soma com $t1
    	addu $t7, $t7, $t1
    
    	#incrementa $t9
    	addiu $t9, $t9, 1
    
    	j CaLcularDecHB
    
    endCaLcularDecHB:
    #converter do decimal para binário agora
    
    	#carregar registrador $t0 com 2 para a divisão 
    	li $t0, 2
    
    	#carregar endereço em $t1
    	la $t1, vetorBinario
    
    	#$t5 será o contador
    	move $t5, $zero
    	
    	 
    	li $v0, 4
	la $a0, mensagemRes
	syscall

    	li $v0, 4
	la $a0, mensagemRes3
	syscall
    
    
    #divide o número decimal fornecido por 2 
    #o quociente se torna o novo decimal
    #o resto de cada divisão é armazenado no vetorBinario
    # e repete o processo até o quociente for 0
    #$t7 terá o decimal
    # $t0 será o divisor(2)
    #$t1 o endereço do vetorBinario
    #$t5 contará quantas vezes o processo foi realizado
    ConvertBinarioHB:
    
    	#condicao de parada
    	beq $t7, $zero, endConvertBinarioHB
    
    	# divide $s0
    	divu $t7, $t0
    
    	#salvar inteiro em $s0 e resto em $t2
    	mflo $t7
    	mfhi $t2
    
    	#armazena t2 no vetor1
    	sw $t2, 0 ($t1)
    
    	#incrementa t1
    	addiu $t1, $t1, 4
    
    	#incrementa $t5
    	addiu $t5, $t5, 1
    
    	#retorna para o inicio do loop
    	j ConvertBinarioHB
    
    #fim do loop	
    endConvertBinarioHB:
    
    	#verificar se o contador for 0 -> se for o valor binario final será 0 e encerra o programa
    	beq $t5, $zero, zero
    
    #vetorBinario possui o número binário invertido	-> imprimir digitos do fim para o inicio
    # $t4 pega o valor no vetor e imprime	
    ImprimeBinarioHB:
    
    	#anda com a posicao de t1
    	addiu $t1, $t1, -4
    
    	#decrementa contador
    	addiu $t5, $t5, -1
    
    	#condicao de parada -> contador atinge -1
    	blt $t5, $zero, endImprimeBinarioHB
    
    	#acessa valor no vetorBinario
    	lw $s4, 0 ($t1)
    
    	#imprime valor
    	li $v0, 36
    	move $a0, $s4
    	syscall 
    
    	#retorna para o inicio do loop
    	j ImprimeBinarioHB
    
    #fim do loop e encerre programa
    endImprimeBinarioHB:
    
    	li $v0, 10
    	syscall
    
    zeroHB:
    	li $v0, 36
    	move $a0, $t5
    	syscall
    
    	li $v0, 10
    	syscall
    

PrintnEnd:
    
    li $v0, 4
	la $a0, mensagemRes
	syscall

    li $v0, 4
	la $a0, mensagemRes3
	syscall

	li $v0, 36
	move $a0, $s1
	syscall
	
	li $v0, 10 
	syscall
	
PrintStringnEnd:

    li $v0, 4
	la $a0, mensagemRes
	syscall

    	li $v0, 4
	la $a0, mensagemRes3
	syscall

	li $v0, 4
	# como o numero nao mudou, a saida sera a mesma da entrada
	la $a0, InsertNum
	syscall
	
	li $v0, 10
	syscall

PrintVetAuxnEnd:

    	li $v0, 4
	la $a0, mensagemRes
	syscall

    	li $v0, 4
	la $a0, mensagemRes3
	syscall

	li $v0, 4
	la $a0, VetAux
	syscall
	
	li $v0, 10
	syscall
	
Erro:
	
    	li $v0, 4
	la $a0, mensagemErro
	syscall
	
	j LeStringBin
	
ErroBaseInvalida:
	
	li $v0, 4
	la $a0, mensagemErroBaseInv
	syscall
	
	li $v0, 10
	syscall
