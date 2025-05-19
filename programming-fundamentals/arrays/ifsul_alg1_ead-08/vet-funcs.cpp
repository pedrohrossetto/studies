#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>

class VetorFunctions
{
    // 'private' and 'public' are access specifiers.
    // They are not mandatory, but if you omit them:
    // - Members are 'private' by default in classes.
    // - Members are 'public' by default in structs.
private:
    std::vector<int> vet;

public:
    // Constructor that takes a vector as parameter
    VetorFunctions(const std::vector<int> &vetor_param)
    {
        vet = vetor_param;
    }


    
    void CoutVetElements(const std::vector<int> &vetor) const
    {
        cout << "[";
        for (size_t i = 0; i < vetor.size(); i++)
        {
            cout << vetor[i];
            if (i != vetor.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    std::vector<int> ordenarDecrescente()
    {
        std::vector<int> vet_ordenado = vet; // copiando o vetor original para um novo vetor
        int max, aux;
        for (size_t i = 0; i < vet_ordenado.size(); i++)
        {
            max = i;
            for (size_t j = i + 1; j < vet_ordenado.size(); j++)
            {
                if (vet_ordenado[j] > vet_ordenado[max])
                    max = j;
            }
            aux = vet_ordenado[max];
            vet_ordenado[max] = vet_ordenado[i];
            vet_ordenado[i] = aux;
        }
        return vet_ordenado;
    }

    std::vector<int> ordenarCrescente()
    {
        std::vector<int> vet_ordenado = vet;
        int min, aux;
        for (size_t i = 0; i < vet_ordenado.size(); i++)
        {
            min = i;
            for (size_t j = i + 1; j < vet_ordenado.size(); j++)
            {
                if (vet_ordenado[j] < vet_ordenado[min])
                    min = j;
            }
            aux = vet_ordenado[min];
            vet_ordenado[min] = vet_ordenado[i];
            vet_ordenado[i] = aux;
        }
        return vet_ordenado;
    }

    std::vector<int> inverterOrdem()
    {
        std::vector<int> vet_invertido = vet;
        size_t n = vet_invertido.size();
        for (size_t i = 0; i < n / 2; ++i)
        {
            int temp = vet_invertido[i];
            vet_invertido[i] = vet_invertido[n - 1 - i];
            vet_invertido[n - 1 - i] = temp;
        }
        return vet_invertido;
    }

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
};

// Em C++, não existe um equivalente direto ao "if __name__ == '__main__'" do Python.
// O ponto de entrada do programa é sempre a função main().
// Portanto, basta definir a função main() normalmente, como já está no seu código.

int main()
{
    using namespace std;
    vector<int> vetor_teste = {5, 2, 9, 1, 7}; // exemplo de vetor
    VetorFunctions classeVetor(vetor_teste);
    cout << "Lista original:\n";
    classeVetor.CoutVetElements(vetor_teste);
    vector<int> vet_invertido = classeVetor.inverterOrdem();
    cout << "Lista após processamento:\n";
    classeVetor.CoutVetElements(vet_invertido);
}