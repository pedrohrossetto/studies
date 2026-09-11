#include "../modules/pilhas_template.hpp"
#include "../modules/utils.hpp"
#include <cstring>
#include <iostream>
using namespace std;

void estatisticaP(Pilha<int> *p1, int *menor, int *maior, float *media);


int main() {
    int *menor = new int();
    int *maior = new int();
    float *media = new float();
    int tamanho_max = 20;

    Pilha <int> p1;
    inicializaP(&p1,tamanho_max);
    preencheP(&p1,true);

    estatisticaP(&p1,menor,maior,media);

    mostraP(&p1);

    cout << "Estatisticas da Pilha: "<< endl;
    cout << "Media: " << *media << endl;
    cout << "Menor Valor: " << *menor << endl;
    cout << "Maior Valor: " << *maior << endl;
    cout << "Quantidade de Valores: " << (p1.topo)+1 << endl;

    delete menor; delete maior; delete media;
    destroiP(&p1);
}


void estatisticaP(Pilha<int> *p1, int *menor, int *maior, float *media){
    int soma_total = 0, counter = 0;
    // Percorre a pilha do topo para a base
    for(int i = p1->topo; i > p1->base; i--){
        if( i == p1->topo){
            *menor = *maior = p1->dados[i];
        }
        if( p1->dados[i] < *menor)
            {*menor = p1->dados[i];};
        if( p1->dados[i] > *maior)
            {*maior = p1->dados[i];};
        soma_total += p1->dados[i];
        counter++;
    }
    float total_final = (float)soma_total;
    float counter_final = (float)counter;
    *media = total_final/counter_final;

}