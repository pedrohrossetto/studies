#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
using namespace std;



int main() {
    Pilha <int> p1;
    inicializaP(&p1,5);
    preencheP(&p1,false);


    


    destroiP(&p1);

}

