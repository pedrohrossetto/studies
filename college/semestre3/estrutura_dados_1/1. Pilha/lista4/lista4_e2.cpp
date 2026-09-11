#include "../modules/pilha_dinamica_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;


template<typename T>
void percorrePilhaInversamenteP_local(Pilha<T> *p);

template<typename T>
void percorreInversoAuxP_local(NoPilha<T> *no);

void inverteStringsP(Pilha<string> *p);


int main() {
    Pilha<string> p1;
    empilhaP(&p1, string("Hello"));
    empilhaP(&p1, string("World"));
    
    percorrePilhaInversamenteP_local(&p1);

    destroiP(&p1);

}

template<typename T>
void percorreInversoAuxP_local(NoPilha<T> *no)
{
    if (no == nullptr) return;
    percorreInversoAuxP_local(no->prox);
    std::cout << no->dado << " ";
}

template<typename T>
void percorrePilhaInversamenteP_local(Pilha<T> *p)
{
    if(vaziaP(p) == false) {
        percorreInversoAuxP_local(p->topo);
    }
}


void inverteString_local(std::string &str) {
    int n = str.length();
    
    // Percorre apenas até a metade da string
    for (int i = 0; i < n / 2; i++) {
        // Lógica de troca manual (sem usar std::swap se preferir)
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}