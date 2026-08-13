#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream arq("dados.txt"); // abre o arquivo
    if(!arq.is_open()) {
        cout << "Erro ao abrir dados.txt\n";
        return 1;
    }

    int x; // variável para armazenar os números

    cout << "Lendo os numeros separados por ';':\n";

    // tenta ler números enquanto houver no arquivo
    while (arq >> x) {
        cout << "Numero lido: " << x << endl;

        // verifica se o próximo caractere é ';'
        if (arq.peek() == ';') {
            cout << "Encontrado ';' -> descartando\n";
            arq.ignore(1, ';'); // descarta o ';'
        }
    }

    arq.close();
    return 0;
}

//atividfade 15
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

int main() {
    const int N = 8;
    int m[N][N];

    srand(time(NULL)); // inicializa números aleatórios

    // Gerar a matriz 8x8 com valores de 0 a 99
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            m[i][j] = rand() % 100;
        }
    }

    ofstream arq("exer_15.txt", ios::out);
    if(!arq.is_open()) {
        cout << "Erro ao criar o arquivo exer_15.txt\n";
        return 1;
    }

    // --- 1) Dados da matriz ---
    arq << "Matriz 8x8:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            arq << m[i][j] << "\t"; // tabulação para formatar
        }
        arq << "\n";
    }
    arq << "\n";

    // --- 2) Diagonal Principal ---
    arq << "Diagonal Principal: ";
    for(int i = 0; i < N; i++) {
        arq << m[i][i] << " ";
    }
    arq << "\n";

    // --- 3) Diagonal Secundária ---
    arq << "Diagonal Secundaria: ";
    for(int i = 0; i < N; i++) {
        arq << m[i][N-1-i] << " ";
    }
    arq << "\n";

    // --- 4) Elementos acima da DP ---
    arq << "Elementos acima da DP: ";
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            arq << m[i][j] << " ";
        }
    }
    arq << "\n";

    // --- 5) Elementos abaixo da DP ---
    arq << "Elementos abaixo da DP: ";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            arq << m[i][j] << " ";
        }
    }
    arq << "\n";

    arq.close();
    cout << "Arquivo exer_15.txt gerado com sucesso!\n";

    return 0;
}
