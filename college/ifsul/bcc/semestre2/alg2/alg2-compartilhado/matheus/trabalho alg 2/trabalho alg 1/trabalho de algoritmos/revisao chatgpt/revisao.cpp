#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

int main() {
    // --- Exemplo 1: Escrita em arquivo ---
    ofstream escreve("exemplo.txt", ios::out);
    if(!escreve.is_open()) {
        cout << "Erro ao abrir arquivo para escrita!" << endl;
        return 1;
    }
    escreve << "Primeira linha no arquivo\n";
    escreve << "Segunda linha no arquivo\n";
    escreve.close();
    cout << "Arquivo 'exemplo.txt' criado e escrito com sucesso.\n\n";

    // --- Exemplo 2: Leitura de caractere ---
    ifstream leitura("exemplo.txt", ios::in);
    if(!leitura.good()) {
        cout << "Erro ao abrir arquivo para leitura!\n";
        return 1;
    }
    char c;
    cout << "Lendo caractere por caractere:\n";
    while (leitura.get(c)) {
        cout << c;
    }
    leitura.close();
    cout << "\n\n";

    // --- Exemplo 3: Leitura de linhas ---
    ifstream leitura2("exemplo.txt", ios::in);
    char conteudo[80];
    cout << "Lendo linha por linha:\n";
    while (leitura2.getline(conteudo, 80)) {
        cout << conteudo << endl;
    }
    leitura2.close();
    cout << "\n";

    // --- Exemplo 4: Leitura de palavras ---
    ifstream leitura3("exemplo.txt", ios::in);
    cout << "Lendo palavra por palavra:\n";
    while (!leitura3.eof()) {
        leitura3 >> conteudo;
        if (!leitura3.fail())
            cout << conteudo << endl;
    }
    leitura3.close();
    cout << "\n";

    // --- Exemplo 5: Escrita de registros (Ctrl+Z encerra) ---
    ofstream escreve2("registros.txt", ios::out);
    int numero;
    char nome[50];
    cout << "Digite numero e nome (Ctrl+Z para encerrar):\n";
    while(cin >> numero >> nome) {
        escreve2 << numero << ";" << nome << "\n";
        cout << "Proximo registro? ";
    }
    escreve2.close();
    cout << "\nRegistros gravados em 'registros.txt'.\n\n";

    // --- Exemplo 6: Leitura em matriz (5x5) ---
    ifstream lerMatriz("matriz.txt");
    if(lerMatriz.is_open()) {
        int m[5][5];
        for(int l = 0; l < 5; l++) {
            for(int c = 0; c < 5; c++) {
                lerMatriz >> m[l][c];
            }
        }
        lerMatriz.close();

        cout << "Matriz lida do arquivo:\n";
        for(int l = 0; l < 5; l++) {
            for(int c = 0; c < 5; c++) {
                cout << m[l][c] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Nao foi possivel abrir 'matriz.txt'.\n";
    }

    return 0;
}
