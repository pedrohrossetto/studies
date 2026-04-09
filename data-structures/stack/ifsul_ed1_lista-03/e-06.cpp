#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
using namespace std;



int main() {
    Pilha <int> p1,p2;
    
    inicializaP(&p1,5);
    inicializaP(&p1,5);

    preencheP(&p1,false);
    empilhaP(&p2,10);
    empilhaP(&p2,20);
    empilhaP(&p2,30);   

    Pilha <int> p3;
    p3 = intercalaP(&p1,&p2);
    cout << "Pilha 3:\n";
    mostraP(&p3);

    destroiP(&p1);
    destroiP(&p2);
    destroiP(&p3);

}

