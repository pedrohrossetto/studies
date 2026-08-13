#include <iostream>
#include <limits> // Opcional, mas bom para validar

using namespace std;

/**
 * @brief Lê um número do teclado e salva no endereço apontado.
 * @param destino Ponteiro (já alocado com new) que receberá o valor.
 */
void input_lerInteiro(int* destino) {
    // Variável temporária no Heap para limpeza
    char* lixo = new char;

    cout << "> Digite um numero: ";
    cin >> *destino;

    // Limpeza de Buffer (Consome o Enter final)
    while (cin.get(*lixo) && *lixo != '\n');

    delete lixo;
}