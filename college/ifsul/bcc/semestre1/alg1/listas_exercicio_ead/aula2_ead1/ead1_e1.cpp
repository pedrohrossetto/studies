#include <iostream>

using namespace std;

int main() {
    float cambio_dolar, produto_valor_reais, produto_valor_dolar;
    string produto;

    cout << "\nEscolha qual produto quer converter para dólar: ";
    cin >> produto;

    cout << "\nInforme o valor do produto \"" << produto << "\" em dólar: US$ ";
    cin >> produto_valor_dolar;

    cout << "\nInforme a cotação do dólar: ";
    cin >> cambio_dolar;

    produto_valor_reais = produto_valor_dolar * cambio_dolar;

    cout << "O valor do produto \"" << produto << "\" em Reais, na cotação atual de R$ " 
         << cambio_dolar << " é de R$ " << produto_valor_reais << "." << endl;

    return 0;  // ✅ FIX: Always return an integer from 'main'
}
