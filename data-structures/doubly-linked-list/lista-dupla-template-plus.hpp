#ifndef _HPP_LISTA_DUPLA_TEMPLATE
#define _HPP_LISTA_DUPLA_TEMPLATE

#include <stdexcept>
#include <iostream>

/**
 * @brief Estrutura que representa um nó de uma lista duplamente encadeada.
 * @tparam T Tipo de dado armazenado no nó.
 */
template<typename T>
struct No
{
    T dado;
    No<T> *prox;
    No<T> *ant;
    
    No() 
    {
        prox = nullptr;
        ant = nullptr;
    }
};

/**
 * @brief Descritor da lista duplamente encadeada.
 * @tparam T Tipo de dado dos elementos contidos na lista.
 */
template<typename T>
struct Lista
{
    No<T> *inicio;
    No<T> *fim;
    int tamanho;
    
    Lista() 
    {
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }

    // Bloqueia cópias acidentais que quebram o gerenciamento de memória na Heap
    Lista(const Lista&) = delete;
    Lista& operator=(const Lista&) = delete;
};

/**
 * @brief Desaloca completamente a memória de todos os nós da lista.
 */
template<typename T>
void destroiL(Lista<T> *l)
{
    if (l == nullptr) return;

    No<T> *n = l->inicio;
    while(n)
    {
        No<T> *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = nullptr;
    l->inicio = nullptr;
    l->tamanho = 0;
}

/**
 * @brief Verifica se a lista está vazia.
 */
template<typename T>
bool vaziaL(const Lista<T> *lista)
{
    return lista == nullptr || lista->inicio == nullptr;
}

/**
 * @brief Imprime a lista do início para o fim.
 */
template<typename T>
void mostraL(const Lista<T> *lista)
{
    if (lista == nullptr) return;

    No<T> *n = lista->inicio;
    std::cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        std::cout << n->dado;
        n = n->prox;
        if(n) std::cout << ", ";
    }
    std::cout << "}\n";
}

/**
 * @brief Imprime a lista do fim para o início usando os ponteiros anteriores.
 */
template<typename T>
void mostrarInversoL(const Lista<T> *lista)
{
    if (lista == nullptr) return;

    No<T> *n = lista->fim;
    std::cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        std::cout << n->dado;
        n = n->ant;
        if(n) std::cout << ", ";
    }
    std::cout << "}\n";
}

/**
 * @brief Insere um elemento no início da lista.
 */
template<typename T>
bool insereInicioL(Lista<T> *lista, T valor)
{
    if (lista == nullptr) return false;

    No<T> *novo = new No<T>();
    if (!novo) return false;

    novo->dado = valor;
    novo->ant = nullptr;
    novo->prox = lista->inicio;

    if (vaziaL(lista)) 
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;
    return true;
}

/**
 * @brief Insere um elemento no fim da lista.
 */
template<typename T>
bool insereFimL(Lista<T> *lista, T valor)
{
    if (lista == nullptr) return false;

    No<T> *novo = new No<T>();
    if (!novo) return false;

    novo->dado = valor;
    novo->ant = lista->fim;
    novo->prox = nullptr;

    if (vaziaL(lista)) 
        lista->inicio = novo;
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;
    return true;
}

/**
 * @brief Remove o primeiro nó da lista e retorna o valor que estava armazenado nele.
 */
template<typename T>
T removePrimeiroNo(Lista<T> *lista)
{
    if (vaziaL(lista)) {
        throw std::underflow_error("Erro: Tentativa de remover um elemento de uma lista vazia.");
    }

    No<T> *aux = lista->inicio; 
    T retorno_t = aux->dado;

    if (lista->inicio == lista->fim) {
        lista->inicio = nullptr;
        lista->fim = nullptr;
    }
    else {
        lista->inicio = lista->inicio->prox; 
        lista->inicio->ant = nullptr;
    }

    lista->tamanho--;
    delete aux;
    return retorno_t;
}

/**
 * @brief Remove o último nó da lista e retorna o valor que estava armazenado nele.
 */
template<typename T>
T removeUltimoNo(Lista<T> *lista)
{
    if (vaziaL(lista)) {
        throw std::underflow_error("Erro: Tentativa de remover um elemento de uma lista vazia.");
    }

    No<T> *aux = lista->fim; 
    T retorno_t = aux->dado;

    if (lista->inicio == lista->fim) {
        lista->inicio = nullptr;
        lista->fim = nullptr;
    }
    else {
        lista->fim = lista->fim->ant; 
        lista->fim->prox = nullptr;
    }

    lista->tamanho--;
    delete aux;
    return retorno_t;
}

/**
 * @brief Busca linear por um valor na lista a partir do início.
 */
template<typename T>
No<T>* buscaL(const Lista<T> *lista, T valor)
{
    if (lista == nullptr) return nullptr;

    No<T> *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;
        n = n->prox;
    }
    return nullptr;
}

/**
 * @brief Remove da lista um nó específico passando diretamente o seu ponteiro.
 */
template<typename T>
bool removerNoL(Lista<T> *lista, No<T> *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (no == lista->inicio) 
    {
        lista->inicio = no->prox;
        if (lista->inicio == nullptr) 
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;
    }
    else if (no == lista->fim) 
    {
        lista->fim = no->ant;
        lista->fim->prox = nullptr;
    }
    else 
    { 
        no->ant->prox = no->prox;
        no->prox->ant = no->ant;
    }

    lista->tamanho--;
    delete no;
    return true;
}

/**
 * @brief Remove a primeira ocorrência do valor especificado na lista.
 */
template<typename T>
bool removeL(Lista<T> *lista, T valor)
{
    No<T>* no = buscaL(lista, valor);
    if(!no) return false;

    return removerNoL(lista, no);
}

/**
 * @brief Executa uma ação personalizada para cada elemento da lista.
 */
template <typename T, typename Func>
void paraCadaElemento(const Lista<T>* lista, Func acao) 
{
    if (lista == nullptr) return;
    No<T>* atual = lista->inicio;
    while (atual != nullptr) {
        acao(atual->dado); 
        atual = atual->prox;
    }
}

/**
 * @brief Insere um elemento na lista mantendo-a ordenada.
 * @details Requer que o tipo T possua a sobrecarga do operador '<'.
 */
template<typename T>
bool insereOrdenadoL(Lista<T> *lista, T valor)
{
    if (lista == nullptr) return false;

    // Se estiver vazia ou o valor for menor que o primeiro, insere no início
    if (vaziaL(lista) || valor < lista->inicio->dado) {
        return insereInicioL(lista, valor);
    }
    
    // Se o valor for maior ou igual ao do último nó, insere no fim
    if (!(valor < lista->fim->dado)) {
        return insereFimL(lista, valor);
    }

    // Varre para encontrar a posição correta de inserção no meio da lista
    No<T> *atual = lista->inicio;
    while (atual != nullptr && !(valor <  atual->dado)) {
        atual = atual->prox;
    }

    No<T> *novo = new No<T>();
    if (!novo) return false;
    novo->dado = valor;

    // Ajusta os ponteiros para encaixar o novo nó antes do nó 'atual'
    novo->prox = atual;
    novo->ant = atual->ant;
    atual->ant->prox = novo;
    atual->ant = novo;

    lista->tamanho++;
    return true;
}

/**
 * @brief Inverte a ordem de todos os elementos da lista rearranjando os ponteiros internos.
 * @details Executa em tempo linear O(N) de forma in-place (sem alocação extra).
 */
template<typename T>
void inverterL(Lista<T> *lista)
{
    if (lista == nullptr || vaziaL(lista) || lista->inicio == lista->fim) return;

    No<T> *atual = lista->inicio;
    No<T> *temp = nullptr;

    // Troca os ponteiros prox e ant de cada nó da lista
    while (atual != nullptr) {
        temp = atual->ant;
        atual->ant = atual->prox;
        atual->prox = temp;
        atual = atual->ant; // Como invertemos, o 'ant' agora aponta para o que costumava ser o próximo
    }

    // Ajusta os ponteiros de controle do descritor
    temp = lista->inicio;
    lista->inicio = lista->fim;
    lista->fim = temp;
}

/**
 * @brief Remove nós da lista que atendam a uma condição enviada via função ou lambda.
 */
template <typename T, typename Predicado>
int removerSeL(Lista<T> *lista, Predicado criterio)
{
    if (lista == nullptr || vaziaL(lista)) return 0;

    No<T> *atual = lista->inicio;
    int removidos = 0;

    while (atual != nullptr) {
        No<T> *proximoNo = atual->prox; // Salva o próximo antes que o atual seja deletado

        if (criterio(atual->dado)) {
            removerNoL(lista, atual);
            removidos++;
        }
        atual = proximoNo;
    }
    return removidos;
}

#endif // _HPP_LISTA_DUPLA_TEMPLATE