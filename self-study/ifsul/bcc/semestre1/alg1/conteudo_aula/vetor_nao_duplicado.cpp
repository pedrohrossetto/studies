#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    const int TAMANHO_VETOR=10;
    int indice, indice_comparado, variavel_auxiliar, indice_minimo;
    int vetor[TAMANHO_VETOR];
    srand(time(NULL));
    cout << "\nVetor aleatório:\n";
    for (indice = 0; indice < TAMANHO_VETOR; indice++){
        vetor[indice] = rand()%100;
        cout <<"\n ["<< indice << "]" << vetor[indice];
    }
    for(indice=0 ; indice < TAMANHO_VETOR-1; indice++) {
        indice_minimo = indice;
        for(indice_comparado=indice+1 ; indice_comparado < TAMANHO_VETOR; indice_comparado++) {
            if (vetor[indice_comparado] < vetor[indice_minimo])
                indice_minimo = indice_comparado;
        }
        variavel_auxiliar = vetor[indice_minimo];
        vetor[indice_minimo] = vetor[indice];
        vetor[indice] = variavel_auxiliar;
    }
    cout<< "\n Vetor Ordenado \n";
    for(indice=0; indice < TAMANHO_VETOR ; indice++) {
        cout<<"\n["<<indice<<"]:" << vetor[indice];
    }
}
