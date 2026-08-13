#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

main()
{
    ofstream escreve("exemplo_11.txt", ios::app);//método construtor
    string nome;

    cout << "Informe o nome completo: ";
    getline(cin, nome);
    fflush(stdin);

    escreve << nome << "\n";

    escreve.close();



    ifstream ler("exemplo_11.txt");

    if(ler.is_open())
    {
        while(!ler.eof())
        {
            getline(ler, nome);//lê a linha inteira e armazena no tipo string
            cout << nome << endl;
        }
        ler.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}
