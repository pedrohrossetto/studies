#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

main(){
    system("chcp 1252 > nul");

    ofstream escreve;
    escreve.open("output/exemplo_3.txt", ios::out);
    string texto;
    char c;

    if(escreve.is_open()){
        cout << "Informe um texto qualquer: ";
        getline(cin,texto);
        fflush(stdin); //limpa o buffer do teclado
        escreve << texto << "\n";
        escreve.close();
    }else{
        cout << "Falha ao abrir o abrir o arquivo";
    }

    cout << "\n Dados no arquivo: " << endl;

    ifstream ler; //cria o objeto para leitura
    int cont = 0;

    ler.open("output/exemplo_3.txt", ios::in); //abre o arquivo a ser

    if(ler.is_open()){
        while(ler.get(c)){ //lendo letra por letra
            c = toupper(c);
            cout << c;
            if(c == 'A'){
                cont ++;
            }
        } ler .close();
        cout <<"\n Total de caracteres do texto: " << cont << endl;
    }
    else{
        cout << "Falha ao abrir o arquivo.";
    }
}