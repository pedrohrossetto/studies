#include "../modules/lista.hpp"
#include <iostream>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor; //valor deve ser do mesmo tipo de DadoNoLista (lista.hpp)
    No* aux; //usado na busca
    No* lista; //evite usar "list", pois � uma palavra reservada

    inicializaL(&lista);

    cout << "\n\n###TESTE 1\n";
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 40);
    mostraL(&lista);
    inserePrimeiroPar(&lista,11);
    mostraL(&lista);
    insereAntesPrimeiroPar(&lista,232);
    mostraL(&lista);

}