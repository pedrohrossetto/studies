#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void ler_valores(int *px);
void mostra_valores(int *px);

main()
{
    setlocale(LC_ALL,"Portuguese");
    int x[5];
    ler_valores(x);
    mostra_valores(x);
}

void ler_valores(int *px)
{
    int i, *pi = &i;
    cout << "Endereço inicial do ponteiro " << px << endl;
    for(*pi = 0; *pi < 5; (*pi)++)
    {
        *px = rand() % 10;
        px++; //incrementa o endereço de memória aritmética de ponteiro
    }

    cout << "Endereço final do ponteiro " << px << endl;

}

void mostra_valores(int *px)
{
    int i, *pi = &i;
    *pi = 0;
    while(*pi < 5)
    {
        cout << *px << ", ";//mostra o valor contido no endereço
        px++;
        (*pi)++;
    }
}
