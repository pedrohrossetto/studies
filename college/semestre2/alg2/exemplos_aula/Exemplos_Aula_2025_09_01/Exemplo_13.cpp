#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;


main()
{
    system("chcp 1252 > nul");
    cout << fixed;
    cout.precision(2);

    string aux, op, vetor, ordem;
    int valor, vet1[100], pos_1 = -1, vet2[100], pos_2 = -1, temp, soma = 0;
    float media = 0;

    ifstream arq("entradas.txt");

    while(!arq.eof())
    {
        arq >> op;
        if(op == "adiciona")
        {
            arq >> vetor;
            arq >> valor;
            if(vetor == "V1")
            {
                pos_1++;
                vet1[pos_1] = valor;
                //esta mensagem pode ser escrita no arquivo texto das saídas
                cout << "\nO número " << valor << " foi adicionado no vetor V1";
            }
            else if(vetor == "V2")
            {
                pos_2++;
                vet2[pos_2] = valor;
                //esta mensagem pode ser escrita no arquivo texto das saídas
                cout << "\nO número " << valor << " foi adicionado no vetor V2";
            }
        }
        else if(op == "mostra")
        {

            arq >> vetor;
            arq >> ordem;
            if(vetor == "V1")
            {
                cout << "\nV1(" << ordem << "): ";
                if(ordem == "C")
                {
                    for(int i = 0; i < pos_1; i++)
                    {
                        for(int j = i + 1; j <= pos_1; j++)
                        {
                            if(vet1[i] > vet1[j])
                            {
                                temp = vet1[i];
                                vet1[i] = vet1[j];
                                vet1[j] = temp;
                            }
                        }
                    }
                }
                if(ordem == "D")
                {
                    for(int i = 0; i < pos_1; i++)
                    {
                        for(int j = i + 1; j <= pos_1; j++)
                        {
                            if(vet1[i] < vet1[j])
                            {
                                temp = vet1[i];
                                vet1[i] = vet1[j];
                                vet1[j] = temp;
                            }
                        }
                    }
                }
                for(int i = 0; i <= pos_1; i++)
                {
                    cout << vet1[i] << ", ";
                }

            }

            else if(vetor == "V2")
            {
                cout << "\nV2(" << ordem << "): ";
                if(ordem == "C")
                {
                    for(int i = 0; i < pos_2; i++)
                    {
                        for(int j = i + 1; j <= pos_2; j++)
                        {
                            if(vet2[i] > vet2[j])
                            {
                                temp = vet2[i];
                                vet2[i] = vet2[j];
                                vet2[j] = temp;
                            }
                        }
                    }
                }
                if(ordem == "D")
                {
                    for(int i = 0; i < pos_2; i++)
                    {
                        for(int j = i + 1; j <= pos_2; j++)
                        {
                            if(vet2[i] < vet2[j])
                            {
                                temp = vet2[i];
                                vet2[i] = vet2[j];
                                vet2[j] = temp;
                            }
                        }
                    }
                }
                for(int i = 0; i <= pos_2; i++)
                {
                    cout << vet2[i] << ", ";
                }
            }

        }
        else if(op == "qtd")
        {
            arq >> vetor;

            if(vetor == "V1")
                cout << "\nTotal de elementos no vetor V1: " << pos_1 + 1;
            else if(vetor == "V2")
                cout << "\nTotal de elementos no vetor V2: " << pos_2 + 1;
        }
        else if(op == "media")
        {
            arq >> vetor;
            if(vetor == "V1")
            {
                soma = 0;
                for(temp = 0; temp <= pos_1; temp++)
                {
                    soma += vet1[temp];
                }

                media = (float)soma / (float)(pos_1 + 1);
                cout << "\nMédia dos elementos no vetor V1: " << media;
            }
            else if(vetor == "V2")
            {
                soma = 0;
                for(temp = 0; temp <= pos_2; temp++)
                {
                    soma += vet2[temp];
                }

                media = (float)soma / (float)(pos_2 + 1);
                cout << "\nMédia dos elementos no vetor V2: " << media;
            }

        }
        getline(arq, aux);
    }
    arq.close();
}

