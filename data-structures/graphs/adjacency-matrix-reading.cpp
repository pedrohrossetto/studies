#include <iostream>
using namespace std;

const int MAX_VERTICES = 20;

int lerInteiro(int minimo, int maximo) {
    int valor;
    while (true) {
        if (cin >> valor && valor >= minimo && valor <= maximo) {
            return valor;
        }
        cout << "Entrada invalida. Digite um numero entre "
             << minimo << " e " << maximo << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    int matriz[MAX_VERTICES][MAX_VERTICES] = {};
    int n, opcao, inicio, fim, vertice;
    int quantidadeArestas = 0;

    cout << "Quantidade de vertices (1 a 20): ";
    n = lerInteiro(1, MAX_VERTICES);

    do {
        cout << "\n0 - Sair\n"
             << "1 - Incluir aresta\n"
             << "2 - Mostrar matriz de adjacencia\n"
             << "3 - Remover aresta\n"
             << "4 - Mostrar vertices adjacentes\n"
             << "5 - Mostrar grau de um vertice\n"
             << "Opcao: ";
        opcao = lerInteiro(0, 5);

        if (opcao >= 2 && quantidadeArestas == 0) {
            cout << "Insira pelo menos uma aresta primeiro.\n";
            continue;
        }

        switch (opcao) {
            case 0:
                cout << "Programa encerrado.\n";
                break;

            case 1:
                cout << "Vertice inicial (0 a " << n - 1 << "): ";
                inicio = lerInteiro(0, n - 1);
                cout << "Vertice final (0 a " << n - 1 << "): ";
                fim = lerInteiro(0, n - 1);
                if (matriz[inicio][fim] == 0) {
                    matriz[inicio][fim] = 1;
                    quantidadeArestas++;
                    cout << "Aresta incluida.\n";
                } else {
                    cout << "Aresta ja existente.\n";
                }
                break;

            case 2:
                cout << "\nMatriz de adjacencia:\n   ";
                for (int j = 0; j < n; j++) cout << j << " ";
                cout << "\n";
                for (int i = 0; i < n; i++) {
                    cout << i << ": ";
                    for (int j = 0; j < n; j++) {
                        cout << matriz[i][j] << " ";
                    }
                    cout << "\n";
                }
                break;

            case 3:
                cout << "Vertice inicial (0 a " << n - 1 << "): ";
                inicio = lerInteiro(0, n - 1);
                cout << "Vertice final (0 a " << n - 1 << "): ";
                fim = lerInteiro(0, n - 1);
                if (matriz[inicio][fim] == 1) {
                    matriz[inicio][fim] = 0;
                    quantidadeArestas--;
                    cout << "Aresta removida.\n";
                } else {
                    cout << "Aresta inexistente.\n";
                }
                break;

            case 4: {
                cout << "Vertice (0 a " << n - 1 << "): ";
                vertice = lerInteiro(0, n - 1);
                cout << "Adjacentes de " << vertice << ": ";
                bool encontrou = false;
                for (int j = 0; j < n; j++) {
                    if (matriz[vertice][j] == 1) {
                        cout << j << " ";
                        encontrou = true;
                    }
                }
                if (!encontrou) cout << "nenhum";
                cout << "\n";
                break;
            }

            case 5: {
                cout << "Vertice (0 a " << n - 1 << "): ";
                vertice = lerInteiro(0, n - 1);
                int entrada = 0, saida = 0;
                for (int j = 0; j < n; j++) {
                    saida += matriz[vertice][j];
                    entrada += matriz[j][vertice];
                }
                cout << "Grau de entrada: " << entrada << "\n";
                cout << "Grau de saida: " << saida << "\n";
                cout << "Grau total: " << entrada + saida << "\n";
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}
