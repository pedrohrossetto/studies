#include <iostream>
using namespace std;

#include "filacircular_lista5_ex2.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    aviao valor;
    int tamFila = 5;
    bool resultado;
    inicializaF(&f1, tamFila);
    int x = 0;
    do
    {
        cout << "\n|----------------------------menu----------------------------|\n";
        cout << "\n1-Imprimir o Num de avioes a espera de decolar\n";
        cout << "\n2-Entrada de um novo aviao para decolar (incluir na fila)\n";
        cout << "\n3-Decolagem de um aviao (retirar da fila)\n";
        cout << "\n4-Listar todos os avioes a espera para decolagem (mostrar fila)\n";
        cout << "\n5-Listar as caracteristicas do proximo aviao a decolar (peek)\n";
        cin >> x;
        if (x == 1)
        {
            resultado = mostraTotal(&f1);
            if (resultado == false)
            {
                cout << "\nNenhum aviao a espera, adicione um aviao!!!\n";
            }
            x = 0;
        }
        else if (x == 2)
        {
            cadastrarAviao(&f1);
            x = 0;
        }
        else if (x == 3)
        {
            valor = desenfileiraF(&f1);
            if (valor.codigo == -1)
            {
                cout << "sem avioes!!!!!!!";
            }
            else
            {
                cout << "O aviao codigo:" << valor.codigo << " foi desenfileirado com sucesso!\n";
            }
            x = 0;
        }
        else if (x == 4)
        {
            MostraTudo(&f1);
            x = 0;
        }
        else if (x == 5)
        {
            espiaF(&f1);
            x = 0;
        }
    } while (x < 1 || x > 5);

    destroiF(&f1);
    return EXIT_SUCCESS;

} // final do main
