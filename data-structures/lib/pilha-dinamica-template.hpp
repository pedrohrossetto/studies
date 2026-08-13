#ifndef _HPP_PILHA_DINAMICA_TEMPLATE
#define _HPP_PILHA_DINAMICA_TEMPLATE

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha
#include <iostream>
#include <string>
template<typename T>
struct NoPilha
{
    T dado; //informao do no
    NoPilha *prox; //pr�ximo elemento
};

template<typename T>
struct Pilha
{
    NoPilha<T> *topo;

    Pilha(){ //Construtor. Inicializa��o da pilha
        topo = nullptr;
    }
};

template<typename T>
bool vaziaP(Pilha<T> *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
template<typename T>
bool empilhaP(Pilha<T> *p, T dado)
{
    NoPilha<T> *novo =  new NoPilha<T>(); //cria um novo n�
    if (novo == NULL) /// sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado; //armazena a informa��o no n�
    novo->prox = p->topo; //o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o n� criado.
    return true;
}

//pop
template<typename T>
T desempilhaP(Pilha<T> *p)
{
    T dado;

    // se n�o estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no n� do topo
        NoPilha<T> *apagar = p->topo; //guarda o n� do topo em uma vari�vel auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o pr�ximo elemento;

        delete apagar;  /// libera a mem�ria
    }

    return dado;
}

//peek
template<typename T>
T espiaP(Pilha<T>* p)
{
    T dado;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}


template<typename T>
// Adicionado std:: antes de string
void mostraP(Pilha<T> *p, std::string tipo="") 
{
    // Adicionado std:: antes de endl em todos os lugares
    std::cout << "PILHA: " << tipo << std::endl;

    if(vaziaP(p) == false)
    {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << std::setfill(' ') << std::setw(13) << "No" << " | ";
        std::cout << std::setfill(' ') << std::setw(13) << "Prox" << " | ";
        std::cout << std::setfill(' ') << std::setw(10) << "Dado" << " |" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        NoPilha<T> *no = p->topo;
        while (no != NULL)
        {
            std::cout << std::setfill(' ') << std::setw(13) << no << " | ";
            std::cout << std::setfill(' ') << std::setw(13) << no->prox << " | ";
            std::cout << std::setfill(' ') << std::setw(10) << no->dado << " |" << std::endl;

            no = no->prox;
        }
        std::cout << "--------------------------------------------" << std::endl;
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor n�o existe na pilha
template<typename T>
bool buscaP(Pilha<T> *p, T dado)
{

    NoPilha<T> *no = p->topo;
    while (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;

}

template<typename T>
void destroiP(Pilha<T> *p)
{
    T dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}


template<typename T>
// Adicionado std:: antes de string
void percorreP(Pilha<T> *p) 
{
    if(vaziaP(p) == false)
    {
        NoPilha<T> *no = p->topo;
        while (no != NULL)
        {            
            std::cout << no->dado << " | " << no << " | " << no->prox << std::endl;
            no = no->prox;
        }
    }
}

// ==========================================
// NOVAS FUNÇÕES ADICIONADAS
// ==========================================

// 1. Percorrer pilha inversamente
// Utiliza recursão para ir até o final da pilha e imprimir na volta
template<typename T>
void percorreInversoAuxP(NoPilha<T> *no)
{
    if (no == nullptr) return;
    percorreInversoAuxP(no->prox);
    std::cout << no->dado << " | " << no << " | " << no->prox << std::endl;
}

template<typename T>
void percorrePilhaInversamenteP(Pilha<T> *p)
{
    if(vaziaP(p) == false) {
        percorreInversoAuxP(p->topo);
    }
}

// 2. Ordena pilha crescente
// Utiliza uma pilha auxiliar para organizar os valores do menor (topo) para o maior (base)
template<typename T>
void ordenaPilhaCrescenteP(Pilha<T> *p)
{
    Pilha<T> aux; // Pilha auxiliar
    
    while (!vaziaP(p)) {
        T temp = desempilhaP(p);
        
        while (!vaziaP(&aux) && espiaP(&aux) < temp) {
            empilhaP(p, desempilhaP(&aux));
        }
        empilhaP(&aux, temp);
    }
    
    // Devolve para a pilha original
    while (!vaziaP(&aux)) {
        empilhaP(p, desempilhaP(&aux));
    }
}

// 3. Separa pilha
// Distribui os elementos de uma pilha origem alternadamente em duas outras pilhas
template<typename T>
void separaPilhaP(Pilha<T> *origem, Pilha<T> *p1, Pilha<T> *p2)
{
    bool turno = true;
    while(!vaziaP(origem)) {
        if(turno) {
            empilhaP(p1, desempilhaP(origem));
        } else {
            empilhaP(p2, desempilhaP(origem));
        }
        turno = !turno;
    }
}

// 4. Combina pilha
// Pega os elementos de p1 e p2 e os intercala na pilha destino
template<typename T>
void combinaPilhaP(Pilha<T> *destino, Pilha<T> *p1, Pilha<T> *p2)
{
    while(!vaziaP(p1) || !vaziaP(p2)) {
        if(!vaziaP(p1)) empilhaP(destino, desempilhaP(p1));
        if(!vaziaP(p2)) empilhaP(destino, desempilhaP(p2));
    }
}

// 5. Fura pilha (Insere na base)
// Insere um elemento no fundo da pilha, ignorando a regra de entrada no topo
template<typename T>
void furaPilhaP(Pilha<T> *p, T dado)
{
    Pilha<T> aux;
    // Esvazia tudo para a auxiliar
    while(!vaziaP(p)) empilhaP(&aux, desempilhaP(p));
    
    // Fura a pilha inserindo na base
    empilhaP(p, dado);
    
    // Volta os dados originais por cima
    while(!vaziaP(&aux)) empilhaP(p, desempilhaP(&aux));
}

// 6. Pilha prioritária
// Insere o elemento na posição correta considerando que a pilha já está ordenada (menor no topo)
template<typename T>
void inserePrioridadeP(Pilha<T> *p, T dado)
{
    Pilha<T> aux;
    while(!vaziaP(p) && espiaP(p) < dado) {
        empilhaP(&aux, desempilhaP(p));
    }
    empilhaP(p, dado);
    while(!vaziaP(&aux)) {
        empilhaP(p, desempilhaP(&aux));
    }
}

// 7. Média de pilha
// Percorre a pilha sem alterar sua estrutura para calcular a média (exige tipo numérico)
template<typename T>
double mediaPilhaP(Pilha<T> *p)
{
    if(vaziaP(p)) return 0.0;
    
    double soma = 0;
    int contador = 0;
    NoPilha<T> *no = p->topo;
    
    while(no != NULL) {
        soma += no->dado;
        contador++;
        no = no->prox;
    }
    
    return soma / contador;
}

// 8. Inverte pilha
// Utiliza duas pilhas auxiliares para inverter completamente a ordem original
template<typename T>
void invertePilhaP(Pilha<T> *p)
{
    Pilha<T> aux1, aux2;
    
    while(!vaziaP(p)) empilhaP(&aux1, desempilhaP(p));
    while(!vaziaP(&aux1)) empilhaP(&aux2, desempilhaP(&aux1));
    while(!vaziaP(&aux2)) empilhaP(p, desempilhaP(&aux2));
}

// 9. Busca posição valor pilha
// Como buscaP já existe para bool, esta retorna a "profundidade" (0 = topo), ou -1 se não achar
template<typename T>
int buscaPosicaoPilhaP(Pilha<T> *p, T dado)
{
    int posicao = 0;
    NoPilha<T> *no = p->topo;
    
    while(no != NULL) {
        if(no->dado == dado) return posicao;
        posicao++;
        no = no->prox;
    }
    return -1;
}

// 10. Busca maior e menor valor
// Passa por referência as variáveis para armazenar o maior e menor encontrados
template<typename T>
void buscaMaiorMenorPilhaP(Pilha<T> *p, T &maior, T &menor)
{
    if(vaziaP(p)) return;
    
    NoPilha<T> *no = p->topo;
    maior = no->dado;
    menor = no->dado;
    no = no->prox;
    
    while(no != NULL) {
        if(no->dado > maior) maior = no->dado;
        if(no->dado < menor) menor = no->dado;
        no = no->prox;
    }
}

// 11. Verifica se uma pilha é igual outra
// Compara elemento a elemento e os tamanhos
template<typename T>
bool pilhasIguaisP(Pilha<T> *p1, Pilha<T> *p2)
{
    NoPilha<T> *no1 = p1->topo;
    NoPilha<T> *no2 = p2->topo;
    
    while(no1 != NULL && no2 != NULL) {
        if(no1->dado != no2->dado) return false;
        no1 = no1->prox;
        no2 = no2->prox;
    }
    
    // Se ambos chegaram no fim juntos, são iguais em tamanho e conteúdo
    if(no1 == NULL && no2 == NULL) return true;
    
    return false;
}

// 12. Concatena 2 pilhas
// Coloca todos os elementos da origem no topo do destino, mantendo a ordem da origem
template<typename T>
void concatenaPilhasP(Pilha<T> *destino, Pilha<T> *origem)
{
    Pilha<T> aux;
    while(!vaziaP(origem)) {
        empilhaP(&aux, desempilhaP(origem));
    }
    while(!vaziaP(&aux)) {
        empilhaP(destino, desempilhaP(&aux));
    }
}

// 13. Pilha balanceada (Algoritmo clássico)
// Verifica se uma string possui os parênteses, chaves e colchetes fechados corretamente.
// Obs: Esta não usa template<T>, pois é específica para análise de caracteres em uma std::string
bool verificaPilhaBalanceada(std::string expressao)
{
    Pilha<char> p; // Usa o struct Pilha para o tipo char
    
    for(size_t i = 0; i < expressao.length(); i++) {
        char c = expressao[i];
        
        if(c == '(' || c == '[' || c == '{') {
            empilhaP(&p, c);
        } 
        else if(c == ')' || c == ']' || c == '}') {
            if(vaziaP(&p)) return false;
            
            char topo = desempilhaP(&p);
            
            if((c == ')' && topo != '(') ||
               (c == ']' && topo != '[') ||
               (c == '}' && topo != '{')) {
                return false;
            }
        }
    }
    
    bool estaBalanceada = vaziaP(&p);
    destroiP(&p); // Garante a liberação de memória caso a expressão estivesse incompleta
    return estaBalanceada;
}




#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

// ==========================================
// FUNÇÕES ADAPTADAS DO MODELO ESTÁTICO
// ==========================================

/**
 * Busca por campo de uma Struct
 * T: O tipo da Struct (ex: Produto)
 * V: O tipo do campo dentro da struct (ex: int, string)
 */
template <typename T, typename V>
bool buscaCampoStructP(Pilha<T> *p, V T::*campo, V valorBusca) 
{
    NoPilha<T> *no = p->topo;
    while (no != NULL)
    {
        // no->dado.*campo acessa o valor do campo específico na struct
        if (no->dado.*campo == valorBusca)
        {
            return true; // Encontrou
        }
        no = no->prox;
    }
    return false; // Não encontrou
}

/**
 * Imprime a pilha utilizando uma função formatadora personalizada
 */
template <typename T>
void mostraFormatadoP(Pilha<T> *p, void (*Formatador_aux)(T))
{
    std::cout << "PILHA (Formatada): " << std::endl;
    
    if(!vaziaP(p))
    {
        std::cout << "------------" << std::endl;
        NoPilha<T> *no = p->topo;
        while (no != NULL)
        {
            Formatador_aux(no->dado); // Chama a lógica de impressão da struct
            
            if(no->prox != NULL) {
                std::cout  << std::endl << "------------" << std::endl;
            }
            no = no->prox;
        }
    }
    std::cout << std::endl << "} base" << std::endl;
}

/**
 * Lê caracteres do teclado e os insere na pilha, ignorando caracteres específicos.
 */
void ReceberInputP(Pilha<char> *p, std::string descartar = "")
{
    char aux;
    
    // std::cin.get(aux) captura cada caractere, incluindo espaços
    while (std::cin.get(aux) && aux != '\n')
    {
        // Verifica se o caractere atual NÃO está na lista de descartados
        if (descartar.find(aux) == std::string::npos)
        {
            empilhaP(p, aux); // Na pilha dinâmica não há teste de "cheiaP"
        }
    }
}

/**
 * Preenche a pilha de inteiros.
 * Adicionado o parâmetro 'qtd' pois a pilha dinâmica não tem limite fixo (tam).
 */
void preencheP(Pilha<int> *p, bool isAleatorio, int qtd)
{
    if (isAleatorio)
    {
        // Inicializa a semente apenas uma vez
        static bool semente_ok = false;
        if (!semente_ok) { srand(time(NULL)); semente_ok = true; }

        for (int i = 0; i < qtd; i++)
        {
            empilhaP(p, rand() % 100);
        }
        std::cout << "Pilha preenchida com " << qtd << " valores aleatorios." << std::endl;
    }
    else
    {
        int valor;
        for (int i = 0; i < qtd; i++)
        {
            std::cout << "Digite o valor [" << i + 1 << " de " << qtd << "]: ";
            if (std::cin >> valor)
            {
                empilhaP(p, valor);
            }
            else
            {
                std::cout << "Entrada invalida. Tente novamente." << std::endl;
                std::cin.clear();
                std::cin.ignore();
                i--; // Decrementa para refazer esta iteração
            }
        }
    }
}

/**
 * Recebe uma pilha e retorna uma NOVA pilha com os elementos copiados.
 * Restaura a pilha original ao final.
 */
template <typename T>
Pilha<T> copiaP(Pilha<T> *p)
{
    Pilha<T> pilhaInvertida, pilhaFinal;

    // 1. Esvazia a original para a auxiliar (fica invertida)
    while (!vaziaP(p))
    {
        T valor = desempilhaP(p);
        empilhaP(&pilhaInvertida, valor);
    }
    
    // 2. Transfere da auxiliar para a original (restaurando) e para a final
    while (!vaziaP(&pilhaInvertida))
    {
        T valor = desempilhaP(&pilhaInvertida);
        empilhaP(p, valor);
        empilhaP(&pilhaFinal, valor);
    }
    
    // Na dinâmica, a pilhaInvertida já fica vazia após os desempilhamentos,
    // mas a chamada a destroiP() é uma boa prática garantida.
    destroiP(&pilhaInvertida); 
    
    return pilhaFinal;
}

/**
 * Calcula menor, maior e média de uma vez usando ponteiros
 */
void estatisticaP(Pilha<int> *p1, int *menor, int *maior, float *media)
{
    if (vaziaP(p1)) return;

    int soma_total = 0, counter = 0;
    NoPilha<int> *no = p1->topo;
    
    // Inicializa com o primeiro valor
    *menor = no->dado;
    *maior = no->dado;

    while (no != NULL)
    {
        if(no->dado < *menor) *menor = no->dado;
        if(no->dado > *maior) *maior = no->dado;
        
        soma_total += no->dado;
        counter++;
        no = no->prox;
    }

    *media = (float)soma_total / (float)counter;
}

/**
 * Retorna diretamente o MAIOR valor
 */
template <typename T>
T maiorP(Pilha<T> *p1)
{
    if (vaziaP(p1)) return T{}; // Retorna valor padrão se vazia

    T maior = p1->topo->dado;
    NoPilha<T> *no = p1->topo->prox;

    while (no != NULL)
    {
        if (no->dado > maior) maior = no->dado;
        no = no->prox;
    }
    return maior;
}

/**
 * Retorna diretamente o MENOR valor
 */
template <typename T>
T menorP(Pilha<T> *p1)
{
    if (vaziaP(p1)) return T{}; // Retorna valor padrão se vazia

    T menor = p1->topo->dado;
    NoPilha<T> *no = p1->topo->prox;

    while (no != NULL)
    {
        if (no->dado < menor) menor = no->dado;
        no = no->prox;
    }
    return menor;
}

#endif // _HPP_PILHA_DINAMICA





