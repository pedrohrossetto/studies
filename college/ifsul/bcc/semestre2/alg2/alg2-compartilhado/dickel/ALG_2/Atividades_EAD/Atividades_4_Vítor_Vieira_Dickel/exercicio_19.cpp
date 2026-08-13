#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

float media(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

int cadastrar() {
    char nome;
    float n1, n2, n3;

    cin.ignore();
    cout << "Nome: ";
    cin >> nome;
    cout << "Nota 1: "; cin >> n1;
    cout << "Nota 2: "; cin >> n2;
    cout << "Nota 3: "; cin >> n3;

    ofstream arq("alunos.txt", ios::app);
    if (!arq) return 1;

    arq << nome << ";" << n1 << ";" << n2 << ";" << n3 << "\n";
    arq.close();
    return 0;
}

int mostrarTodos() {
    ifstream arq("alunos.txt");
    if (!arq) return 1;

    char linha[200];
    while (arq.getline(linha, 200)) {
        char* nome = strtok(linha, ";");
        float n1 = atof(strtok(NULL, ";"));
        float n2 = atof(strtok(NULL, ";"));
        float n3 = atof(strtok(NULL, ";"));
        cout << nome << " - Média: " << media(n1, n2, n3) << "\n";
    }
    arq.close();
    return 0;
}

int estatisticas() {
    ifstream arq("alunos.txt");
    if (!arq) return 1;

    char linha[200];
    float maior = 0, menor = 10, soma = 0;
    int qtd = 0;

    while (arq.getline(linha, 200)) {
        strtok(linha, ";");
        float n1 = atof(strtok(NULL, ";"));
        float n2 = atof(strtok(NULL, ";"));
        float n3 = atof(strtok(NULL, ";"));
        float m = media(n1, n2, n3);
        if (m > maior) maior = m;
        if (m < menor) menor = m;
        soma += m;
        qtd++;
    }

    if (qtd > 0) {
        cout << "Maior média: " << maior << "\n";
        cout << "Menor média: " << menor << "\n";
        cout << "Média da turma: " << soma / qtd << "\n";
    } else {
        cout << "Nenhum aluno cadastrado.\n";
    }

    arq.close();
    return 0;
}

int percentual() {
    ifstream arq("alunos.txt");
    if (!arq) return 1;

    char linha[200];
    int aprov = 0, reprov = 0;

    while (arq.getline(linha, 200)) {
        strtok(linha, ";");
        float n1 = atof(strtok(NULL, ";"));
        float n2 = atof(strtok(NULL, ";"));
        float n3 = atof(strtok(NULL, ";"));
        float m = media(n1, n2, n3);
        if (m >= 6) aprov++;
        else reprov++;
    }

    int total = aprov + reprov;
    if (total > 0) {
        cout << "Aprovados: " << (100.0 * aprov / total) << "%\n";
        cout << "Reprovados: " << (100.0 * reprov / total) << "%\n";
    } else {
        cout << "Nenhum aluno cadastrado.\n";
    }

    arq.close();
    return 0;
}

int main() {
    int op;
    do {
        cout << "\n0-Sair\n1-Cadastrar\n2-Mostrar\n3-Estatísticas\n4-Percentual\nOpção: ";
        cin >> op;
        if (op == 1) cadastrar();
        else if (op == 2) mostrarTodos();
        else if (op == 3) estatisticas();
        else if (op == 4) percentual();
    } while (op != 0);

    return 0;
}