// Autor: Pedro H.C Rossetto
// Data: 19/05/2025
// Descrição: Código para preencher vetor, mostrar vetor, inverter e mostrar novamente
// Lista de Exercícios, Exercício 1, EAD8

//Vou tentar utilizar funções secundárias, classes e headers nessa lista de exercicios


#include <iostream>
#include <vector>
using namespace std;


vector<int> VetElementInput(int tam_vet, int limite_inferior, int limite_superior)
{
    vector<int> vet(tam_vet);
    for (int i = 0; i < tam_vet; i++)
    {
        do
        {
            cout << "\nPreencha, com valores entre " << limite_inferior << " e " << limite_superior << ", o vet para a posição: " << i << endl;
            cin >> vet[i];
        } while (vet[i] < limite_inferior || vet[i] > limite_superior);
        cout << "Posição " << i << " registrada com sucesso como " << vet[i] << endl;
    }
    return vet;
}

void CoutVetElements(const vector<int> &vet)
{
    cout << "[";
    for (size_t i = 0; i < vet.size(); i++)
    {
        cout << vet[i];
        if (i != vet.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

vector<int> inverterOrdem(const vector<int> &vet)
{
    std::vector<int> vet_invertido = vet;
    int vet_size = vet_invertido.size();
    for (int i_inv = 0; i_inv < vet_size / 2; ++i_inv)
    {
        int aux = vet_invertido[i_inv];
        vet_invertido[i_inv] = vet_invertido[vet_size - 1 - i_inv];
        vet_invertido[vet_size - 1 - i_inv] = aux;
    }
    return vet_invertido;
}

int main()
{
    int const tam_vet = 6;
    vector<int> vet = VetElementInput(tam_vet,20,50);
    cout << "\nVetor original:\n";
    CoutVetElements(vet);
    vector<int> vet_invertido = inverterOrdem(vet);
    cout << "Vetor invertido:\n";
    CoutVetElements(vet_invertido);
}