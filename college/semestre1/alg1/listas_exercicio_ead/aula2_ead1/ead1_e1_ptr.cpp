#include <iostream>

using namespace std;

int main() {
    string* ptr1 = new string();
    float* ptr2 = new float(0);
    float* ptr3 = new float(0);
    float* ptr4 = new float(0);

    cout << "\nEscolha qual produto quer converter para dólar: ";
    cin >> *ptr1;
    
    cout << "\nInforme o valor do produto \"" << *ptr1 << "\" em dólar: US$ ";
    cin >> *ptr2;

    cout << "\nInforme a cotação do dólar: ";
    cin >> *ptr3;

    *ptr4 = *ptr2 * *ptr3;

    cout << "O valor do produto \"" << *ptr1 << "\" em Reais, na cotação atual de R$ " 
    << *ptr2 << " é de R$ " << *ptr4<< "." << endl;

}
