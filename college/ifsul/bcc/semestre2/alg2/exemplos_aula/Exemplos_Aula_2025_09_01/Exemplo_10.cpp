#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<ctime>

using namespace std;


main()
{
    setlocale(LC_ALL,"portuguese");
    int menu, v[20], soma = 0, indice = -1;
    char vet[10];

    srand(time(NULL));

    do
    {
        system("cls");
        cout << "-------MENU-------" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Popular o arquivo" << endl;
        cout << "2 - Mostrar os dados do arquivo" << endl;
        cout << "3 - Gerar vetor com os dados do arquivo" << endl;
        cout << "4 - Mostrar vetor" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch (menu)
        {
        case 0:
            cout << "Programa finalizado.";
            break;
        case 1:
            {
            ofstream escrever("exemplo_10.txt", ios::out);

            if(escrever.is_open())
            {
                for(int i = 0; i < 100; i++)
                {
                    escrever << rand() % 100 << ";";
                }


                cout << "Arquivo atualizado com sucesso.";
            }
            else
            {
                cout << "Erro não foi possível abrir o arquivo.";
            }
            escrever.close();
            break;
            }

        case 2:
            {
            ifstream ler("exemplo_10.txt", ios::in);

            if(ler.is_open())
            {
                cout << "\n\nConteúdo existente no arquivo: " << endl;
                while(!ler.eof())
                {
                    ler.getline(vet, 10, ';'); //lê toda a linha ou até atingir o tamanho
                    cout << vet << endl;
                }
            }
            else
            {
                cout << "Erro não foi possível abrir o arquivo.";
            }
            ler.close();
            getchar();
            break;
            }
        case 3:
            {
            ifstream ler("exemplo_10.txt", ios::in);

            if(ler.is_open())
            {
                cout << "\n\nVetor gerado com sucesso: " << endl;
                while(!ler.eof())
                {
                    ler.getline(vet, 10, ';'); //lê toda a linha ou até atingir o tamanho
                    indice++;
                    v[indice]= atoi(vet);
                    if(indice > 18)
                    {
                        break;//interrompe a leitura após ler os 20 termos do vetor
                    }
                }

            }
            else
            {
                cout << "Erro não foi possível abrir o arquivo.";
            }
            ler.close();
            getchar();
            break;
            }
        case 4:
            {
            cout << "\n\nElementos no vetor: " << endl;
            for(int i = 0; i <= indice; i++)
            {
                cout <<  v[i] << ", ";
            }
            break;
            }
        case 5:
            //
            break;
        default :
            cout << "Opção inválida do menu.";
            break;
        };
        getchar();
    }
    while(menu != 0);
}
