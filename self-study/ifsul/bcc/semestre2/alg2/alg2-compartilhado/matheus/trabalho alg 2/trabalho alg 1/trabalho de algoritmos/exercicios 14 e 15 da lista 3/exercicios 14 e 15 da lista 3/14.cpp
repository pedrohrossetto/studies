#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<cstring>
using namespace std;
int gerar(int *tamanho);
main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));
    do
    {
        cout << "\nMENU\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar valores para o vetor\n";
        cout << "2 - Localizar Valor\n";
        cout << "3 - Mostrar todos elementos de Vet\n";
        cout << "4 - Mostrar todos elementos de Sobra\n";
        cout << "Escolha: ";
        cin >> opc;

        switch(opc)
        {
        case 0:
            cout << "Encerrando programa...\n";
            break;


        case 1:
            cout<<"insira o tamanho do vetor, deve ser maior que 5: "
            cin>> int *tamanho;
            while(*tamanho<5)
            {
            cout<<"insira o tamanho do vetor, deve ser maior que 5: "
            cin>> int *tamanho;
            }
            int *p = new int[tamanho];
            int *sobra = new int[tamanho];
            gerar(p,tamanho);
            break;

}

int gerar(int *pvet,int *tamanho)
{
    int *tamanho = new int();
    int *contV = new int();
    *contV = 0;
    int *i = new int();
    int *j = new int();
    int *aux = new int();
    bool *achou = new bool();
    int *inicio = new int();
    inicio = pvet;
    int *percorre = new int();

    for (*i = 0; *i < *tamanho; (*i)++)
    {
        do
        {
            *aux = rand() % 50 + 1;
            *achou = false;
            percorre = inicio;

            for(*j = 0; *j < *contV; (*j)++)
            {
                if(*percorre == *aux)
                {
                    *achou = true;
                    cout << "Achou duplicado " << *percorre << endl;
                    break;
                }
                percorre++;
            }
            if(*achou == false)
            {
                *pvet  = *aux;
                pvet++;
                (*contV)++;
            }
        }
        while(*achou == true);
    }
}
