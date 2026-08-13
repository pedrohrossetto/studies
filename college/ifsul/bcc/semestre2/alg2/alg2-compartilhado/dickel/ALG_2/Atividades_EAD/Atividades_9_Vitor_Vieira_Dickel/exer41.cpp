#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio> // Usado para operações simples de entrada/saída (limpeza de buffer)

using namespace std;

// --- 1. ESTRUTURA E CONSTANTES ---

const int MAX_ALUNOS = 25;
const int TAM_NOME = 50;

struct Aluno {
    int matricula;
    char nome[TAM_NOME];
    float media;
};

// --- 2. GESTÃO DE MEMÓRIA E ESTADO (Ponteiros Globais) ---

Aluno *p_alunos = new Aluno[MAX_ALUNOS];
int *p_contagem = new int(0);

// --- 3. PROTÓTIPOS E MAIN ---

void menu(int *opcao);
void cadastrar(Aluno *p_arr_alunos, int *p_cont);
void mostrar_todos(const Aluno *p_arr_alunos, const int *p_cont);
void listar_medias(const Aluno *p_arr_alunos, const int *p_cont);
void pesquisar_aluno(const Aluno *p_arr_alunos, const int *p_cont);

int main() {
    int *p_opcao = new int(0); 

    do {
        menu(p_opcao);
        
        switch (*p_opcao) {
            case 1: cadastrar(p_alunos, p_contagem); break;
            case 2: mostrar_todos(p_alunos, p_contagem); break;
            case 3: listar_medias(p_alunos, p_contagem); break;
            case 4: pesquisar_aluno(p_alunos, p_contagem); break;
            case 0: cout << "\nSaindo. Memória liberada.\n"; break;
            default: cout << "Opcao invalida.\n";
        }
    } while (*p_opcao != 0);

    delete[] p_alunos;
    delete p_contagem;
    delete p_opcao;
    
    return 0;
}

// --- 4. IMPLEMENTAÇÃO DAS FUNÇÕES ---

void menu(int *opcao) {
    cout << "\n--- MENU ---\n0-Sair\n1-Cadastrar\n2-Mostrar\n3-Listar Medias\n4-Pesquisar\nOpcao: ";
    if (!(cin >> *opcao)) {
        cin.clear();
        // Alternativa simples de limpeza de buffer
        while (cin.get() != '\n') continue;
        *opcao = -1; 
    }
}

void cadastrar(Aluno *p_arr_alunos, int *p_cont) {
    if (*p_cont >= MAX_ALUNOS) {
        cout << "Limite de " << MAX_ALUNOS << " alunos atingido.\n";
        return;
    }

    Aluno *p_novo_aluno = &p_arr_alunos[*p_cont]; 

    cout << "\n--- CADASTRO ALUNO " << (*p_cont) + 1 << " ---\n";

    cout << "Matrícula: ";
    if (!(cin >> p_novo_aluno->matricula)) {
        cin.clear(); cin.ignore(256, '\n'); 
        cout << "Entrada inválida. Cancelado.\n"; return;
    }
    
    // Limpeza de buffer (simplificada)
    cin.ignore(256, '\n'); 

    cout << "Nome: ";
    cin.getline(p_novo_aluno->nome, TAM_NOME);

    cout << "Média: ";
    if (!(cin >> p_novo_aluno->media)) {
        cin.clear(); cin.ignore(256, '\n');
        cout << "Entrada inválida. Cancelado.\n"; return;
    }

    (*p_cont)++;
    cout << "Aluno cadastrado.\n";
}

void mostrar_todos(const Aluno *p_arr_alunos, const int *p_cont) {
    if (*p_cont == 0) {
        cout << "\nNenhum aluno cadastrado.\n"; return;
    }

    cout << "\n--- LISTA DE ALUNOS (" << *p_cont << ") ---\n";
    
    for (int i = 0; i < *p_cont; ++i) {
        cout << "M: " << p_arr_alunos[i].matricula << " | Nome: " << p_arr_alunos[i].nome 
             << " | Média: " << fixed << setprecision(2) << p_arr_alunos[i].media << "\n";
    }
}

void listar_medias(const Aluno *p_arr_alunos, const int *p_cont) {
    if (*p_cont == 0) {
        cout << "\nNenhum aluno cadastrado.\n"; return;
    }

    const Aluno *p_maior = p_arr_alunos;
    const Aluno *p_menor = p_arr_alunos;

    for (int i = 1; i < *p_cont; ++i) {
        const Aluno *p_aluno_atual = p_arr_alunos + i; 
        
        if (p_aluno_atual->media > p_maior->media) p_maior = p_aluno_atual;
        if (p_aluno_atual->media < p_menor->media) p_menor = p_aluno_atual;
    }

    cout << "\n--- MAIOR E MENOR MÉDIA ---\n" << fixed << setprecision(2);
    
    cout << "MAIOR (" << p_maior->media << "): M: " << p_maior->matricula << " | Nome: " << p_maior->nome << "\n";
    cout << "MENOR (" << p_menor->media << "): M: " << p_menor->matricula << " | Nome: " << p_menor->nome << "\n";
}

void pesquisar_aluno(const Aluno *p_arr_alunos, const int *p_cont) {
    if (*p_cont == 0) {
        cout << "\nNenhum aluno cadastrado.\n"; return;
    }
    
    int *p_matricula_busca = new int(0); 

    cout << "\nMatrícula para pesquisar: ";
    if (!(cin >> *p_matricula_busca)) {
        cin.clear(); cin.ignore(256, '\n');
        cout << "Entrada inválida.\n"; delete p_matricula_busca; return;
    }

    const Aluno *p_aluno_encontrado = nullptr;
    
    for (int i = 0; i < *p_cont; ++i) {
        if (p_arr_alunos[i].matricula == *p_matricula_busca) {
            p_aluno_encontrado = &p_arr_alunos[i];
            break;
        }
    }

    delete p_matricula_busca; 

    if (p_aluno_encontrado) {
        cout << "\n--- ENCONTRADO ---\n";
        cout << "M: " << p_aluno_encontrado->matricula << " | Nome: " << p_aluno_encontrado->nome 
             << " | Média: " << fixed << setprecision(2) << p_aluno_encontrado->media << "\n";
    } else {
        cout << "Aluno não cadastrado\n";
    }
}