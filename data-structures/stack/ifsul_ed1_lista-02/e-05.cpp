#include <iostream>
#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"


using namespace std;

int main(void)
{
    int menu_selection;
    Pilha <string> p1;
    int tamanho_pilha;
    string value;
    bool pilha_criada;

    do{
    pausar_e_limpar();
    cout << "Informe a opcao desejada: \n1 - Criar Pilha\n2 - Inserir Valor\n3 - Remover Valor\n4 - Buscar Valor\n5 - Mostrar Pilha\n0 - Sair" << endl;
    cin >> menu_selection;
    limpar_tela();

    switch(menu_selection){
    case 0:
        cout << "\n----------------------------\nEncerrando o Programa...\n";
        break;
    case 1:
        if(pilha_criada)
            {cout << "Destruindo Pilha Antiga."<< endl; destroiP(&p1);}
        
        cout << "Informe tamanho da pilha" << endl;
        cin >> tamanho_pilha;
        inicializaP(&p1,tamanho_pilha);
        if(verificaInicializacaoP(&p1)){
            cout << "Pilha inicilizada.\n";
            pilha_criada = true;
            }
        else {
            cout <<"Pilha nao inicializada.\n";
        };


        break;
    case 2: //Inserir
        if(cheiaP(&p1))
            {cout << "Pilha Cheia." << endl; break;}
        cout << "Informe o valor a ser inserido: " << endl;
        cin.ignore();
        getline(cin,value);
        empilhaP<string>(&p1,value);

        break;
    case 3: //Remover
        if(vaziaP(&p1))
            {cout << "Pilha vazia." << endl; break;}
        cout << "Valor Removido: " << desempilhaP(&p1);
        break;

    case 4: //Consultar
        cout << "Informe o valor a ser consultado: " << endl;
        cin.ignore();
        getline(cin,value);
        if(buscaP<string>(&p1,value))
            {cout << "Valor " << value << " Encontrado!"<< endl;}
        else 
            {cout << "Valor " << value << " Nao Encontrado..."<< endl;};
        break;
    case 5: //Mostrar
        cout << "Mostrando a pilha..." << endl;
        mostraP(&p1);
        break;
    default:
        cout << "Opcao Invalida." << endl;

    }
    }
    while(menu_selection != 0);

    return 0;




    
}