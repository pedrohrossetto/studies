#include <iostream>
#include <cstdio>

/**
 * @brief Limpa o buffer de entrada (stdin) consumindo o '\n' residual.
 * Use após cin >> variavel_numerica.
 */
void util_limparBuffer() {
    // Variável temporária no Heap (para ser rigoroso)
    char* lixo = new char;
    
    // Consome caracteres até encontrar o Enter ou o fim do arquivo
    while (std::cin.get(*lixo) && *lixo != '\n');
    
    delete lixo;
}