
#include "ead6_e31.hpp"

using namespace std;


void gerar_novo_arquivo_valores() {
    ofstream arquivo_saida("ead6_e31_valores.txt");

    if (!arquivo_saida.is_open()) {
        cout << "Erro critico: Nao foi possivel criar o arquivo 'ead6_e31_valores.txt'." << endl;
        return;
    }

    cout << "\nGerando 300 novos valores..." << endl;

    for (int i = 0; i < 300; i++) {
        int numero_aleatorio = rand() % 1000;
        arquivo_saida << numero_aleatorio << ";";
    }

    arquivo_saida.close();
    cout << "Arquivo 'ead6_e31_valores.txt' gerado com sucesso!" << endl;
}

bool preencher_matriz(int matriz[][10], int ordem) {
    char valores[5];
    ifstream arquivo_valores("ead6_e31_valores.txt");

    if (arquivo_valores.is_open()) {
        for (int i = 0; i < ordem; i++) {
            for (int a = 0; a < ordem; a++) {
                while (true) {
                    arquivo_valores.getline(valores, 5, ';');
                    if (arquivo_valores.fail()) {
                        cout << "Erro: O arquivo terminou antes de a matriz ser preenchida com valores unicos." << endl;
                        arquivo_valores.close();
                        return false;
                    }
                    
                    int novo_valor = atoi(valores);
                    bool duplicado_encontrado = false;

                    for (int check_i = 0; check_i <= i; check_i++) {
                        int limite_coluna = (check_i < i) ? ordem : a;
                        for (int check_a = 0; check_a < limite_coluna; check_a++) {
                            if (matriz[check_i][check_a] == novo_valor) {
                                duplicado_encontrado = true;
                                break;
                            }
                        }
                        if (duplicado_encontrado) break;
                    }

                    if (!duplicado_encontrado) {
                        matriz[i][a] = novo_valor;
                        break;
                    }
                }
            }
        }
        arquivo_valores.close();
        return true;
    } else {
        cout << "Nao foi possivel abrir o arquivo 'ead6_e31_valores.txt'." << endl;
        return false;
    }
}

void mostrar_matriz(const int matriz[][10], int ordem) {
    for (int i = 0; i < ordem; i++) {
        for (int a = 0; a < ordem; a++) {
            cout << setw(5) << matriz[i][a];
        }
        cout << endl;
    }
}

int somar_diagonal_principal(const int matriz[][10], int ordem) {
    int soma = 0;
    for (int i = 0; i < ordem; i++) {
        soma += matriz[i][i];
    }
    return soma;
}

int somar_diagonal_secundaria(const int matriz[][10], int ordem) {
    int soma = 0;
    for (int i = 0; i < ordem; i++) {
        soma += matriz[i][ordem - 1 - i];
    }
    return soma;
}

int somar_linha(const int matriz[][10], int ordem, int numero_linha) {
    int soma = 0;
    for (int a = 0; a < ordem; a++) {
        soma += matriz[numero_linha][a];
    }
    return soma;
}

int somar_coluna(const int matriz[][10], int ordem, int numero_coluna) {
    int soma = 0;
    for (int i = 0; i < ordem; i++) {
        soma += matriz[i][numero_coluna];
    }
    return soma;
}

bool validar_quadrado_magico(const int matriz[][10], int ordem) {
    int soma_referencia = somar_diagonal_principal(matriz, ordem);
    if (somar_diagonal_secundaria(matriz, ordem) != soma_referencia) {
        return false;
    }
    for (int i = 0; i < ordem; i++) {
        if (somar_linha(matriz, ordem, i) != soma_referencia) {
            return false;
        }
        if (somar_coluna(matriz, ordem, i) != soma_referencia) {
            return false;
        }
    }
    return true;
}