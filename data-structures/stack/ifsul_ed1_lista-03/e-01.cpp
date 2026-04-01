#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
using namespace std;

bool buscaP(Pilha<int> *p1, Pilha<int> *p_aux, int valorBusca);



int main() {
    int tamanho_max = 25;
    Pilha<int> p1,p2_aux;

    // Inicializa a pilha para suportar os caracteres
    inicializaP(&p1, tamanho_max);
    inicializaP(&p2_aux,tamanho_max);

    preencheP(&p1,false);

    int valor_busca = 95;

    bool encontrado = buscaP(&p1,valor_busca);

    mostraP(&p1);

    if (encontrado)
    {
        cout << "Valor "<< valor_busca << " Encontrado!\n";
    } 
    else
    {
        cout << "Valor " << valor_busca << " Nao Encontrado.\n";  
    }

    return EXIT_SUCCESS;

}


bool buscaP(Pilha<int> *p1, Pilha<int> *p_aux, int valorBusca) 
{
    int aux;
    bool encontrou;
    // Percorre a pilha do topo para a base
    for(int i = p1->topo; i > p1->base; i--)
    {
        aux = desempilhaP(p1);
        // p1->dados[i].*campo acessa o valor do campo específico naquela instância da struct
        if (aux == valorBusca)
        {
            encontrou = true;
        }
        empilhaP(p_aux,aux);
    }
    for (int i = p_aux->topo; i >p1->base;i--)
    {
        empilhaP(p1,desempilhaP(p_aux));
    }

    return encontrou; 
}