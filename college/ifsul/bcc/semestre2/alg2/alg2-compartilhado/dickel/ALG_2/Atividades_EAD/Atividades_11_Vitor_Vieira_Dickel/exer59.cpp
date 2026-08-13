#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int mat[8][8];
    srand(time(0));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    ofstream arq("exer_59.txt");

    arq << "Matriz 8x8:\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arq << mat[i][j] << " ";
        }
        arq << endl;
    }

    arq << "\nDiagonal principal:\n";
    for (int i = 0; i < 8; i++) {
        arq << mat[i][i] << " ";
    }

    arq << "\n\nDiagonal secundaria:\n";
    for (int i = 0; i < 8; i++) {
        arq << mat[i][7 - i] << " ";
    }

    arq << "\n\nElementos acima da DP:\n";
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            arq << mat[i][j] << " ";
        }
    }

    arq << "\n\nElementos abaixo da DP:\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            arq << mat[i][j] << " ";
        }
    }

    arq.close();
    cout << "Arquivo exer_59.txt gerado com sucesso!\n";
    return 0;
}