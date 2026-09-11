#################################################
# BCC - AC1 - AT01
# Questão 3
# Grupo : 09
# Alunos: Pedro Henrique Carteli Rossetto e Matheus Pastore Polese
#################################################

.data

A:   .word -6
B:   .word 8
R:   .word 0
msg: .asciiz "R = "

.text

#################################################
# Inicialização
#################################################
init:
    lui $s0, 0x1001        # $s0 = inicio area dados
    ori $s0, $s0, 0x0000   # $s0 = 0x1001 0000

main:
#################################################
# Tarefa 3: Questão 3 – Seleção Condicional Composta
#################################################

    lw  $t0, 0($s0)        # Carrega A em $t0
    lw  $t1, 4($s0)        # Carrega B em $t1
    
    slt $t3, $t1, $t0      # Se B < A (ou seja, A > B), então $t3 = 1
    bne $t3, $zero, rotuloMaior    # Se verdadeiro ($t3 != 0), pula para rotuloMaior
    
    beq $t0, $t1, RotuloIgual      # Se A == B, pula para RotuloIgual
    
rotuloMenor:
    # Caso padrão (Else): Se não for maior nem igual, A é menor que B
    add $t4, $t0, $t1      # $t4 = A + B
    j   fimCondicional     # Desvia para o fim para não invadir outros blocos
    
rotuloMaior:
    sub $t4, $t0, $t1      # $t4 = A - B
    j   fimCondicional     # Desvia para o fim
    
RotuloIgual:
    add $t4, $zero, $zero  # $t4 = 0
    j   fimCondicional     # Desvia para o fim
    
fimCondicional:
    sw  $t4, 8($s0)        # Salva o resultado em R (offset 8 nesta questão)
    
#################################################
# Mostrar resultado
#################################################
    # Instruções para mostrar 'msg'
    ori  $v0, $zero, 4     # Syscall 4: Print String
    addi $a0, $s0, 12      # Endereço da 'msg' está no offset 12 do $s0
    syscall
        
    # Instruções para mostrar o valor numérico de R
    lw   $a0, 8($s0)       # Ajustado R para offset reg: 8($s0)
    ori  $v0, $zero, 1     # Syscall 1: Print Integer
    syscall

#################################################
# Encerrar
#################################################
    lui $v0, 0x0000       
    ori $v0, $v0, 0x000A   # Exit syscall
    syscall