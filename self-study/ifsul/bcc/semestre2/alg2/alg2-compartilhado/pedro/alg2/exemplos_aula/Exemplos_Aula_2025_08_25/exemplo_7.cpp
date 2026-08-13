#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>


using namespace std;


main()
{
    system("chcp 1252 > nul");

    char texto[80];

    cout << "\n\nDados no arquivo lido por palavra: " << endl;

    ifstream ler;//cria o objeto para leitura
    ler.open("exemplo_4.txt", ios::in); //abre o arquivo a ser lido

    if(ler.is_open())
    {
        while(!ler.eof())
        {
            ler >> texto;
            cout << texto << endl;
        }

        ler.close();

    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}
