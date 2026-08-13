#include <iostream>

using namespace std;

int main(){

    int total = 6;
    int *ptr; // VAZIO, AQUI ESTA COMO LIXO DE MEMÓRIA

    ptr = &total; // sem o * e com & para direcionar ao endereço

    cout << "Conteúdo de total: " << total<< endl;
    cout << "Conteúdo de total apontado por '*ptr': " << *ptr << endl;
    
    cout << "Endereço de total: " << &total << endl; // retornará o endereço de total
    cout << "Conteúdo de apenas ptr: " << ptr << endl; // retornará o endereço de total
    cout << "Conteúdo de *ptr: " << *ptr << endl; // retornará o conteúdo de total

    *ptr = *ptr + 1; // altera o conteúdo de total
    
    cout << "Conteúdo modificado de total: "<< total << endl;
    cout << "Conteúdo modificado de total apontdo por ptr: "<< *ptr << endl;
}