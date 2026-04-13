#include "../modules/pilha_dinamica_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;


int main() {
    Pilha<string> p1;
    empilhaP(&p1, string("Hello"));
    empilhaP(&p1, string("World"));

    percorreP(&p1);
    desempilhaP(&p1);
    cout << "Após desempilhar um elemento:" << endl;

    percorreP(&p1);

    destroiP(&p1);

}