#include <iostream>
#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"


using namespace std;

struct Cliente{
    int codigo;
    string nome;
    int idade;

    Cliente() : codigo(0), nome(""), idade(0) {};
    Cliente(int p_codigo, string p_nome, int p_idade){
        codigo = p_codigo;
        nome = p_nome;
        idade = p_idade;
    }
};

// Função auxiliar que define o formato interno dos colchetes
void imprimirCliente(Cliente cliente) {
    std::cout << "[codigo " << cliente.codigo << ", nome " << cliente.nome << ", idade " << cliente.idade << "]";
}

Cliente criar_cliente();
bool empilhaP_Cliente(Pilha<Cliente> *p,Cliente cliente);


int main(void)
{
    int menu_selection;
    Pilha <Cliente> p1;
    int tamanho_pilha;
    int value;
    bool pilha_criada = false;

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
        inicializaP<Cliente>(&p1,tamanho_pilha);
        if(verificaInicializacaoP(&p1)){
            cout << "Pilha inicilizada.\n";
            pilha_criada = true;
            }
        else {
            cout <<"Pilha nao inicializada.\n";
        };


        break;
    case 2: //Inserir
        {
        if(cheiaP(&p1))
            {cout << "Pilha Cheia." << endl; break;}
        Cliente cliente = criar_cliente();
        empilhaP(&p1, cliente);

        break;
        }
    case 3: //Remover
        if(vaziaP(&p1))
            {cout << "Pilha vazia." << endl; break;}
        desempilhaP<Cliente>(&p1);
        break;

    case 4: //Consultar ----- Exercício 7 função buscaCliente
        cout << "Informe o valor a ser consultado: " << endl;
        cin >> value;
        if(buscaP<Cliente,int>(&p1,&Cliente::codigo, value))
            {cout << "Valor " << value << " Encontrado!"<< endl;}
        else 
            {cout << "Valor " << value << " Nao Encontrado..."<< endl;};
        break;
    case 5: //Mostrar
        cout << "Mostrando a pilha..." << endl;
        mostraP(&p1,imprimirCliente);
        break;
    default:
        cout << "Opcao Invalida." << endl;

    }
    }
    while(menu_selection != 0);
    destroiP(&p1);
    return 0;




    
}
Cliente criar_cliente()
    {

    int v_codigo;
    string v_nome;
    int v_idade;

    cout << "Informe código do cliente: ";
    cin >> v_codigo;
    cout << "Informe nome do cliente: ";
    cin.ignore();
    getline(cin,v_nome);
    cout << "Informe idade do cliente: ";
    cin >> v_idade;

    Cliente cliente(v_codigo,v_nome,v_idade);
    return cliente;
    }

bool empilhaP_Cliente(Pilha<Cliente> *p, Cliente cliente)
{
    if (verificaInicializacaoP(p) == false || cheiaP(p) == true)
        return false;
    
    p->topo++;
    p->dados[p->topo] = cliente;
    return true;
}