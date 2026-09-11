#################################################
# BCC - AC1 - AT01
# Questão 2
# Grupo : 09
# Alunos: Pedro Henrique Carteli Rossetto e Matheus Pastore Polese
#################################################

.data

A:     .word 0 #A=0
B:     .word 0 #B = 0
MAIOR: .word 0
msg: .asciiz "MAIOR = "

.text

#################################################
# Inicialização
#################################################
init:
    lui $s0, 0x1001        # $s0 = inicio area dados
    ori $s0, $s0, 0x0000   # $s0 = 0x1001 0000

main:
#################################################
# Implementar solução abaixo
#################################################
lw $t0, 0($s0) # t0 recebe A
lw $t1, 4($s0) # t1 recebe B

#	 A   < B		
slt $t2, $t0, $t1 # if(A<B) t2=1 else t2 =0
bne $t2, $zero, BMAIOR
AMAIOR:##MAIOR OU IGUAL
sw $t0, 8($s0)# guarda em A em MAIOR
j mostrar_resultado
BMAIOR:
sw $t1, 8($s0)# guarda em B em MAIOR
j mostrar_resultado

#################################################
# Mostrar resultado
#################################################
mostrar_resultado:
    ori $v0, $zero, 4      # $v0: 4 (Print String)
    addi $a0, $s0, 12      # 0=A 4=B 8=MAIOR 12=MSG
    syscall
	
    lw $a0, 8($s0)     #  8($s0)=maior
    ori $v0, $zero, 1
    syscall

#################################################
# Encerrar
#################################################
    lui $v0, 0x0000      # 
    ori $v0, $v0, 0x000A # Exit syscall: code 0x0A
    syscall
