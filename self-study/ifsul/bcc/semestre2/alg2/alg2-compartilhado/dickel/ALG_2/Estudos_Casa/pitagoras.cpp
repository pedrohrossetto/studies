#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double a, b, c;

    cout << "\n Informe o valor do cateto adjacente: " <<endl;
    cin >> b;

    cout << "\n Informe o valor do cateto oposto: " <<endl;
    cin >> c;

    a = sqrt (b*b + c*c);

    cout << "\n O valor da hipotenusa é: " << a <<endl;

    return 0;
}