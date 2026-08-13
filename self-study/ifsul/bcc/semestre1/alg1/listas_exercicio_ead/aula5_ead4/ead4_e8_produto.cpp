// Autor: Pedro H.C Rossetto
// Data: 30/03/2025
// Descrição: Código para ler codigo do produto
// Lista EAD 3, Exercício 8, Algoritimos 1


#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    string nome;

    char product_type;
    int product_code, product_stock;
    float product_value, sell_price, product_stock_value, type_porcentage;

    cout << "Código do produto: " << endl; cin >> product_code;
    cout << "Preço de custo do produto: " << endl; cin >> product_value;
    cout << "Quantidade em estoque do produto: " << endl; cin >> product_stock;
    product_stock_value = product_stock * product_value;

    cout << "Tipo (S/P): " << endl;
    cin >> product_type;
    product_type = toupper(product_type);

    if (product_type != 'S' && product_type != 'P') {
        cout << "Tipo de produto inválido." << endl;
        return 1;
    }
    else if (product_type = 'S') {
        type_porcentage = 0.8;
    }
    else if (product_type = 'P') {
        type_porcentage = 0.65;
    }

    cout << "Descrição do produto:  " << endl;
    getline(cin, nome); // Lê o nome completo
    
    sell_price = (type_porcentage * product_value) + product_value;

    cout << "Preço de venda: R$ " << sell_price << endl;
    cout << "Valor em estoque: R$ " << product_stock_value << endl;
    return 0;


}