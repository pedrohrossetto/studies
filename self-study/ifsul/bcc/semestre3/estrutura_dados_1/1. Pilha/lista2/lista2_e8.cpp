#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
using namespace std;


int main() {
    int tamanho_max = 25;
    Pilha<char> p1,p2,p2_aux,p3;

    // Inicializa a pilha para suportar os caracteres
    inicializaP(&p1, tamanho_max);
    inicializaP(&p2, tamanho_max);
    inicializaP(&p3, tamanho_max);
    inicializaP(&p2_aux, tamanho_max);


    cout << "Digite uma palavra (ela sera empilhada letra por letra): ";
    
    ReceberInputP(&p1," .");

    cin.ignore();

    cout << "Digite outra palavra (ela sera empilhada letra por letra): ";
    
    ReceberInputP(&p2," .");
    p2_aux = p2;
    p3 = inverteP(&p2);
    p2 = p2_aux;

    mostraP(&p1);
    mostraP(&p2);
    mostraP(&p3);

    bool ispalindromo = (comparaP(&p1,&p2) && comparaP(&p1,&p3));
    if (ispalindromo)
    {
        cout << "Palindromo!" << endl;
    }
    else
        cout <<"Nao palindromo..." << endl;
    


    destroiP(&p1);
    destroiP(&p2);
    destroiP(&p3);
    destroiP(&p2_aux);


    return 0;
}
