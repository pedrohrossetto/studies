#include <iostream>
using namespace std;

// Preenche o vetor com numeros unicos entre min e max
void gerarAleatorioPadrao(int vetor[], int tamanho, int min, int max) {
    // Dica: Se pudesse usar <ctime>, chamaria srand(time(NULL)) aqui ou na main.
    
    for (int i = 0; i < tamanho; i++) {
        bool existe;
        int novoNumero;

        do {
            existe = false;
            // Formula: min + (rand() % (max - min + 1))
            novoNumero = min + (rand() % (max - min + 1));

            // Verifica se ja existe nos indices anteriores (0 ate i-1)
            for (int j = 0; j < i; j++) {
                if (vetor[j] == novoNumero) {
                    existe = true;
                    break; // Para o loop interno se achar duplicata
                }
            }
        } while (existe); // Se existe, repete a geracao

        vetor[i] = novoNumero;
    }
    
    cout << "Vetor gerado (Modo Padrao) com sucesso!" << endl;
}