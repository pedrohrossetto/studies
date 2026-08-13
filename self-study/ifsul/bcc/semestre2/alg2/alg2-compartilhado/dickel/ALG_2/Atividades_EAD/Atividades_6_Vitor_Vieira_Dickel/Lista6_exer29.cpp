#include <iostream>

using namespace std;

int inverterRecursivoAux(int numero, int reverso);

int inverterNumero(int numero) {

    return inverterRecursivoAux(numero, 0);
}

int inverterRecursivoAux(int numero, int reverso) {
    if (numero == 0) {
        return reverso;
    }

    int ultimoDigito = numero % 10;
    int novoReverso = reverso * 10 + ultimoDigito;

    return inverterRecursivoAux(numero / 10, novoReverso);
}

int main() {
    int numeroInformado;

    cout << "Digite um numero inteiro para ser invertido: ";
    if (numeroInformado < 0) {
        cout << "\nErro: Por favor, insira apenas numeros inteiros positivos." << endl;
        return 1; } else {
            cin >> numeroInformado;
        }

    int resultado = inverterNumero(numeroInformado);

    cout << "\nNumero informado: " << numeroInformado << endl;
    cout << "Resultado exibido: " << resultado << endl;

    return 0;
}