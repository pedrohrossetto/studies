#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    double pes, metros;

    cout << "Digite o valor em pés: ";
    cin >> pes;

    metros = pes * 3.28;

    cout << pes << " pés equivalem a " << metros << "metros." << endl;

    return 0;
}