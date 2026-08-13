#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    int a, b, c;

    a = 2;
    b = 3;

    if (a < b) cout << "a é menor que b" << endl;
    
    //isso não exibirá nada porque a não é menor que b
    if (a==b) cout << "você não verá isso" << endl;

    cout << endl;

    c = a - b; // c contém -1

    cout << "c contém -1" << endl;
    if (c >= 0) cout << "c não é negativo" << endl;
    if (c < 0) cout << "c é negativo" << endl;

    cout << endl;

    c = b - a; // c contém 1
    cout << "c contém 1" << endl;
    if (c >= 0) cout << "c não é negativo" << endl;
    if (c < 0) cout << "c é negativo" << endl;

    return 0;
}