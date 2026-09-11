#include <iostream>
using namespace std;

void imprimirVetorPtr(int* vetor, int* tamanho) {
    cout << "[ ";
    // Percorre do endereco inicial ate o endereco final (vetor + tamanho)
    for (int* p = vetor; p < (vetor + *tamanho); p++) {
        cout << *p << " ";
    }
    cout << "]" << endl;
}