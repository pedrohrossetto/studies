#include <iostream>

using namespace std;

const int N = 10; 

void encontrar_maior_e_contar(const int *array, int tamanho, int *maior_elemento, int *contagem);

int main() {

    system("chcp 1252 > nul");
    
    int meu_array[N] = {5, 2, 15, 3, 7, 15, 8, 6, 15, 1}; 
    int maior = 0;
    int cont = 0;

    encontrar_maior_e_contar(meu_array, N, &maior, &cont);

    cout << "Array: ";
    for (int i = 0; i < N; i++) {
        cout << meu_array[i] << (i < N - 1 ? ", " : "");
    }
    cout << endl;

    cout << "O maior elemento é: " << maior << endl;
    cout << "Este elemento ocorreu: " << cont << " vez(es)." << endl;

    return 0;
}

void encontrar_maior_e_contar(const int *array, int tamanho, int *maior_elemento, int *contagem) {
    *maior_elemento = array[0];
    *contagem = 1;

    for (int i = 1; i < tamanho; i++) {
        // Uso da notação de array para simplificar a aritmética de ponteiros
        int elemento_atual = array[i]; 

        if (elemento_atual > *maior_elemento) {
            *maior_elemento = elemento_atual; 
            *contagem = 1; 
        } else if (elemento_atual == *maior_elemento) {
            (*contagem)++; 
        }
    }
}