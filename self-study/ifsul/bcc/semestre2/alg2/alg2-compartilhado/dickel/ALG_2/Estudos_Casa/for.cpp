#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "portuguese");
    /*
    for(initialization; condition; increment/decrement)
    initialization(iniciação): define uma variável de controle do loop inicial
    condition(condição): condição que é testada para cada vez que o loop se repete
    increment/decrement(incremento/decremento): determina como a variável de controle é implementada ou decrementada a cada iteração do loop
    */
   int count;

   for (count=1; count <=100; count++) {
       cout << "Contagem: " << count << endl;
   }
   return 0;
   /*
    No laço for, a inicialização da variável tem valor 1.
    A cada incremento do laço, a condição count <=100 é verificada.
    Quando o valor atinge 100 ou número maior, o laço é interrompido pois a condição não é mais verdadeira.
    o "++" incrementa o valor da variável count em 1 a cada iteração do laço.
   */
}