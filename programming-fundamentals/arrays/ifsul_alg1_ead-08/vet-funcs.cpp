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
    VetorFunctions()
    {
    }
    template <typename T>

    void coutVet(const std::vector<T> &vet) const
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

    std::vector<int> ordenarDecrescente(const std::vector<int> &vet) const
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

    std::vector<int> ordenarCrescente(const std::vector<int> &vet) const
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

    std::vector<int> inverterOrdem(const std::vector<int> &vet) const
    {
        std::vector<int> vet_invertido = vet;
        size_t n = vet_invertido.size();
        for (size_t i = 0; i < n / 2; i++)
        {
            int temp = vet_invertido[i];
            vet_invertido[i] = vet_invertido[n - 1 - i];
            vet_invertido[n - 1 - i] = temp;
        }
        return vet_invertido;
    }

    template <typename T>
    vector<T> vetElementInput(int tam_vet, T limite_inferior, T limite_superior)
    {
    vector<T> vet(tam_vet);
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
    template <typename T>

    float mediaVector(const std::vector<T> &vet) const
    {
        int tam_vet = vet.size();
        float sum = 0.0f;
        for (int i = 0; i < tam_vet; i++)
        {
            sum += vet[i];
        }
        float media_vet = sum / tam_vet;
        cout << fixed << setprecision(1);
        return media_vet;
    }

    template <typename T>

    int elementsAboveLimit(vector<T> vet,T limit){
        
    }



};

/*int main(){
    using namespace std;
    int tam_vet = 10;
    VetorFunctions classeVetor;
    vector<float> vet_original = classeVetor.VetElementInput(tam_vet, 0.0f, 10.0f);
    cout << "Lista original:" << endl;
    classeVetor.CoutVetElements(vet_original);
    float media_vet = classeVetor.mediaVector(vet_original);
    cout << "\nMedia do Vector: "<< media_vet<< endl;
}
    */

// Em C++, não existe um equivalente direto ao "if __name__ == '__main__'" do Python.
// O ponto de entrada do programa é sempre a função main().
// Portanto, basta definir a função main() normalmente, como já está no seu código.

/* int main()
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
*/