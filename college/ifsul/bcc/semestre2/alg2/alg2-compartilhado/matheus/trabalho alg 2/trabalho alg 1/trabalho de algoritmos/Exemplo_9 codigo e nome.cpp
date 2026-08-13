#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

main()
{
    ofstream escreve("exemplo_9.txt");//método construtor
    int cod, soma = 0;
    string nome;
    if(escreve.is_open())
    {
        cout << "Informe o codigo e o nome, CTRL+Z para finalizar: ";
        while(cin >> cod >> nome)
        {
            escreve << cod << " " << nome << "\n";
            cout << "Proximo Registro ou CTRL+Z para finalizar? ";
        }
        escreve.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
    cout << "\n\nDados no arquivo: " << endl;

    ifstream ler("exemplo_9.txt");

    if(ler.is_open())
    {
        while(ler >> cod >> nome)
        {
            cout << cod << " " << nome << "\n";
            soma += cod;
        }
        cout << "\nSoma dos codigos: " << soma;
        ler.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}
