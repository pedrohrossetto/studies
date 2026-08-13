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

    // Desabilita a cópia padrão para evitar falhas catastróficas de memória
    Lista(const Lista&) = delete;
    Lista& operator=(const Lista&) = delete;
};

/**
 * @brief Imprime na tela todos os elementos da lista no formato L:[tamanho]{e1, e2, ...}.
 * @param lista Ponteiro constante para o descritor da lista a ser exibida.
 */
template <typename T>
void mostraL(const Lista<T> *lista)
{
    if (lista == nullptr) return;

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
 * @param lista Ponteiro para o descritor da lista que será destruída.
 */
template <typename T>
void destroiL(Lista<T> *lista)
{
    if (lista == nullptr) return;

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
 * @param lista Ponteiro constante para o descritor da lista.
 */
template <typename T>
bool vaziaL(const Lista<T> *lista)
{
    return lista == nullptr || lista->inicio == nullptr;
}

/**
 * @brief Retorna de forma segura a quantidade atual de elementos na lista.
 * @param lista Ponteiro constante para o descritor da lista.
 */
template <typename T>
int tamanhoL(const Lista<T> *lista)
{
    return (lista != nullptr) ? lista->tamanho : 0;
}

/**
 * @brief Insere um novo elemento no início da lista.
 */
template <typename T>
bool insereInicioL(Lista<T> *lista, T valor)
{
    if (lista == nullptr) return false;

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
 */
template <typename T>
bool insereFimL(Lista<T> *lista, T valor)
{
    if (lista == nullptr) return false;

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
 */
template <typename T>
bool removeL(Lista<T> *lista, T valor)
{
    if (lista == nullptr || lista->inicio == nullptr) return false;

    No<T> *anterior = nullptr;
    No<T> *atual = lista->inicio;
    
    while(atual && !(atual->dado == valor))
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
            lista->fim = nullptr;
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
 */
template <typename T>
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
 * @brief Executa uma função/ação personalizada para cada elemento da lista.
 * @details Otimizado para passar o dado por referência constante, evitando cópias.
 */
template <typename T, typename Func>
void paraCadaElemento(const Lista<T>* lista, Func acao) {
    if (lista == nullptr) return;
    No<T>* atual = lista->inicio;
    while (atual != nullptr) {
        acao(atual->dado); 
        atual = atual->prox;
    }
}

/**
 * @brief Exibe os elementos que estão presentes em ambas as listas, sem repetições.
 */
template <typename T>
void MostrarInterseccao(const Lista<T> *lista1, const Lista<T> *lista2) {
    if (lista1 == nullptr || lista2 == nullptr || lista1->inicio == nullptr || lista2->inicio == nullptr) {
        std::cout << "Nenhuma pessoa foi encontrada em comum entre as listas.\n";
        return;
    }

    bool encontrou_algum = false;
    No<T>* atual1 = lista1->inicio;

    std::cout << "\n--- Intersecção (Sem Repetições) ---\n";

    while (atual1 != nullptr) {
        const T& dado_atual = atual1->dado;
        bool ja_processado = false;

        No<T>* verificador = lista1->inicio;
        while (verificador != atual1) {
            if (verificador->dado == dado_atual) {
                ja_processado = true;
                break; 
            }
            verificador = verificador->prox;
        }

        if (!ja_processado) {
            No<T>* atual2 = lista2->inicio;
            bool existe_na_l2 = false;

            while (atual2 != nullptr) {
                if (atual2->dado == dado_atual) {
                    existe_na_l2 = true;
                    break; 
                }
                atual2 = atual2->prox;
            }

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

/**
 * @brief Inverte a ordem dos elementos da lista diretamente na memória (In-place).
 * @details Altera os ponteiros estruturais sem alocar novos nós ou copiar dados,
 * mantendo a eficiência de tempo linear O(N) e memória constante O(1).
 * @param lista Ponteiro para o descritor da lista que será invertida.
 */
template <typename T>
void inverterL(Lista<T> *lista)
{
    if (lista == nullptr || lista->inicio == nullptr || lista->inicio == lista->fim) {
        return; 
    }

    No<T> *anterior = nullptr;
    No<T> *atual = lista->inicio;
    No<T> *proximo = nullptr;

    // O antigo início se tornará o novo fim da lista
    lista->fim = lista->inicio;

    while (atual != nullptr) {
        proximo = atual->prox; // Salva o próximo nó
        atual->prox = anterior; // Inverte o ponteiro do nó atual para olhar para trás
        anterior = atual;       // Avança o anterior
        atual = proximo;        // Avança o atual
    }

    // O último nó processado se torna o novo início da lista
    lista->inicio = anterior;
}

/**
 * @brief Remove múltiplos elementos da lista baseando-se em uma função de critério (Predicado).
 * @details Percorre a lista e deleta todo nó cuja avaliação do predicado retorne 'true'.
 * @tparam Predicando Tipo da função/lambda de avaliação (deve retornar bool e aceitar const T&).
 * @param lista Ponteiro para o descritor da lista.
 * @param criterio Função lambda ou ponteiro de função contendo a regra de remoção.
 * @return int Quantidade total de elementos que foram removidos.
 */
template <typename T, typename Predicado>
int removerSeL(Lista<T> *lista, Predicado criterio)
{
    if (lista == nullptr || lista->inicio == nullptr) return 0;

    No<T> *anterior = nullptr;
    No<T> *atual = lista->inicio;
    int removidos = 0;

    while (atual != nullptr) {
        if (criterio(atual->dado)) {
            No<T> *noParaDeletar = atual;

            if (anterior == nullptr) {
                lista->inicio = atual->prox;
                atual = lista->inicio;
                if (lista->inicio == nullptr) {
                    lista->fim = nullptr;
                }
            } else {
                anterior->prox = atual->prox;
                atual = atual->prox;
                if (anterior->prox == nullptr) {
                    lista->fim = anterior;
                }
            }

            delete noParaDeletar;
            lista->tamanho--;
            removidos++;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return removidos;
}

/**
 * @brief Cria uma nova lista contendo apenas os elementos que atendem a um critério específico.
 * @details Varre a lista original e insere cópias dos nós aprovados pelo predicado na lista de destino.
 * @param listaOrigem Ponteiro constante para a lista base de consulta.
 * @param listaDestino Ponteiro para a lista que receberá as cópias filtradas (deve estar limpa).
 * @param criterio Função de validação que retorna 'true' para os elementos desejados.
 */
template <typename T, typename Predicado>
void filtrarL(const Lista<T> *listaOrigem, Lista<T> *listaDestino, Predicado criterio)
{
    if (listaOrigem == nullptr || listaDestino == nullptr || listaOrigem->inicio == nullptr) return;

    No<T> *atual = listaOrigem->inicio;
    while (atual != nullptr) {
        if (criterio(atual->dado)) {
            insereFimL(listaDestino, atual->dado);
        }
        atual = atual->prox;
    }
}

#endif // _HPP_LISTA_DESCRITOR