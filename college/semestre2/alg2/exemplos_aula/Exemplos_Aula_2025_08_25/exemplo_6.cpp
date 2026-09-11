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

    cout << "\n\nDados no arquivo lido por linha: " << endl;

    ifstream ler;//cria o objeto para leitura
    ler.open("exemplo_6.txt", ios::in); //abre o arquivo a ser lido

    int soma = 0, vet[20], i = -1, aux;
    if(ler.is_open())
    {
        while(!ler.eof())
        {
            ler.getline(texto,80,';');
            cout << texto << endl;
            soma += atoi(texto);
            i++;
            vet[i] = atoi(texto);
        }

        ler.close();
        cout << "\nSoma dos valores lidos: " << soma << endl;

        cout << "Elementos no vetor: " << endl;
        for(int j = 0; j < i; j++)
        {
            cout << vet[j] << "\t";
        }

        for(int j = 0; j < i - 1; j++)
        {
            for(int x = j + 1; x < i; x++)
            {
                if(vet[j] > vet[x])
                {
                    aux = vet[j];
                    vet[j] = vet[x];
                    vet[x] = aux;
                }
            }
        }

        cout << "\n\nElementos no vetor ordenados: " << endl;
        for(int j = 0; j < i; j++)
        {
            cout << vet[j] << "\t";
        }



    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}
