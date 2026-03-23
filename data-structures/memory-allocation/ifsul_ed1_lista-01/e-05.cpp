#include <ctime>   
#include <cstdlib> 
#include "../modules/vetor_dinamico.hpp"
using namespace std;

int main(){
int tamanho = 0;
int* meu_vetor = nullptr; // Ponteiro inicializado como nulo para controle

cout << "Informe tamanho do vetor:\n";
cin >> tamanho;
meu_vetor = alocar_vetor(tamanho);
preencher_aleatorio(meu_vetor,tamanho,10,100);
mostrar_vetor(meu_vetor,tamanho);
liberar_vetor(meu_vetor);

}
