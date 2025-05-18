#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

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

    int const tamanho_vetor = 6;
    int i;

    int vetor_original[tamanho_vetor];

    for (i = 0; i < tamanho_vetor; i++)
    {
        do
        {
            cout << "\nPreencha o vet para a posição: " << i << endl;
            cin >> vetor_original[i];
        } while (vetor_original[i] < 20 || vetor_original[i] > 50);
        cout << "Posição " << i << " registrada com sucesso como " << vetor_original[i] << endl;
    }
    vector<int> vetor_invertido = inverterOrdem(vector<int>(vetor_original, vetor_original + tamanho_vetor));
    CoutVetElements(vetor_invertido);
}