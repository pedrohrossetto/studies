#include <iostream>
#include <ctime>   // Para time()
#include <cstdlib> // Para rand() e srand()

using namespace std;

int main() {
    // Configura a semente para números aleatórios baseada no tempo atual
    srand(static_cast<unsigned int>(time(0)));

    // a. Aloca dinamicamente um vetor de 5 posições
    int* vetor = new int[5];

    // b. Grava as 5 posições com valores ímpares aleatórios (10 a 50)
    for (int i = 0; i < 5; i++) {
        int num;
        do {
            // Gera número entre 10 e 50
            num = rand() % (50 - 10 + 1) + 10;
        } while (num % 2 == 0); // Repete se for par para garantir que seja ímpar

        vetor[i] = num;
    }

    // c. Mostra o vetor
    cout << "Vetor de impares aleatorios (10 a 50):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "[" << i << "]: " << vetor[i] << endl;
    }

    // d. Libera a memória alocada
    delete[] vetor;
    vetor = nullptr; // Boa prática: anular o ponteiro após deletar

    return 0;
}