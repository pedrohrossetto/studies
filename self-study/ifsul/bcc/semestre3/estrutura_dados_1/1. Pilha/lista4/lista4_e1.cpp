#include "../modules/pilha_dinamica_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
using namespace std;

template<typename T>
void percorreP_local(Pilha<T> *p);


int main() {
    Pilha<int> p1;
    empilhaP(&p1, 100);
    empilhaP(&p1, 50);

    percorreP_local(&p1);


    destroiP(&p1);

}

template<typename T>
// Adicionado std:: antes de string
void percorreP_local(Pilha<T> *p) 
{
    if(vaziaP(p) == false)
    {
        NoPilha<T> *no = p->topo;
        while (no != NULL)
        {            
            std::cout << no->dado << " | " << no << " | " << no->prox << std::endl;
            no = no->prox;
        }
    }
}