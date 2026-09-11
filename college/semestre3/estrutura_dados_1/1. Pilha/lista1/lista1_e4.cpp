#include <iostream>
#include <ctime>   
#include <cstdlib> 
#include "../modules/vetor_dinamico.hpp"
#include "../modules/utils.hpp"


using namespace std;

struct Aluno
{
        string nome;
        int matricula;
        float nota_final;

        Aluno()
        {
            nome = "";
            matricula = 0;
            nota_final = 0.0;

        }
        Aluno(string n, int matr, float nota){
            nome = n;
            matricula = matr;
            nota_final = nota;
        }
};


int main(){
    int quantidade_alunos;
    do
    {
        cout << "Informe a quantidade de alunos (1 - 10): \n";
        cin >> quantidade_alunos;
    }   while (quantidade_alunos < 1 or quantidade_alunos > 10);
    

    Aluno* turma = new Aluno[quantidade_alunos];
    for (int i = 0; i < quantidade_alunos; i++)
    {
        // Variáveis temporárias para coletar os dados para permitir chamar o construtor com parametros
        int m;
        string n;
        float nf;
        pausar_e_limpar();

        cout << "\n--- Cadastro do Aluno " << i + 1 << " ---" << endl;

        cout << "Matricula: ";
        cin >> m;
        
        cin.ignore(); // Limpa o buffer antes do getline
        cout << "Nome: ";
        getline(cin, n);

        cout << "Nota Final: ";
        cin >> nf;


        // h. Utilizando o construtor com parâmetros para instanciar o objeto
        // Isso sobrescreve o objeto padrão criado pelo new[]
        turma[i] = Aluno(n, m, nf);
    }
    pausar_e_limpar();

    cout << "\n========== LISTA DE ALUNOS ==========" << endl;
    for (int i = 0; i < quantidade_alunos; i++) {
        cout << "ID: " << turma[i].matricula 
             << " | Nome: " << turma[i].nome 
             << " | Nota: " << turma[i].nota_final << endl;
    }

    delete[] turma;
    turma = nullptr;

    cout << "\nMemoria liberada com sucesso." << endl;

    return 0;

    }
    



