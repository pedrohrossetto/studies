#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
using namespace std;



int main() {
    int tamanho_max = 3;
    Pilha <int> p1,p2;
    inicializaP(&p1,tamanho_max);
    inicializaP(&p2,tamanho_max);
    cout << "Pilha 1: \n";

    preencheP(&p1,false);
    cout << "Pilha 2: \n";

    preencheP(&p2,false);

    bool comparacao = comparaP(&p1,&p2);
    if (comparacao)
    {
        cout << "Pilhas são idênticas!";
    } 
    else
    {
        cout << "Pilhas não são iguais.";
    }
    cout << endl;
    
    cout << "Pilha 1: \n";
    mostraP(&p1);
    cout << "Pilha 2: \n";
    mostraP(&p2);


    destroiP(&p1);
    destroiP(&p2);
    
}