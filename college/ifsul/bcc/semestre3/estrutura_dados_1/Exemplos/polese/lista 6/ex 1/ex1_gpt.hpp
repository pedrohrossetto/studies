#ifndef _HPP_FILA
#define _HPP_FILA

#include <iostream>
#include <string>

using namespace std;

struct imp
{
    string nome;
    int qtd_pg;
};

struct Fila
{
    int tam;
    int total;
    int inicio;
    int fim;
    imp *dados;

    Fila()
    {
        tam = 0;
        total = 0;
        inicio = 0;
        fim = 0;
        dados = nullptr;
    }
};

void inicializaF(Fila *f, int tam)
{
    if (f->dados != nullptr)
        delete[] f->dados; // Libera se já existia
    f->tam = tam;
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->dados = new imp[tam];
}

bool verificaInicializacaoF(Fila *f)
{
    return (f->dados != nullptr);
}

bool vaziaF(Fila *f)
{
    return (f->total == 0);
}

bool cheiaF(Fila *f)
{
    return (f->total == f->tam);
}

// Enqueue
bool enfileiraF(Fila *f, imp valor)
{
    if (!verificaInicializacaoF(f) || cheiaF(f))
        return false;

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->tam; // Lógica circular correta
    f->total++;
    return true;
}

// Dequeue
imp ImprimirDoc(Fila *f)
{
    if (vaziaF(f))
        return {"", 0};

    imp removido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->tam; // Lógica circular correta
    f->total--;

    // Conforme o exercício, imprimir o dado removido
    cout << "Imprimindo: " << removido.nome << " (" << removido.qtd_pg << " pag)" << endl;
    return removido;
}

void Enfileirar(Fila *f, string nome, int qtd_pg)
{
    imp novo = {nome, qtd_pg};
    if (!enfileiraF(f, novo))
    {
        // O erro de "Cheia" ou "Não Inicializada" deve ser tratado conforme a regra
    }
}

// CORRIGIDO: Retorna a soma das páginas, não a quantidade de docs
int TotalPag(Fila *f)
{
    if (!verificaInicializacaoF(f) || vaziaF(f))
        return 0;

    int soma = 0;
    for (int i = 0; i < f->total; i++)
    {
        int indice = (f->inicio + i) % f->tam; // Mapeamento circular
        soma += f->dados[indice].qtd_pg;
    }
    return soma;
}

// CORRIGIDO: Percorre de forma circular
void MostraTudo(Fila *f, string nomeFila)
{
    if (!verificaInicializacaoF(f))
    {
        cout << "ERRO: inicializar fila " << nomeFila << endl;
        return;
    }
    if (vaziaF(f))
    {
        cout << "FILA VAZIA" << endl;
        return;
    }

    for (int i = 0; i < f->total; i++)
    {
        int indice = (f->inicio + i) % f->tam;
        cout << "[" << f->dados[indice].nome << " - " << f->dados[indice].qtd_pg << "p] ";
    }
    cout << endl;
}

// Novo: Função Consultar exigida pela lista
bool Consultar(Fila *f, string nomeDoc)
{
    if (!verificaInicializacaoF(f) || vaziaF(f))
        return false;

    for (int i = 0; i < f->total; i++)
    {
        int indice = (f->inicio + i) % f->tam;
        if (f->dados[indice].nome == nomeDoc)
        {
            cout << "Documento " << nomeDoc << " encontrado na posicao " << i + 1 << endl;
            return true;
        }
    }
    return false;
}

#endif