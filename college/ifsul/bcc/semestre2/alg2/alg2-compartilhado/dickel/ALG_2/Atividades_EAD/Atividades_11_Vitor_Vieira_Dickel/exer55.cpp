#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

void carregarArquivo(const char* nome, int*& vet, int& qtd) {
    ifstream arq(nome);
    if (!arq) {
        qtd = 0;
        vet = NULL;
        return;
    }
    int valor;
    qtd = 0;
    while (arq >> valor) {
        if (arq.peek() == ';') arq.ignore();
        qtd++;
    }
    vet = (int*) malloc(qtd * sizeof(int));
    arq.clear();
    arq.seekg(0);
    int i = 0;
    while (arq >> *(vet + i)) {
        if (arq.peek() == ';') arq.ignore();
        i++;
    }
    arq.close();
}

void salvarArquivo(const char* nome, int* vet, int qtd) {
    ofstream arq(nome);
    for (int i = 0; i < qtd; i++) {
        arq << *(vet + i);
        if (i < qtd - 1) arq << ";";
    }
    arq.close();
}

void incluirElemento(const char* nome, int*& vet, int& qtd) {
    int novo;
    cout << "Digite o valor a incluir: ";
    cin >> novo;
    int* novoVet = (int*) malloc((qtd + 1) * sizeof(int));
    for (int i = 0; i < qtd; i++) {
        *(novoVet + i) = *(vet + i);
    }
    *(novoVet + qtd) = novo;
    free(vet);
    vet = novoVet;
    qtd++;
    salvarArquivo(nome, vet, qtd);
}

void intersecao(int* vet1, int qtd1, int* vet2, int qtd2) {
    if (qtd1 == 0 || qtd2 == 0) {
        cout << "Vetores vazios! Operacao invalida." << endl;
        return;
    }
    int cont = 0;
    for (int i = 0; i < qtd1; i++) {
        for (int j = 0; j < qtd2; j++) {
            if (*(vet1 + i) == *(vet2 + j)) {
                cont++;
            }
        }
    }
    if (cont == 0) {
        cout << "Nao ha elementos em comum." << endl;
        return;
    }
    int* vet3 = (int*) malloc(cont * sizeof(int));
    int k = 0;
    for (int i = 0; i < qtd1; i++) {
        for (int j = 0; j < qtd2; j++) {
            if (*(vet1 + i) == *(vet2 + j)) {
                *(vet3 + k) = *(vet1 + i);
                k++;
            }
        }
    }
    salvarArquivo("vet3.txt", vet3, cont);
    free(vet3);
    cout << "Arquivo vet3.txt criado com intersecao." << endl;
}

void mostrarOrdenado(int* vet1, int qtd1, int* vet2, int qtd2) {
    if (qtd1 == 0 && qtd2 == 0) {
        cout << "Vetores vazios!" << endl;
        return;
    }
    int total = qtd1 + qtd2;
    int* todos = (int*) malloc(total * sizeof(int));
    int i;
    for (i = 0; i < qtd1; i++) {
        *(todos + i) = *(vet1 + i);
    }
    for (int j = 0; j < qtd2; j++) {
        *(todos + i) = *(vet2 + j);
        i++;
    }

    for (int a = 0; a < total - 1; a++) {
        for (int b = a + 1; b < total; b++) {
            if (*(todos + a) > *(todos + b)) {
                int tmp = *(todos + a);
                *(todos + a) = *(todos + b);
                *(todos + b) = tmp;
            }
        }
    }

    for (int x = 0; x < total; x++) {
        cout << *(todos + x);
        if (x < total - 1) cout << ", ";
    }
    cout << endl;
    free(todos);
}

int main() {
    int* vet1 = NULL;
    int* vet2 = NULL;
    int qtd1 = 0, qtd2 = 0;
    int op;

    carregarArquivo("vet1.txt", vet1, qtd1);
    carregarArquivo("vet2.txt", vet2, qtd2);

    do {
        cout << "\n0 - Sair\n1 - Incluir no vetor 1\n2 - Incluir no vetor 2\n3 - Intersecao\n4 - Mostrar Ordenado\nOpcao: ";
        cin >> op;

        if (op == 1)
            incluirElemento("vet1.txt", vet1, qtd1);
        else if (op == 2)
            incluirElemento("vet2.txt", vet2, qtd2);
        else if (op == 3)
            intersecao(vet1, qtd1, vet2, qtd2);
        else if (op == 4)
            mostrarOrdenado(vet1, qtd1, vet2, qtd2);
        else if (op != 0)
            cout << "Opcao invalida!" << endl;

    } while (op != 0);

    free(vet1);
    free(vet2);
    return 0;
}