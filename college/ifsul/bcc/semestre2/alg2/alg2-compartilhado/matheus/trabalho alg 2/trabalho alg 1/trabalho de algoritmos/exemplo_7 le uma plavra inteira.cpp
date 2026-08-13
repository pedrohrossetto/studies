#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

int main() {
    system("chcp 1252 > null");
    int i = 0;
    char texto[80], vet[80];

    cout << "\n\nDados no arquivo lido por palavra: " << endl;

    ifstream ler; // cria o objeto para leitura
    ler.open("exemplo_4.txt", ios::in); // abre o arquivo a ser lido

    if (ler.is_open()) {
        while (ler >> texto) { // Lê palavra por palavra do arquivo
            strcpy(vet, texto); // Copia a palavra lida para o vetor 'vet'
            i++;
            if(i==5){break;}
        }
        cout << vet << endl; // Exibe a palavra

        ler.close();
    } else {
        cout << "Não foi possível abrir o arquivo!" << endl;
    }

    return 0;
}
