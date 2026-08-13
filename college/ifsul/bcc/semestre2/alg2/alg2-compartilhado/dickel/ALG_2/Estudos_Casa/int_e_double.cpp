/*
    Este programa demonstra o uso de tipos de dados inteiros e double em C++.
*/
#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    cout << "Exemplo de Inteiros e Double em C++" << endl;
    cout << "====================================" << endl;

    int ivar; // variável inteira "ivar"
    double dvar; // variável do tipo double "dvar"

    ivar = 100;

    dvar = 100.0;

    cout << "Valor originhal de ivar: " << ivar << endl;
    cout << "Valor originhal de dvar: " << dvar << endl;
    cout << endl;

    ivar = ivar / 3;
    dvar = dvar / 3.0;

    cout << "Valor de ivar após divisão por 3: " << ivar << endl;
    cout << "Valor de dvar após divisão por 3.0: " << dvar << endl;
    cout << endl;

    return 0;
}