/*Escreva um programa que leia um texto qualquer via entrada padrão (teclado) a seguir o texto deverá ser escrito em um arquivo de texto e solicitar
se o usuário deseja incluir mais um texto, se a resposta for "s" ou "S", repetir o processo, caso a resposta for qualquer outra devera exibir um conteúdp
do arquivo na tela */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    ofstream arqSaida;
    ifstream arqEntr;
    string texto;
    char resposta;

    arqSaida.open("texto.txt", ios::out);

    if (!arqSaida){
        cout << "\n Erro ao abrir o arquivo" << endl;
    } else {
        cout << "Digite um texto: ";
        getline (cin, texto);

        arqSaida << texto << endl;

        cout << "\n Deseja escrever um novo texto? ";
        cout << "\n S/N";

        cin >> resposta;
    }
    if (resposta == 'S' || resposta == 's'){
        arqSaida.close();

        arqEntr.open("texto.txt", ios::in);
        if (!arqEntr){
            cout << "\n Erro ao abrir o arquivo! ";
        }
    } else { 
        cout << "\n Conteúdo do arquivo: ";
        cout << texto << endl;
    }
    return 0;
}