#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>

using namespace std;

main()
{
    cout << fixed;
    cout.precision(2);

    float num, soma = 0;
    char texto[20];

    ifstream ler("numeros.txt", ios::in);
    if(ler.is_open())
    {
        cout << "\nLeitura realizada com sucesso" << endl;
        ler.getline(texto,20,';');
        while(!ler.eof())
        {
            //cout << texto << endl;
            num = atof(texto);
            cout << num << ", ";
            soma += num;
            ler.getline(texto,20,';');
        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    ler.close();

    cout << "\n\nSoma dos valores: " << soma << endl;

    ifstream ler2("numeros2.txt");
    soma = 0;
    if(ler2.is_open())
    {
        cout << "\nLeitura realizada com sucesso" << endl;
        ler2 >> num;
        while(!ler2.eof())
        {
           cout << num << "\t";
           soma += num;
           ler2 >> num;
        }

        cout << "\n\nSoma dos valores: " << soma << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo";
    }
    ler2.close();

}
