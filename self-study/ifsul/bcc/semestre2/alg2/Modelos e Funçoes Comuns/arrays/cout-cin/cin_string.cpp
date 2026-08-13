#include <iostream>
#include <cstring>

/**
 * @brief Lê uma linha de texto inteira.
 * @param destino Ponteiro para string (new string).
 */
void input_lerString(string* destino) {
    cout << "> Digite o texto: ";
    
    // getline funciona passando o valor desreferenciado (*destino)
    getline(cin, *destino);
}