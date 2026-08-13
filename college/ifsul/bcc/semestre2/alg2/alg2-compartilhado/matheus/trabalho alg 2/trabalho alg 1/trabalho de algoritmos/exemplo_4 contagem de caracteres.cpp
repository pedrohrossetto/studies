#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>


using namespace std;


main()
{
    system("chcp 1252 > nul");

    ofstream escreve;//cria o objeto para escrita
    escreve.open("exemplo_4.txt", ios::app);
    string texto;
    char c;
    if(escreve.is_open())
    {
        cout << "Informe um texto qualquer: ";
        getline(cin,texto);
        fflush(stdin);//limpa o buffer do teclado
        escreve << texto << "\n";
        escreve.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }


    cout << "\n\nDados no arquivo: " << endl;

    ifstream ler;//cria o objeto para leitura
    ler.open("exemplo_4.txt", ios::in); //abre o arquivo a ser lido

    int cont = 0;

    if(ler.is_open())
    {
        while(ler.get(c)) //lendo letra por letra
        {
            c = toupper(c);
            cout << c;
            if(c == 'A')
            {
                cont++;
            }
        }
        ler.close();

        cout << "\nTotal de caracteres A no texto: " << cont << endl;
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}
