#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>


using namespace std;


main()
{
    system("chcp 1252 > nul");

    int num, soma = 0;

    cout << "\n\nDados no arquivo lido por palavra: " << endl;

    ifstream ler;//cria o objeto para leitura
    ler.open("exemplo_8.txt", ios::in); //abre o arquivo a ser lido

    if(ler.is_open())
    {
        while(!ler.eof())
        {
            ler >> num;
            cout << num << endl;
            soma += num;
        }

        ler.close();

        cout << "\n\nSoma dos valores: " << soma << endl;

    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}
