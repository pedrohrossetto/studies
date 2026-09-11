#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<windows.h>

using namespace std;

struct cadastro
{
    int matricula;
    string nome;
    float salario;
};

void leitura(cadastro *x);
void mostra(cadastro *x);

main()
{
    setlocale(LC_ALL, "portuguese");
    cadastro teste;
    leitura(&teste);
    system("cls");
    mostra(&teste);
}

void leitura(cadastro *x)
{
    cout << "Informe a matrícula: ";
    cin >> x->matricula;
    //cin >> (*x).matricula;
    fflush(stdin);

    cout << "Informe o nome: ";
    getline(cin, x->nome);
    //getline(cin, (*x).nome);
    fflush(stdin);

    cout << "Informe o salário: ";
    cin >> x->salario;
    //cin >> (*x).salario;
    fflush(stdin);

}

void mostra(cadastro *x)
{
    cout << "matrícula: " << (*x).matricula << endl;

    cout << "nome: " << (*x).nome << endl;

    cout << "salário: " << (*x).salario << endl;
}
