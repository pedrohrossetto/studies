#include <iostream>
using namespace std;

void maiorElemento(int *vet, int n, int *maior, int *ocorrencias) {
    *maior = *vet;
    *ocorrencias = 1;

    int *p = vet + 1;
    for (; p < vet + n; p++) {
        if (*p > *maior) {
            *maior = *p;
            *ocorrencias = 1;
        } else if (*p == *maior) {
            (*ocorrencias)++;
        }
    }
}

int main() {
    int n;
    cout << "Digite o tamanho do array: ";
    cin >> n;

    int *vet = new int[n];

    cout << "Digite os " << n << " elementos do array:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(vet + i);
    }

    int maior, ocorrencias;
    maiorElemento(vet, n, &maior, &ocorrencias);

    cout << "Maior elemento: " << maior << endl;
    cout << "Numero de ocorrencias: " << ocorrencias << endl;

    delete[] vet;

    return 0;
}