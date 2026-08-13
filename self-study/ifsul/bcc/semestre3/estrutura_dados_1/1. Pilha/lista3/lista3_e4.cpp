#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
using namespace std;



int main() {
    int tamanho_max = 3;
    Pilha <int> p1,p2;
    
    inicializaP(&p1,tamanho_max);

    preencheP(&p1,false);

    cout << "Pilha 1 original:\n";
    mostraP(&p1);

    p2 = inverteP(&p1);
    
    cout << "Pilha 2 invertida:\n";
    mostraP(&p2);

    destroiP(&p1);
    destroiP(&p2);

}