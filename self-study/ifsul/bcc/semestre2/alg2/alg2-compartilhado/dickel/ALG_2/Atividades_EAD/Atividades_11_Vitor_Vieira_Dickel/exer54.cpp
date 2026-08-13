#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    ifstream entrada("exer_54.txt");
    if (!entrada) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    double valor;
    int qtd = 0;
    while (entrada >> valor) {
        qtd++;
    }

    double* vet = (double*) malloc(qtd * sizeof(double));

    entrada.clear();
    entrada.seekg(0);
    int i = 0;
    while (entrada >> *(vet + i)) {
        i++;
    }
    entrada.close();

    for (int j = 0; j < qtd - 1; j++) {
        for (int k = j + 1; k < qtd; k++) {
            if (*(vet + j) > *(vet + k)) {
                double temp = *(vet + j);
                *(vet + j) = *(vet + k);
                *(vet + k) = temp;
            }
        }
    }

    ofstream saida("exer_54.txt");
    for (int j = 0; j < qtd; j++) {
        saida << *(vet + j) << " ";
    }
    saida.close();

    free(vet);

    cout << "Arquivo ordenado com sucesso!" << endl;
    return 0;
}