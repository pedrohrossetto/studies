/**
 * @brief Valida se um numero atende aos criterios especificos:
 * - Multiplo de 4 OU 9
 * - OU Termina em 5 OU 8
 */
bool regra_validarNumeroComplexo(int* valor) {
    // Verifica Múltiplos
    if (*valor % 4 == 0) return true;
    if (*valor % 9 == 0) return true;
    
    // Verifica Terminação (Resto da divisão por 10)
    int* resto = new int(*valor % 10);
    bool match = (*resto == 5 || *resto == 8);
    
    delete resto;
    return match;
}