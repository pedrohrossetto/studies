#################################################
# BCC - AC1 - AT01
# Quest�o 4
# Grupo : 09
# Alunos: Pedro Henrique Carteli Rossetto e Matheus Pastore Polese
#################################################

.data

INICIO: .word 4
FIM:    .word 14
SOMA:   .word 0
msg: .asciiz "SOMA = "

.text

#################################################
# Inicializacao
#################################################
init:
    lui $s0, 0x1001        # $s0 = inicio area dados
    ori $s0, $s0, 0x0000   # $s0 = 0x1001 0000

main:
#################################################
# Implementar solucao abaixo
#################################################
    # Carrega os limites da memoria
    lw $t0, 0($s0)         # $t0 = INICIO
    lw $t1, 4($s0)         # $t1 = FIM

    # Inicializa os registradores
    add $t2, $zero, $zero  # $t2 = acumulador = 0
    add $t3, $t0, $zero    # $t3 = contador = inicio + 0

laco:
    # se FIM < contador entao sai do laco
    slt $t4, $t1, $t3      # if FIM < cont t4 = 1 else t4 = 0
    bne $t4, $zero, fim_laco # repete o laco ate t4 == 0

    # somatorio			acumulador = 4+4 | acumulador = 8+5 | acumulador = 13+6
    add $t2, $t2, $t3      # acumulador = acumulador + contador
    addi $t3, $t3, 1       # cont++
    j laco                 # Volta para o topo do laco

fim_laco:
    sw $t2, 8($s0)         # guarda o acumulador em SOMA

#################################################
# Mostrar resultado
#################################################
mostrar_resultado:
	## ajeita para printar "SOMA = "
    ori $v0, $zero, 4      # cod 4 print string
    addi $a0, $s0, 12      # INICIO=0, FIM=4, SOMA=8, msg=12
    syscall
	
    #exibe valor int
    lw $a0, 8($s0)         # SOMA=8 
    ori $v0, $zero, 1      # cod 1 print_int
    syscall

#################################################
# Encerrar
#################################################
    lui $v0, 0x0000      
    ori $v0, $v0, 0x000A # Exit syscall: code 0x0A
    syscall
