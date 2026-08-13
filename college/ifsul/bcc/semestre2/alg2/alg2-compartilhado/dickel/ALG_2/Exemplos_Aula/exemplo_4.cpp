#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

main(){

    system("chcp 1252 > nul");

    char texto[80];

    ifstream ler;
    ler.open("exemplo_4.txt", ios::in);

    int soma = 0, vet[20], i = -1, aux;

    if (ler.is_open()){
        while(!ler.eof()){ // eof é para localizar o final do arquivo
            ler.getline(texto,80,';');
            cout << texto << endl;
            soma += atoi(texto);
            i++;
            vet[i] = atoi(texto);
        }

        ler.close();
        cout << "\n Soma dos valores lidos: " << soma << endl;

        cout << "\n Elementos do vetor: " << endl;

        for(int j = 0; j < i; j++){
            cout << vet [j] << "\t";
        }

        for (int j  = 0; j < i; j++){
            for (int x = j + 1; x < 1; x++){
                if(vet[j] > vet[x]){
                    aux = vet[j];
                    vet[j] = vet[x];
                    vet [x] = aux;
                }
            }
        }

    }
    else{
        cout << "Falha ao abrir";
    }
    return 0;
}