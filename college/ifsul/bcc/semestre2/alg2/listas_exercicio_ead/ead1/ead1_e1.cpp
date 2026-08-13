#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

const int TAMANHO_MAX_N = 11;

int input_ordem_N(int tamanho_n);
void preencherMatrizSimples(int mat[TAMANHO_MAX_N][TAMANHO_MAX_N],int tamanho_real, int VALOR_MIN, int VALOR_MAX);
void mostrarMatriz(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n);
void mostrarMatriz_dp(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n);
void mostrarMatriz_ds(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n);
void mostrarMatriz_elementos_fora_dp(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n);
void mostrarMatriz_fora_ds(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n);
void menu_mostrarMatrizes(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n);

int main(){

int tamanho_n = 0;
tamanho_n = input_ordem_N(tamanho_n);
cout << "Ordem escolhida: " << tamanho_n << endl; 
int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N];

const int VALOR_MIN = 0;
const int VALOR_MAX = 100;

preencherMatrizSimples(matriz_n,tamanho_n,VALOR_MIN,VALOR_MAX);
menu_mostrarMatrizes(matriz_n,tamanho_n);
// mostrarMatriz(matriz_n,tamanho_n);
//mostrarMatriz_dp(matriz_n,tamanho_n);
// mostrarMatriz_ds(matriz_n,tamanho_n);
//mostrarMatriz_elementos_fora_dp(matriz_n,tamanho_n);
//mostrarMatriz_fora_ds(matriz_n,tamanho_n);

return 0;

}

int input_ordem_N(int tamanho_n){ 
    do
    {

        cout << "Informe o tamanho da Matriz (3 < N < 11): " << endl;
        cin >> tamanho_n;
    } while (!(tamanho_n > 3 and tamanho_n < 11));
     
    return tamanho_n;
}

void preencherMatrizSimples(int mat[TAMANHO_MAX_N][TAMANHO_MAX_N],int tamanho_real, int VALOR_MIN, int VALOR_MAX) {

    // 1. Loop Externo (Linha por Linha) - Usa índice 'i'
    for (int i = 0; i < tamanho_real; i++) {
        
        // 2. Loop Interno (Coluna por Coluna) - Usa índice 'j'
        for (int j = 0; j < tamanho_real; j++) {
            
            // 3. Acesso Direto com Colchetes []
            // Não precisa de asteriscos. O compilador faz a matemática.
            mat[i][j] = VALOR_MIN + (rand() % (VALOR_MAX - VALOR_MIN + 1));
        }
    }
}

void mostrarMatriz(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n){
    cout << "Mostrando toda a matriz: "<< endl;
    for (int i = 0; i < tamanho_n; i++) {
        for (int j = 0; j < tamanho_n; j++) {
            cout << "[" << matriz_n[i][j] << "] ";
        }
        cout << endl;
    }

}

void mostrarMatriz_dp(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n){
    cout << "Mostrando a diagonal principal: "<< endl;
    for (int i = 0; i < tamanho_n; i++) {
        for (int j = 0; j < tamanho_n; j++) {
            if (i == j)
            {
               cout << "[" << matriz_n[i][j] << "] ";
            }
            else
            cout << "[" << " " << "] ";
        }
        cout << endl;
    }
}

void mostrarMatriz_ds(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n){
    cout << "Mostrando a diagonal secundaria: "<< endl;
    for (int i = 0; i < tamanho_n; i++) {
        for (int j = 0; j < tamanho_n; j++) {
            if (i + j == tamanho_n - 1)
            {
               cout << "[" << matriz_n[i][j] << "] ";
            }
            else
            cout << "[" << " " << "] ";
        }
        cout << endl;
    }
}


void mostrarMatriz_elementos_fora_dp(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n){
    cout << "Mostrando elementos acima da diagonal principal: "<< endl;
    for (int i = 0; i < tamanho_n; i++) {
        for (int j = 0; j < tamanho_n; j++) {
            if (!(i == j))
            {
               cout << "[" << matriz_n[i][j] << "] ";
            }
            else
            cout << "[" << " " << "] ";
        }
        cout << endl;
    }
}

void mostrarMatriz_fora_ds(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n){
    cout << "Mostrando a diagonal secundaria: "<< endl;
    for (int i = 0; i < tamanho_n; i++) {
        for (int j = 0; j < tamanho_n; j++) {
            if (!(i + j == tamanho_n - 1))
            {
               cout << "[" << matriz_n[i][j] << "] ";
            }
            else
            cout << "[" << " " << "] ";
        }
        cout << endl;
    }
}

void menu_mostrarMatrizes(int matriz_n[TAMANHO_MAX_N][TAMANHO_MAX_N], int tamanho_n){
    int opcao = -1;

    do {
        cout << "\nEscolha uma opcao de exibicao dos valores:\n";
        cout << " 1 - Mostrar toda a matriz\n";
        cout << " 2 - Mostrar diagonal principal\n";
        cout << " 3 - Mostrar diagonal secundaria\n";
        cout << " 4 - Mostrar elementos fora da diagonal principal\n";
        cout << " 5 - Mostrar elementos fora da diagonal secundaria\n";
        cout << " 0 - Voltar / Sair do menu\n";
        cout << "> Opcao: ";
        cin >> opcao;

        if (cin.fail()) { // trata entrada invalida
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Tente novamente.\n";
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                mostrarMatriz(matriz_n, tamanho_n);
                break;
            case 2:
                mostrarMatriz_dp(matriz_n, tamanho_n);
                break;
            case 3:
                mostrarMatriz_ds(matriz_n, tamanho_n);
                break;
            case 4:
                mostrarMatriz_elementos_fora_dp(matriz_n, tamanho_n);
                break;
            case 5:
                mostrarMatriz_fora_ds(matriz_n, tamanho_n);
                break;
            case 0:
                cout << "Saindo do menu.\n";
                break;
            default:
                cout << "Opcao desconhecida. Tente novamente.\n";
                break;
        }
    } while (opcao != 0);
}