#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void mostra_valores(int *px);

main()
{
    setlocale(LC_ALL,"Portuguese");
    int x[5] = {5,6,7,8,9};
    mostra_valores(x);
}

void mostra_valores(int *px)
{
    int *pi = new int(0);
    cout << endl << "Endereço inicial do ponteiro: " << px << endl;
    while(*pi < 5)
    {
        cout << px << endl;//mostra o endereço atual do px
        cout << *px << endl;//mostra o valor contido no endereço
        px++; //está se deslocando na memória usando aritmética de ponteiro
        (*pi)++;//está incrementando o valor do controlador do laço
    }

    cout << endl << "Endereço final do ponteiro: " << px << endl;

    px = px - *pi; //operação aritmética para retornar ao endereço inicial

    cout << endl << "Retorna ao Endereço inicial: " << px << endl;
}
