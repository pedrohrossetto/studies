#include <iostream>
#include <string>
#include <limits>
using namespace std;


struct Ficha
{
    int codigo;
    string nome;
    int idade;
    float saldo;
    Ficha()
    {
        codigo = 0;
        nome = "";
        idade = 0;
        saldo = 0.0f;
    }
};
#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"


int main(void)
{



    setlocale(LC_ALL, "Portuguese");
    char menu;

    Pilha pCadastro;
    Fila fP, fN, fD;

    do{
        system("cls");

        cout << "###BanPasso####\n";
        cout << "a - Cadastrar cliente\n";
        cout << "b - Adicionar cliente na fila\n";
        cout << "c - Mostrar\n";
        cout << "d - Atender cliente da fila\n";
        cout << "e - Mostrar dados do banco\n";
        cout << "s - Sair\n";
        cout << "Digite a opção: ";
        cin >> menu;
        menu = tolower(menu);

        if(menu!='a' && menu!='b' && menu!='c' && menu!='d' && menu!='e' && menu!='s')
        {
            cout << "Erro: opção inválida!\n";
            system("pause");
            continue;
        }

        //opções do menu
        if(menu=='a')
        {
            Ficha ficha;
            cout << "Informe o código:";
            cin >> ficha.codigo;
            cout << "Informe o nome:";
            cin >> ficha.nome;
            cout << "Informe a idade:";
            cin >> ficha.idade;
            cout << "Informe o saldo:";
            cin >> ficha.saldo;

            if(!buscaCodigoP(&pCadastro, ficha.codigo))
            {
                empilhaOrdenadoP(&pCadastro, ficha);
                cout << "O cliente " << ficha.nome << " foi cadastrado com sucesso!\n";
            }
            else
                cout << "Erro ao cadastradar! O código " << ficha.codigo << " já existe!\n";
        }
        else if(menu=='b')
        {
            int cod;
            cout << "Informe o código do cliente:";
            cin >> cod;

            if(!buscaCodigoP(&pCadastro, cod))
                cout << "Erro: código de cliente inexistente!\n";
            else if(buscaF(&fP, cod) || buscaF(&fN, cod) || buscaF(&fD, cod))
                cout << "Erro: o cliente já se encontra na fila!\n";
            else{
                //ufa, o cliente existe
                Ficha ficha;
                ficha = buscaFichaP(&pCadastro, cod);
                if(ficha.idade > 60)
                {
                    enfileiraF(&fP, cod);
                    cout << "O cliente " << ficha.nome << " foi enfileirado na Fila P!\n";
                }
                else if(ficha.saldo >= 0)
                {
                    enfileiraF(&fN, cod);
                    cout << "O cliente " << ficha.nome << " foi enfileirado na Fila N!\n";
                }
                else
                {
                    enfileiraF(&fD, cod);
                    cout << "O cliente " << ficha.nome << " foi enfileirado na Fila D!\n";
                }
            }
        }
        else if(menu=='c')
        {
            char opcao;
            cout << "Mostrar (P – Pilha ou F - Filas)?\n";
            cin >> opcao;
            opcao = toupper(opcao);

            if(opcao=='P')
                mostraP(&pCadastro);
            else if(opcao=='F')
            {
                mostraF(&fP, "Fila P: ");
                mostraF(&fN, "Fila N: ");
                mostraF(&fD, "Fila D: ");
            }
            else
                cout << "Erro: opção inválida!\n";

        }
        else if(menu=='d')
        {
            int cod = numeric_limits<int>::min();
            if(!vaziaF(&fP))
                cod = desenfileiraF(&fP);
            else if(!vaziaF(&fN))
                cod = desenfileiraF(&fN);
            else if(!vaziaF(&fD))
                cod = desenfileiraF(&fD);

            if(cod!= numeric_limits<int>::min())
            {
                Ficha ficha;
                ficha = buscaFichaP(&pCadastro, cod);
                float soma = somaSaldoBanco(&pCadastro);
                soma = soma * 0.8; //80% do saldo

                cout << "Valor máximo disponível para saque : " << soma << endl;
                cout << "O cliente " << ficha.nome << " está sendo atendido!\n";
                cout << "Código do cliente: " << ficha.codigo << endl;
                cout << "Idade do cliente: " << ficha.idade << endl;
                cout << "Saldo atual do cliente: " << ficha.saldo << endl;

                char opcao;
                float valor;

                cout << "Digite (D – Depósito ou S - Saque):";
                cin >> opcao;
                opcao = toupper(opcao);

                cout << "Valor:";
                cin >> valor;

                if(opcao == 'S')
                {

                    if(valor<=soma)
                    {
                        atualizaSaldo(&pCadastro, opcao, cod, valor);
                        cout << "O saque foi realizado com sucesso!\n";
                    }
                    else
                    {
                        cout << "O saque não foi realizado, ";
                        cout << "pois ultrapassa o limite atual do banco que é de R$" << soma << endl;
                    }

                }
                else if(opcao == 'D')
                {
                    cout << "O depósito foi realizado com sucesso!\n";
                    atualizaSaldo(&pCadastro, opcao, cod, valor);
                }
                else
                    cout << "Erro: opção inválida!\n";

            }
            else
                cout << "As filas estão vazias!\n";
        }
        else if(menu=='e')
        {
            int contCli, contCliNeg;
            float saldoM, saldoSoma;
            dadosBanco(&pCadastro, &contCli, &contCliNeg, &saldoM, &saldoSoma);
            cout << "Total de clientes: " << contCli << endl;
            cout << "Número de clientes com saldo negativo: " << contCliNeg << endl;
            cout << "Saldo médio : " << saldoM << endl;
            cout << "Soma do saldo de todos os clientes: " << saldoSoma << endl;
        }

        if(menu!='s')
            system("pause");
    }while(menu !='s');

    destroiP(&pCadastro);
    destroiF(&fP);
    destroiF(&fN);
    destroiF(&fD);

    return EXIT_SUCCESS;

}//final do main

