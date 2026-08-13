#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

// Importante: certifique-se que as funções no .hpp aceitam os parâmetros abaixo
#include "ex1_gpt.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    // Inicializamos os ponteiros como NULL para verificar se foram alocados
    // Se sua struct Fila não usa ponteiros internos, você precisará de um
    // marcador booleano como 'bool p1_inicializada = false;'
    Fila p1;
    Fila n1;

    // Sugestão: inicialize o controle de inicialização
    bool inicializada = false;

    string OP;
    ifstream arq("arq.txt");

    if (!arq.is_open())
    {
        cout << "Erro ao abrir o arquivo arq.txt" << endl;
        return 1;
    }

    string linha;
    while (getline(arq, linha))
    {
        if (linha.empty())
            continue; // Ignora linhas vazias

        stringstream strBuffer(linha);
        strBuffer >> OP;

        if (OP == "INICIALIZAR")
        {
            int tam;
            strBuffer >> tam;

            // Se já foi inicializada antes, a lógica de liberar memória
            // deve estar dentro da sua função inicializaF ou chamada antes
            inicializaF(&p1, tam);
            inicializaF(&n1, tam);
            inicializada = true;
            cout << "A fila P e N foram inicializadas com o tamanho " << tam << endl;
        }
        else if (OP == "MOSTRAR")
        {
            string F;
            strBuffer >> F;
            if (!inicializada)
            {
                cout << "ERRO: inicializar fila " << F << endl;
            }
            else
            {
                if (F == "P")
                {
                    if (vaziaF(&p1))
                        cout << "FILA VAZIA" << endl;
                    else
                        MostraTudo(&p1, "P");
                }
                else
                {
                    if (vaziaF(&n1))
                        cout << "FILA VAZIA" << endl;
                    else
                        MostraTudo(&n1, "N");
                }
            }
        }
        else if (OP == "IMPRIMIRDOC")
        {
            if (!inicializada)
            {
                cout << "ERRO: inicializar fila P/N" << endl;
            }
            else
            {
                // Política: Prioridade para P
                if (!vaziaF(&p1))
                {
                    ImprimirDoc(&p1);
                }
                else if (!vaziaF(&n1))
                {
                    ImprimirDoc(&n1);
                }
                else
                {
                    cout << "NÃO há documentos para imprimir" << endl;
                }
            }
        }
        else if (OP == "ENFILEIRARDOC")
        {
            string nome, F;
            int qtd_pg;
            strBuffer >> nome >> qtd_pg >> F;

            if (!inicializada)
            {
                cout << "ERRO: inicializar fila " << F << endl;
            }
            else
            {
                // Verifica se está cheia antes de enfileirar
                Fila *destino = (F == "P") ? &p1 : &n1;
                if (cheiaF(destino))
                {
                    cout << "FILA CHEIA" << endl;
                }
                else
                {
                    Enfileirar(destino, nome, qtd_pg);
                }
            }
        }
        else if (OP == "TOTALPAG")
        {
            if (!inicializada)
            {
                cout << "ERRO: inicializar filas" << endl;
            }
            else
            {
                int soma = TotalPag(&n1) + TotalPag(&p1);
                cout << soma << " página(s)" << endl;
            }
        }
        else if (OP == "CONSULTAR")
        {
            string nome, F;
            strBuffer >> nome >> F;

            if (!inicializada)
            {
                cout << "ERRO: inicializar fila " << F << endl;
            }
            else
            {
                Fila *alvo = (F == "P") ? &p1 : &n1;
                if (vaziaF(alvo))
                {
                    cout << "FILA VAZIA" << endl;
                }
                else
                {
                    // Chame sua função de busca/consulta
                    bool achou = Consultar(alvo, nome);
                    if (!achou)
                        cout << "Documento não encontrado" << endl;
                }
            }
        }
    }
    arq.close();
    return 0;
}