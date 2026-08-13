#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    const int MAX = 100;
    int V1[MAX], V2[MAX];
    int qtdV1 = 0, qtdV2 = 0;

    ifstream entrada("Entrada.txt");
    ofstream saida("Saida.txt");

    if (!entrada.is_open() || !saida.is_open()) {
        cout << "Erro ao abrir os arquivos!" << endl;
        return 1;
    }

    string comando;
    while (entrada >> comando) {
        if (comando == "adiciona") {
            string vetor;
            int num;
            entrada >> vetor >> num;

            if (vetor == "V1") {
                V1[qtdV1++] = num;
                saida << "O número " << num << " foi adicionado no vetor V1" << endl;
            } else if (vetor == "V2") {
                V2[qtdV2++] = num;
                saida << "O número " << num << " foi adicionado no vetor V2" << endl;
            }
        }
        else if (comando == "mostra") {
            string vetor, lixo;
            entrada >> vetor >> lixo;

            if (vetor == "V1") {
                saida << "V1(" << lixo << "): ";
                for (int i = 0; i < qtdV1; i++) {
                    saida << V1[i];
                    if (i < qtdV1 - 1) saida << ", ";
                }
                saida << endl;
            } else if (vetor == "V2") {
                saida << "V2(" << lixo << "): ";
                for (int i = 0; i < qtdV2; i++) {
                    saida << V2[i];
                    if (i < qtdV2 - 1) saida << ", ";
                }
                saida << endl;
            }
        }
        else if (comando == "remove") {
            string vetor;
            int num;
            entrada >> vetor >> num;

            if (vetor == "V1") {
                bool encontrado = false;
                for (int i = 0; i < qtdV1; i++) {
                    if (V1[i] == num) {
                        for (int j = i; j < qtdV1 - 1; j++) V1[j] = V1[j + 1];
                        qtdV1--;
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado)
                    saida << "O número " << num << " foi removido do vetor V1" << endl;
                else
                    saida << "O número " << num << " não pode ser removido, pois não pertence ao vetor V1" << endl;
            } else if (vetor == "V2") {
                bool encontrado = false;
                for (int i = 0; i < qtdV2; i++) {
                    if (V2[i] == num) {
                        for (int j = i; j < qtdV2 - 1; j++) V2[j] = V2[j + 1];
                        qtdV2--;
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado)
                    saida << "O número " << num << " foi removido do vetor V2" << endl;
                else
                    saida << "O número " << num << " não pode ser removido, pois não pertence ao vetor V2" << endl;
            }
        }
        else if (comando == "qtd") {
            string vetor;
            entrada >> vetor;
            if (vetor == "V1") {
                saida << "Total de elementos no vetor V1: " << qtdV1 << endl;
            } else if (vetor == "V2") {
                saida << "Total de elementos no vetor V2: " << qtdV2 << endl;
            }
        }
        else if (comando == "media") {
            string vetor;
            entrada >> vetor;
            if (vetor == "V1") {
                double soma = 0;
                for (int i = 0; i < qtdV1; i++) soma += V1[i];
                double media = (qtdV1 > 0) ? soma / qtdV1 : 0;
                saida << fixed << setprecision(1);
                saida << "Media dos elementos do vetor V1: " << media << endl;
            } else if (vetor == "V2") {
                double soma = 0;
                for (int i = 0; i < qtdV2; i++) soma += V2[i];
                double media = (qtdV2 > 0) ? soma / qtdV2 : 0;
                saida << fixed << setprecision(1);
                saida << "Media dos elementos do vetor V2: " << media << endl;
            }
        }
    }

    entrada.close();
    saida.close();
    return 0;
}