#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

struct cadastro
{
    int codigo;
    string nome;
    float salario;
};

void ler_valores(cadastro *px);
void mostra_valores(cadastro *px);

main()
{
    setlocale(LC_ALL,"Portuguese");
    cadastro *x = new cadastro[3];
    ler_valores(x);
    mostra_valores(x);
}

void ler_valores(cadastro *px)
{
    int *pi = new int();
    cout << "Endereço inicial do ponteiro " << px << endl;
    for(*pi = 0; *pi < 3; (*pi)++)
    {
        cout << "Informe o código: ";
        cin >> px[*pi].codigo;
        //cin >> (*(px + *pi)).codigo;
        fflush(stdin);
        cout << "Informe o nome: ";
        getline(cin, (*(px + *pi)).nome);
        fflush(stdin);
        cout << "Informe o salário: ";
        cin >> (*(px + *pi)).salario;
        fflush(stdin);
    }

    cout << "Endereço final do ponteiro " << px << endl;

}

void mostra_valores(cadastro *px)
{
    int *pi = new int(0);
    while(*pi < 3)
    {
        cout << "Código: " << (*(px + *pi)).codigo << endl;
        cout << "Nome: " << (*(px + *pi)).nome << endl;
        cout << "Salário: " << (*(px + *pi)).salario << endl;
        cout << "---------------------------------" << endl;
        (*pi)++;
    }
}
