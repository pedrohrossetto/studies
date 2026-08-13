#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    const int TAM = 20;
    int V[TAM];

    for (int i = 0; i < TAM; i++) {
        V[i] = rand() % 101; // rand() % (max + 1)
    }

    cout << "Vetor original:\n";
    for (int i = 0; i < TAM; i++) {
        cout << setw(3) << V[i] << " ";
    }
    cout << endl;

    ofstream arquivo("exer_18.txt");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    arquivo << "Vetor original:\n";
    for (int i = 0; i < TAM; i++) {
        arquivo << setw(3) << V[i] << " ";
    }
    arquivo << endl;

    int pos1, pos2;
    do {
        cout << "Digite a primeira posição (0 a 19): ";
        cin >> pos1;
    } while (pos1 < 0 || pos1 >= TAM);

    do {
        cout << "Digite a segunda posição (0 a 19): ";
        cin >> pos2;
    } while (pos2 < 0 || pos2 >= TAM);

    int temp = V[pos1];
    V[pos1] = V[pos2];
    V[pos2] = temp;

    cout << "Vetor alterado:\n";
    for (int i = 0; i < TAM; i++) {
        cout << setw(3) << V[i] << " ";
    }
    cout << endl;

    arquivo << "Vetor alterado:\n";
    for (int i = 0; i < TAM; i++) {
        arquivo << setw(3) << V[i] << " ";
    }
    arquivo << endl;

    arquivo.close();
    return 0;
}