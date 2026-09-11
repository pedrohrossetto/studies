#include <iostream>

/**
 * @brief Calcula a média entre dois números arredondando para cima (Teto).
 * Lógica: (a + b + 1) / 2 realiza o "ceil" usando apenas inteiros.
 */
int math_mediaTeto(int* val1, int* val2) {
    // Alocação temporária
    int* soma = new int;
    *soma = *val1 + *val2;
    
    // Truque de aritmética inteira para teto: (numerador + denominador - 1) / denominador
    // Aqui: (soma + 2 - 1) / 2  => (soma + 1) / 2
    int resultado = (*soma + 1) / 2;
    
    delete soma;
    return resultado;
}