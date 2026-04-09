#ifndef _HPP_PILHA
#define _HPP_PILHA

#include <iostream>
#include <string>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

template <typename T>
struct Pilha
{
    int tam;
    int base;
    int topo;
    T *dados; // Vetor genérico que será alocado

    Pilha() 
    {
        tam = 0;
        base = -1;
        topo = -1;
        dados = nullptr;
    }
};

/// Inicialização dos dados da pilha com template
template <typename T>
void inicializaP(Pilha<T> *p, int tam)
{
    p->base = -1;
    p->topo = -1;
    p->tam  = tam;
    p->dados = new T[tam]; // Aloca memória para o tipo T
}

template <typename T>
bool verificaInicializacaoP(Pilha<T> *p)
{
    return (p->dados != nullptr);
}

template <typename T>
void destroiP(Pilha<T> *p)
{
    p->base = -1;
    p->topo = -1;
    p->tam = 0;

    if(p->dados != nullptr)
    {
        delete[] (p->dados);
        p->dados = nullptr;
    }
}

template <typename T>
bool cheiaP(Pilha<T> *p)
{
    return (p->topo == p->tam - 1);
}

template <typename T>
bool vaziaP(Pilha<T> *p)
{
    return (p->topo == p->base);
}

/// Push genérico
template <typename T>
bool empilhaP(Pilha<T> *p, T valor)
{
    if (verificaInicializacaoP(p) == false || cheiaP(p) == true)
        return false;
    
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

/// Pop genérico
template <typename T>
T desempilhaP(Pilha<T> *p)
{
    T valor = T();
    if (vaziaP(p) == false)
    {
        valor = p->dados[p->topo];
        p->topo--;
    }

    return valor;
}

/// Peek genérico
template <typename T>
T espiaP(Pilha<T> *p)
{
    T valor = T();
    if (vaziaP(p) == false)
    {
        valor = p->dados[p->topo];
    }

    return valor;
}

template <typename T>
void mostraP(Pilha<T> *p)
{
    std::cout << "PILHA: " << std::endl;
    std::cout << "TAM: " << p->tam << std::endl;
    std::cout << "TOPO: " << p->topo << std::endl;
    if(vaziaP(p) == false)
    {
        std::cout << "------------" << std::endl;
        for(int i = p->topo; i > p->base; i--){
            std::cout << i << "| " << p->dados[i]  << std::endl;
            std::cout << "------------" << std::endl;
        }
    }
}

template <typename T>
bool buscaP(Pilha<T> *p, T valor)
{
   for(int i = p->topo ; i > p->base; i--)
   {
       if (valor == p->dados[i])
          return true;
   }
   return false;
}

/**
 * T: O tipo da Struct (ex: Produto)
 * V: O tipo do campo dentro da struct (ex: int, string)
 * p: Ponteiro para a pilha
 * campo: O endereço do membro da struct (ex: &Produto::id)
 * valorBusca: O valor que você está procurando
 */
template <typename T, typename V>
bool buscaP(Pilha<T> *p, V T::*campo, V valorBusca) 
{
    // Percorre a pilha do topo para a base
    for(int i = p->topo; i > p->base; i--)
    {
        // p->dados[i].*campo acessa o valor do campo específico naquela instância da struct
        if (p->dados[i].*campo == valorBusca)
        {
            return true; // Encontrou
        }
    }
    return false; // Não encontrou
}

/**
 * T: O tipo da Struct
 * p: Ponteiro para a pilha
 * imprimirElemento: Uma função que recebe a struct T e imprime seus campos
 */
template <typename T>
void mostraP(Pilha<T> *p, void (*Formatador_aux)(T))
{
    std::cout << "PILHA: " << std::endl;
    std::cout << "TAM: " << p->tam << std::endl;
    std::cout << "TOPO: " << p->topo << std::endl;
    
    if(!vaziaP(p))
    {
        std::cout << "------------" << std::endl;
        for(int i = p->topo; i > p->base; i--)
        {
            Formatador_aux(p->dados[i]); // Chama a lógica de impressão da struct
            // Adiciona nova linha e separador se não for o último elemento (a base)
            if(i > p->base + 1) {
            std::cout  << std::endl << "------------" << std::endl;
            }
        }
    }
    
    std::cout << std::endl << "} base" << std::endl;
}


/**
 * Recebe uma pilha e retorna uma NOVA pilha com os elementos invertidos.
 * A pilha original 'p' será esvaziada durante o processo.
 */
template <typename T>
Pilha<T> inverteP(Pilha<T> *p)
{
    // 1. Criar e inicializar a nova pilha com o mesmo tamanho da original
    Pilha<T> pilhaInvertida;
    inicializaP(&pilhaInvertida, p->tam);

    // 2. Enquanto a original não estiver vazia, transfere os dados
    while (!vaziaP(p))
    {
        T valor = desempilhaP(p);
        empilhaP(&pilhaInvertida, valor);
    }

    // 3. Retorna a estrutura da nova pilha
    return pilhaInvertida;
}

/**
 * Inverte a ordem dos elementos dentro da própria pilha (In-place).
 * Não consome memória extra para uma nova pilha.
 */
template <typename T>
void inverteP_inplace(Pilha<T> *p)
{
    if (vaziaP(p) || p->topo == 0) return; // Nada para inverter

    int i = 0;              // Início (base)
    int j = p->topo;        // Fim (topo)

    while (i < j)
    {
        // Lógica de Swap (Troca)
        T temp = p->dados[i];
        p->dados[i] = p->dados[j];
        p->dados[j] = temp;

        i++; // Sobe a base
        j--; // Desce o topo
    }
}

/**
 * Lê caracteres do teclado e os insere na pilha, ignorando caracteres específicos.
 * p: Ponteiro para a pilha de chars.
 * descartar: String contendo todos os caracteres que NÃO devem entrar na pilha.
 */
void ReceberInputP(Pilha<char> *p, std::string descartar = "")
{
    char aux;
    
    // std::cin.get(aux) captura cada caractere, incluindo espaços
    while (std::cin.get(aux) && aux != '\n')
    {
        // Verifica se o caractere atual NÃO está na lista de descartados
        // std::string::npos significa que o caractere não foi encontrado
        if (descartar.find(aux) == std::string::npos)
        {
            if (!cheiaP(p))
            {
                empilhaP(p, aux);
            }
            else
            {
                std::cout << "\n[Aviso: Limite da pilha atingido]" << std::endl;
                break;
            }
        }
    }
}


// Função para comparar se duas pilhas são idênticas
template <typename T>
bool comparaP(Pilha<T> *p1, Pilha<T> *p2) {
    // Se os tamanhos ocupados (topos) forem diferentes, não são iguais
    if (p1->topo != p2->topo) return false;

    // Compara elemento por elemento
    for (int i = 0; i <= p1->topo; i++) {
        if (p1->dados[i] != p2->dados[i]) {
            return false; // Encontrou diferença, interrompe
        }
    }
    return true; // Se percorreu tudo, são iguais
}





/**
 * Preenche a pilha de inteiros.
 * p: Ponteiro para a pilha.
 * isAleatorio: Se true, gera números (0-99). Se false, solicita input do usuário.
 */
void preencheP(Pilha<int> *p, bool isAleatorio)
{
    if (isAleatorio)
    {
        // Inicializa a semente apenas uma vez
        static bool semente_ok = false;
        if (!semente_ok) { srand(time(NULL)); semente_ok = true; }

        while (!cheiaP(p))
        {
            empilhaP(p, rand() % 100);
        }
        std::cout << "Pilha preenchida com valores aleatorios." << std::endl;
    }
    else
    {
        int valor;
        while (!cheiaP(p))
        {
            std::cout << "Digite o valor para a posicao [" << p->topo + 1 << "]: ";
            if (std::cin >> valor)
            {
                empilhaP(p, valor);
            }
            else
            {
                // Trata erro de input (ex: digitar letra em vez de número)
                std::cout << "Entrada invalida. Tente novamente." << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
}
/**
 * Recebe uma pilha e retorna uma NOVA pilha com os elementos copiados
 * A pilha original 'p' será esvaziada durante o processo.
 */
template <typename T>
Pilha<T> copiaP(Pilha<T> *p)
{
    // 1. Criar e inicializar a nova pilha com o mesmo tamanho da original
    Pilha<T> pilhaInvertida,pilhaFinal;
    inicializaP(&pilhaInvertida, p->tam);
    inicializaP(&pilhaFinal, p->tam);


    // 2. Enquanto a original não estiver vazia, transfere os dados
    while (!vaziaP(p))
    {
        T valor = desempilhaP(p);
        empilhaP(&pilhaInvertida, valor);
    }
    while (!vaziaP(&pilhaInvertida))
    {
        T valor = desempilhaP(&pilhaInvertida);
        empilhaP(p,valor);
        empilhaP(&pilhaFinal,valor);
    }
    
    destroiP(&pilhaInvertida);
    // 3. Retorna a estrutura da nova pilha
    return pilhaFinal;
}

template <typename T>
Pilha<T> intercalaP(Pilha<T> *p1, Pilha <T> *p2){

    // 1. Criar e inicializar a nova pilha com o mesmo tamanho da original
    Pilha<T> PilhaAux;
    T valor;
    int tamanhoNecessario = p1->tam + p2->tam;
    inicializaP(&PilhaAux, tamanhoNecessario);

    // std::cout << tamanhoNecessario;
    

    // 2. Enquanto a original não estiver vazia, transfere os dados
    while (!vaziaP(p1) || !vaziaP(p2)  )
    {   
        if (!vaziaP(p1))
        {
            valor = desempilhaP(p1);
            empilhaP(&PilhaAux, valor);
        }
        if ((!vaziaP(p2)))
        {
            valor = desempilhaP(p2);
            empilhaP(&PilhaAux, valor);
        }
         
        
    }
    // 3. Retorna a estrutura da nova pilha
    Pilha pilhaNova = inverteP(&PilhaAux);
    destroiP(&PilhaAux);
    return pilhaNova;


}
#endif