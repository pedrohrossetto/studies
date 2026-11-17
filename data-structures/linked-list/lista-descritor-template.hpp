#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

#include <iostream>

/**
 * @brief Estrutura que representa um nó da lista encadeada.
 * @tparam T Tipo de dado que o nó irá armazenar.
 */
template <typename T>
struct No
{
    T dado; 
    No<T> *prox;
    
    No() 
    {
        prox = nullptr;
    }
};

/**
 * @brief Estrutura do descritor da lista, que armazena os ponteiros
 * para o início, fim e a quantidade de elementos.
 * @tparam T Tipo de dado dos elementos contidos na lista.
 */
template <typename T>
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
};

/**
 * @brief Imprime na tela todos os elementos da lista no formato L:[tamanho]{e1, e2, ...}.
 * @details Percorre a lista a partir do ponteiro 'inicio' até encontrar o nullptr,
 * exibindo o valor de cada nó separado por vírgulas.
 * @tparam T Tipo do elemento da lista.
 * @param lista Ponteiro para o descritor da lista a ser exibida.
 */
template <typename T>
void mostraL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;

    std::cout << "L:[" << lista->tamanho << "]{";
    while(n != nullptr) 
    {
        std::cout << n->dado;
        n = n->prox;

        if(n != nullptr)
            std::cout << ", ";
    }
    std::cout << "}\n";
}

/**
 * @brief Desaloca a memória de todos os nós da lista, deixando-a vazia.
 * @details Remove sequencialmente cada nó utilizando um ponteiro auxiliar para
 * não perder a referência do próximo elemento. Ao final, redefine os
 * ponteiros do descritor para nullptr e o tamanho para zero.
 * @tparam T Tipo do elemento da lista.
 * @param lista Ponteiro para o descritor da lista que será destruída.
 */
template <typename T>
void destroiL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;
    while(n != nullptr)
    {
        No<T> *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = nullptr;
    lista->fim = nullptr;
    lista->tamanho = 0;
}

/**
 * @brief Verifica se a lista está desprovida de elementos.
 * @tparam T Tipo do elemento da lista.
 * @param lista Ponteiro para o descritor da lista.
 * @return true Se o ponteiro 'inicio' for nulo (lista vazia).
 * @return false Se a lista contiver ao menos um elemento.
 */
template <typename T>
bool vaziaL(Lista<T> *lista)
{
    return lista->inicio == nullptr;
}

/**
 * @brief Insere um novo elemento no início da lista.
 * @details Aloca um novo nó, atribui o valor a ele, faz com que o seu ponteiro 
 * 'prox' aponte para o antigo início e atualiza o descritor. Se for o 
 * primeiro elemento inserido, o ponteiro 'fim' também é atualizado.
 * @tparam T Tipo do elemento a ser inserido.
 * @param lista Ponteiro para o descritor da lista.
 * @param valor O dado de tipo T que será armazenado no novo nó.
 * @return true Se a alocação de memória foi bem-sucedida e a inserção realizada.
 * @return false Se falhou a alocação de memória para o novo nó.
 */
template <typename T>
bool insereInicioL(Lista<T> *lista, T valor)
{
    No<T> *novo = new No<T>();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}

/**
 * @brief Insere um novo elemento no final da lista.
 * @details Aloca um novo nó e ajusta os ponteiros. Graças ao descritor que mantém
 * o ponteiro 'fim', a inserção ocorre de forma direta (tempo constante), 
 * sem a necessidade de varrer toda a lista.
 * @tparam T Tipo do elemento a ser inserido.
 * @param lista Ponteiro para o descritor da lista.
 * @param valor O dado de tipo T que será adicionado ao final.
 * @return true Se a inserção foi realizada com sucesso.
 * @return false Se faltou memória para o novo nó.
 */
template <typename T>
bool insereFimL(Lista<T> *lista, T valor)
{
    No<T> *novo = new No<T>();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = nullptr;

    if(vaziaL(lista))
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}

/**
 * @brief Remove a primeira ocorrência de um determinado valor na lista.
 * @details Varre a lista com dois ponteiros ('atual' e 'anterior') procurando o valor.
 * Caso o encontre, ajusta os ponteiros para "saltar" o nó a ser excluído,
 * trata as exceções de remoção no início ou no fim para manter o descritor 
 * correto, decrementa o tamanho e libera a memória do nó.
 * @tparam T Tipo do elemento da lista.
 * @param lista Ponteiro para o descritor da lista.
 * @param valor O valor que se deseja remover.
 * @return true Se o elemento foi encontrado e removido com sucesso.
 * @return false Se o elemento não foi encontrado na lista.
 */
template <typename T>
bool removeL(Lista<T> *lista, T valor)
{
    No<T> *anterior = nullptr;
    No<T> *atual = lista->inicio;
    
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    
    if(!atual) 
        return false;
        
    if (!anterior) 
    {
        lista->inicio = atual->prox;
        if (!lista->inicio) 
            lista->fim = lista->inicio;
    }
    else   
    {
        anterior->prox = atual->prox;
        if (!atual->prox)
            lista->fim = anterior;
    }
    
    lista->tamanho--;
    delete(atual);
    return true;
}

/**
 * @brief Busca por um elemento específico na lista.
 * @details Realiza uma busca linear a partir do início da lista comparando o campo
 * 'dado' com o valor procurado.
 * @tparam T Tipo do elemento da lista.
 * @param lista Ponteiro para o descritor da lista.
 * @param valor O valor de tipo T que está sendo buscado.
 * @return No<T>* Ponteiro para o nó que contém o valor, ou 'nullptr' caso não seja encontrado.
 */
template <typename T>
No<T>* buscaL(Lista<T> *lista, T valor)
{
    No<T> *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}


template <typename T, typename Func>
void paraCadaElemento(Lista<T>* lista, Func acao) {
    if (lista == nullptr) return;
    No<T>* atual = lista->inicio;
    while (atual != nullptr) {
        acao(atual->dado); // Executa uma função personalizada passando o dado
        atual = atual->prox;
    }
}

/**
 * @brief Exibe os elementos que estão presentes em ambas as listas, sem repetições.
 * @details Compara os elementos diretamente usando o operador '=='. Varre a lista1,
 * garante que o elemento é inédito para evitar duplicatas na saída, e verifica 
 * se ele possui um par correspondente na lista2.
 * @tparam T Tipo genérico dos elementos das listas (deve suportar o operador ==).
 * @param lista1 Ponteiro para o descritor da primeira lista.
 * @param lista2 Ponteiro para o descritor da segunda lista.
 */
template <typename T>
void MostrarInterseccao(Lista<T> *lista1, Lista<T> *lista2) {
    // Salvaguarda caso alguma das listas esteja nula ou vazia
    if (lista1 == nullptr || lista2 == nullptr || lista1->inicio == nullptr || lista2->inicio == nullptr) {
        std::cout << "Nenhuma pessoa foi encontrada em comum entre as listas.\n";
        return;
    }

    bool encontrou_algum = false;
    No<T>* atual1 = lista1->inicio;

    std::cout << "\n--- Intersecção (Sem Repetições) ---\n";

    while (atual1 != nullptr) {
        // T_atual guarda o valor genérico (pode ser int, string ou Pessoa)
        T dado_atual = atual1->dado;
        bool ja_processado = false;

        // 1. Verificação de Duplicatas na própria lista1
        No<T>* verificador = lista1->inicio;
        while (verificador != atual1) {
            if (verificador->dado == dado_atual) { // Uso do operador == genérico
                ja_processado = true;
                break; 
            }
            verificador = verificador->prox;
        }

        // Se o elemento for inédito, procuramos na lista2
        if (!ja_processado) {
            No<T>* atual2 = lista2->inicio;
            bool existe_na_l2 = false;

            // 2. Busca de Intersecção na lista2
            while (atual2 != nullptr) {
                if (atual2->dado == dado_atual) { // Uso do operador == genérico
                    existe_na_l2 = true;
                    break; 
                }
                atual2 = atual2->prox;
            }

            // 3. Exibição: O operador << deve estar preparado para o tipo T
            if (existe_na_l2) {
                std::cout << "- " << dado_atual << "\n";
                encontrou_algum = true;
            }
        }

        atual1 = atual1->prox; 
    }

    if (!encontrou_algum) {
        std::cout << "Nenhuma pessoa foi encontrada em comum entre as listas.\n";
    }
}

#endif // _HPP_LISTA_DESCRITOR