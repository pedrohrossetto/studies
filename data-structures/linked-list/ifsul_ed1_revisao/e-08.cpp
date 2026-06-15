#include <iostream>
#include <fstream>
#include <cstring>
#include <istream>
#include <string> // Garantindo a inclusão para o std::string
#include "../../modules/lista_descritor_template.hpp"
#include "../../modules/utils.hpp"

using namespace std;


struct Pessoa {
    int codigo;
    int idade;
    float salario;
    string nome;

    // Correção: Utilização de lista de inicialização para evitar o sombreamento (shadowing) de variáveis
    Pessoa(int cod, int age, float s, string n) 
        : codigo(cod), idade(age), salario(s), nome(n) {}

    // Construtor padrão (necessário pois a estrutura 'No' faz 'new No<T>()')
    Pessoa() : codigo(0), idade(0), salario(0.00f), nome("") {}

    // Sobrecarga do operador << para que a função 'mostraL' saiba como imprimir uma Pessoa
    friend ostream& operator<<(ostream& os, const Pessoa& p) {
        os << "[Cod: " << p.codigo 
           << ", Nome: " << p.nome 
           << ", Idade: " << p.idade 
           << ", Salario: R$ " << p.salario << "]";
        return os;
    }
};

bool Inserir(Lista<Pessoa> *lista, int codigo,int idade, float salario, string nome);
void MostrarSalarioMedioPorFaixaEtaria(Lista<Pessoa> *lista1, Lista<Pessoa> *lista2);
void MostrarInterseccao(Lista<Pessoa> *lista1, Lista<Pessoa> *lista2);
void RemoverAcimaDeIdadeESalario(Lista<Pessoa> *lista, int idadeLimite, float salarioLimite);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Lista<Pessoa> lista1;
    Lista<Pessoa> lista2;

    
    Inserir(&lista1,1,18,1750.00,"Pedro");
    Inserir(&lista1,2,61,9750.00,"Henrique");
    Inserir(&lista1,3,51,7750.00,"Julio");
    Inserir(&lista2,1,52,5750.00,"Pedro");
    Inserir(&lista2,2,34,6750.00,"Rogerio");

    
    // Agora funcionará perfeitamente, pois o operador << foi sobrecarregado acima
    mostraL(&lista1);
    mostraL(&lista2);
    //MostrarSalarioMedioPorFaixaEtaria(&lista1,&lista2);
    MostrarInterseccao(&lista1,&lista2);

    
    // Boa prática: destruir a lista antes de encerrar o programa
    destroiL(&lista1);
    destroiL(&lista2);


    return 0;
}

///insere no in�cio da lista
bool Inserir(Lista<Pessoa> *lista, int codigo,int idade, float salario, string nome)
{
    No<Pessoa> *novo = new No<Pessoa>();
    if (novo == nullptr)
        return false;
    Pessoa pessoa(codigo,idade,salario,nome);
    novo->dado = pessoa;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}


/**
 * @brief Exibe media sarial por faixa etária
 * @details Realiza uma soma de cada elemento dentro das listas passadas utilizando a funcao "para cada elemento" no header
 * @tparam Listas que serao utilizadas
 * @return Nao retorna resultado, apenas exibe os valorre processados
 */

void MostrarSalarioMedioPorFaixaEtaria(Lista<Pessoa> *lista1, Lista<Pessoa> *lista2) {
    float somas[4] = {0.0f};
    int conts[4] = {0};
    const char* rótulos[4] = { "Ate 20 anos", "21 a 40 anos", "41 a 60 anos", "Mais de 60 anos" };
    // Definimos a regra de negócio em uma função Lambda moderna
    auto acumularDados = [&](const Pessoa& p) {
        int idx = (p.idade <= 20) ? 0 : (p.idade <= 40) ? 1 : (p.idade <= 60) ? 2 : 3;
        somas[idx] += p.salario;
        conts[idx]++;
    };

    // Aplicamos a regra nas listas de forma puramente declarativa
    paraCadaElemento(lista1, acumularDados);
    paraCadaElemento(lista2, acumularDados);

    // (O bloco de exibição dos resultados permanece o mesmo da Abordagem 1)
    // Exibição elegante e sem repetição de código
    std::cout << "\n--- Media Salarial por Faixa Etaria (Otimizado) ---\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << rótulos[i] << ": ";
        if (conts[i] > 0) {
            std::cout << "R$ " << (somas[i] / conts[i]) << "\n";
        } else {
            std::cout << "Nenhum registro.\n";
        }
    }
}

void MostrarInterseccao(Lista<Pessoa> *lista1, Lista<Pessoa> *lista2) {
    // Salvaguarda caso alguma das listas esteja nula ou vazia
    if (lista1 == nullptr || lista2 == nullptr || lista1->inicio == nullptr || lista2->inicio == nullptr) {
        std::cout << "Nenhuma pessoa foi encontrada em comum entre as listas.\n";
        return;
    }

    bool encontrou_algum = false;
    No<Pessoa>* atual1 = lista1->inicio;

    std::cout << "\n--- Interseccao de Nomes (Sem Repeticoes) ---\n";

    // Varre a primeira lista
    while (atual1 != nullptr) {
        string nome_atual = atual1->dado.nome;
        bool ja_processado = false;

        // 1. Verificação de Duplicatas: Olha para trás na própria lista1 
        // para saber se este nome já foi avaliado e impresso antes.
        No<Pessoa>* verificador = lista1->inicio;
        while (verificador != atual1) {
            if (verificador->dado.nome == nome_atual) {
                ja_processado = true;
                break; // Nome repetido dentro da L1, pula para não duplicar na saída
            }
            verificador = verificador->prox;
        }

        // Se o nome for inédito nesta varredura, procuramos na lista2
        if (!ja_processado) {
            No<Pessoa>* atual2 = lista2->inicio;
            bool existe_na_l2 = false;

            // 2. Busca de Intersecção: Procura o nome_atual dentro da lista2
            while (atual2 != nullptr) {
                if (atual2->dado.nome == nome_atual) {
                    existe_na_l2 = true;
                    break; // Encontrado na L2, não precisa continuar procurando
                }
                atual2 = atual2->prox;
            }

            // 3. Exibição: Se o nome está em ambas, exibe apenas o campo nome
            if (existe_na_l2) {
                std::cout << "- " << nome_atual << "\n";
                encontrou_algum = true;
            }
        }

        atual1 = atual1->prox; // Avança na lista1
    }

    // Caso o laço termine e nenhuma intersecção tenha ocorrido
    if (!encontrou_algum) {
        std::cout << "Nenhuma pessoa foi encontrada em comum entre as listas.\n";
    }
}
void RemoverAcimaDeIdadeESalario(Lista<Pessoa> *lista, int idadeLimite, float salarioLimite) {
    // Salvaguarda para lista nula ou vazia
    if (lista == nullptr || lista->inicio == nullptr) {
        return;
    }

    No<Pessoa>* anterior = nullptr;
    No<Pessoa>* atual = lista->inicio;

    while (atual != nullptr) {
        // Verifica se o registro atende AMBOS os critérios de exclusão
        if (atual->dado.idade > idadeLimite && atual->dado.salario > salarioLimite) {
            
            No<Pessoa>* noParaDeletar = atual;
            
            // Caso 1: O elemento está no início da lista
            if (anterior == nullptr) {
                lista->inicio = atual->prox;
                atual = lista->inicio; // O atual avança para o novo início
                
                // Se a lista ficou completamente vazia, atualiza o fim
                if (lista->inicio == nullptr) {
                    lista->fim = nullptr;
                }
            } 
            // Caso 2: O elemento está no meio ou no fim da lista
            else {
                anterior->prox = atual->prox;
                atual = atual->prox; // O atual avança para o próximo nó do encadeamento
                
                // Se o elemento removido era o último, atualiza o descritor 'fim'
                if (anterior->prox == nullptr) {
                    lista->fim = anterior;
                }
            }

            // Liberação de memória e ajuste do descritor
            delete noParaDeletar;
            lista->tamanho--;
        } 
        // Se o elemento NÃO atende ao critério de exclusão, apenas avançamos normalmente
        else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}