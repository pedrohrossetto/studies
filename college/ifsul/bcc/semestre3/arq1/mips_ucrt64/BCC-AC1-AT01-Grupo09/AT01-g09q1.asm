#################################################
# BCC - AC1 - AT01
# Questão 1
# Grupo : 09
# Alunos: Pedro Henrique Carteli Rossetto e Matheus Pastore Polese
#################################################

.data

A:   .word 16
B:   .word -9
C:   .word 7
R:   .word 0
msg: .asciiz "R = "

.text

#################################################
# Inicializacao
#################################################
init:
    lui $s0, 0x1001        # $s0 = inicio area dados
    ori $s0, $s0, 0x0000   # $s0 = 0x1001 0000

main:
#################################################
# Implementar solucaoo abaixo
#################################################
    lw $t0, 0($s0)         # Carrega o valor (16) de A em $t0
    lw $t1, 4($s0)         # Carrega o valor (-9) de B em $t1
    add $t2, $t0, $t1      # $t2 = A + B (7)
    
    lw $t3, 8($s0)         # Carrega o valor de C em $t3 (7)
    sub $t4, $t2, $t3      # $t4 = (A + B) - C (0)
    
    sw $t4, 12($s0)        # Guarda o resultado ($t4=0) na variavel R (offset 12)

#################################################
# Mostrar resultado
#################################################
    # Por aqui as instrucoes para mostrar 'msg'
    ori $v0, $zero, 4      # Valor codigo para $v0: 4 (Print String)
    addi $a0, $s0, 16      # Carrega o endereco da 'msg' em $a0 (offset 16 do $s0)
    syscall
    
    # Mostrar o número R
    lw  $a0, 12($s0)       # Ajustar R para off(reg). Offset de R é 12!
    ori $v0, $zero, 1      # Código 1 para imprimir inteiro
    syscall

#################################################
# Encerrar
#################################################
    lui $v0, 0x0000        # Prepara a parte alta de $v0 com 0
    ori $v0, $v0, 0x000A   # Exit syscall: code 0x0A (10 em decimal)
    syscall
