#include <iostream>
using namespace std;

#include "cliente.hpp"
#include "fila-dinamica-template.hpp"

void mostraF(Fila<Cliente> *f, string nome="")
{

     cout << "Fila " << nome << " : ";

    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        cout << "{";

        NoFila<Cliente> *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << "[" << no->dado.nome << ", " << no->dado.idade << "]";
            no = no->prox;

            if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "}" << endl;
    }
    else
        cout << "vazia!\n";

}


//busca de pelo nome do cliente
bool buscaF(Fila<Cliente> *f, string nome)
{

    NoFila<Cliente> *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado.nome == nome)
            return true;

        no = no->prox;
    }

    return false;

}

//busca de pela idade
bool buscaF(Fila<Cliente> *f, int idade)
{

    NoFila<Cliente> *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado.idade == idade)
            return true;

        no = no->prox;
    }

    return false;

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    cout << "\n#######INT#######\n";
    Fila<int> f1;
    enfileiraF(&f1, 100);
    enfileiraF(&f1, 50);
    enfileiraF(&f1, 20);
    enfileiraF(&f1, 10);
    mostraF(&f1, "tipo int");
    destroiF(&f1);

    cout << "\n#######FLOAT#######\n";
    Fila<float> f2;

    if(vaziaF(&f2))
        cout << "Fila<float> vazia!\n";
    else
        cout << "Fila<float> não está vazia.\n";

    enfileiraF(&f2, 10.5f);
    enfileiraF(&f2, 50.6f);
    enfileiraF(&f2, 20.2f);
    enfileiraF(&f2, 10.3f);
    mostraF(&f2, "tipo float");
    cout << "Espia fila<float>: " << espiaF(&f2) << endl;
    cout << "Busca fila<float> valor 10.5: " << buscaF(&f2, 10.5f) << endl;
    float x = desenfileiraF(&f2);
    cout << "Valor x: " << x << endl;
    mostraF(&f2, "tipo float");
    destroiF(&f2);

    cout << "\n#######DOUBLE#######\n";
    Fila<double> f3;
    enfileiraF(&f3, 10.5);
    enfileiraF(&f3, 50.6);
    enfileiraF(&f3, 20.2);
    enfileiraF(&f3, 10.3);
    mostraF(&f3, "tipo double");
    double y = desenfileiraF(&f3);
    cout << "Valor y: " << y << endl;
    destroiF(&f3);


    cout << "\n#######CLIENTE#######\n";
    Fila<Cliente> f4;
    enfileiraF(&f4, Cliente("Fulano", 10));
    enfileiraF(&f4, Cliente("Ciclano", 20));
    mostraF(&f4, "tipo Cliente");
    cout << "Busca fila<Cliente> nome Fulano " << buscaF(&f4, "Fulano") << endl;
    cout << "Busca fila<Cliente> nome Joao " << buscaF(&f4, "Joao") << endl;
    cout << "Busca fila<Cliente> idade 20 " << buscaF(&f4, 20) << endl;
    cout << "Busca fila<Cliente> idade 50 " << buscaF(&f4, 50) << endl;
    Cliente c = desenfileiraF(&f4);
    cout << "Cliente c: " << c.nome << ", " << c.idade << endl;
    destroiF(&f4);


    return EXIT_SUCCESS;

}//final do main

