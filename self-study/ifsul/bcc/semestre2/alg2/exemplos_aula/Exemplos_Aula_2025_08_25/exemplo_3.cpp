#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>


using namespace std;


main()
{
    system("chcp 1252 > nul");
    ofstream escreve;
    escreve.open("exemplo_3.txt", ios::app);
    string texto;
    if(escreve.is_open())
    {
        cout << "Informe um texto qualquer:~~ÇÇ ";
        getline(cin,texto);
        fflush(stdin);
        escreve << texto << "\n";
        escreve.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
    cout << "\n\nDados no arquivo: " << endl;
}
