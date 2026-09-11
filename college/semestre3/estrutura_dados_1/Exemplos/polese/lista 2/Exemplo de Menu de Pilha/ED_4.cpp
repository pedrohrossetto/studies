#include <iostream>
using namespace std;

#include "pilha.hpp"


int main(void)
{
    Pilha p1;
    int *cont = new int[0];
    *cont = 0;
    cout<<cont;//<<endl<<*cont<<endl<<&cont<<endl;
    int op;
    int tamPilha, valor;
    bool resultado;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        cout << "\n--- MENU PILHA ---\n";
        cout << "0 - Criar Pilha\n1 - Inserir (Push)\n2 - Remover (Pop)\n3 - Consultar (Top)\n4 - Mostrar Tudo\n5 - Sair\n";
        cout << "Escolha: ";
        cin >> op;

        switch(op)
        {
        case 0:
            destroiP(&p1);
            cout << "Informe o tamanho da pilha: ";
            cin >> tamPilha;
            inicializaP(&p1, tamPilha);
            cout << "Pilha criado com sucesso";
            *cont = 1;
            break;

        case 1:
            if (*cont==0)//colocar verificador de pilha
            {
                cout<<"Pro favor crie a pilha primeiro!\n";
                break;
          }
            cout<< "Digite um valor para ser empilhado: ";
            cin>>valor;
            resultado = empilhaP(&p1, valor);
            if(resultado == true)
                cout << "O valor " << valor << " foi empilhado com sucesso!\n";
            else
                cout << "Não foi possível empilhar o valor " << valor <<"!\n";
            break;

        case 2:
          if (*cont==0)
            {
                cout<<"Pro favor crie a pilha primeiro!\n";
                break;
            }
            if(cheiaP(&p1)==true)
            {
                cout<< "A pilha esta cheia...";
                break;
            }

            cout<< "Digite um valor para ser removido: ";
            cin>>valor;
            resultado = desempilhaP(&p1);
            if(resultado == true)
                cout<<"Valor ["<<valor<<"] removido com sucesso!";
            else
                cout << "Não foi possível remover o valor " << valor <<"!\n";
            break;


        case 3:
          if (*cont==0)
            {
                cout<<"Pro favor crie a pilha primeiro!\n";
                break;
            }
            if(vaziaP(&p1)==true)
            {
                cout<< "A pilha esta vazia...";

                break;
            }

            cout<< "Digite um valor para ser verificado: ";
            cin>>valor;
            resultado=buscaP(&p1, valor);
            if(resultado == true)
                cout<<"Valor ["<<valor<<"] esta presente na pilha!";
            else
                cout << "O valor " << valor <<" nao esta presente na pilha!\n";
            break;

        case 4:
         if (*cont==0)
            {
                cout<<"Pro favor crie a pilha primeiro!\n";
                break;
            }
            mostraP(&p1);
            break;
        case 5:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
        }
    }
    while(op != 5);
}
