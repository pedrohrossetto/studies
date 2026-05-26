#include <iostream>
#include <string>
using namespace std;

struct Reuniao
{
    string titulo;
    int duracao;
    Reuniao()
    {
        titulo = "";
        duracao = 0;
    }
    Reuniao(string s, int d)
    {
        titulo = s;
        duracao = d;
    }

};


#include "lista_descritor.hpp"

void dividirReunioesLongas(Lista *lista)
{
    No* n = lista->inicio;

    while(n!=NULL)
    {
        if(n->dado.duracao>240)
        {
            int resto = n->dado.duracao - 240;
            n->dado.duracao = 240;

            No *novo = new No();
            if (novo == nullptr)
                return;

            novo->dado = Reuniao(n->dado.titulo, resto);
            novo->prox = n->prox;
            n->prox = novo;

            if(novo->prox == NULL)
                lista->fim = novo;
            lista->tamanho++;
        }

        n = n->prox;
    }

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");




    Lista lista = Lista();//chama o cosntrutor para inicilizar a lista


    cout << "\n\n###TESTE 1 - inserindo inicio/fim\n";
    insereFimL(&lista, Reuniao("Planejamento", 180));
    insereFimL(&lista, Reuniao("Workshop", 300));
    insereFimL(&lista, Reuniao("Revisão", 90));
    mostraL(&lista);
    dividirReunioesLongas(&lista);
    mostraL(&lista);
    destroiL(&lista);


     cout << "\n\n###TESTE 2 - inserindo inicio/fim\n";
    insereFimL(&lista, Reuniao("Planejamento", 180));
    insereFimL(&lista, Reuniao("Workshop", 90));
    insereFimL(&lista, Reuniao("Revisão", 480));
    mostraL(&lista);
    dividirReunioesLongas(&lista);
    mostraL(&lista);
    destroiL(&lista);


     cout << "\n\n###TESTE 3 - inserindo inicio/fim\n";
    insereFimL(&lista, Reuniao("Planejamento", 352));
    insereFimL(&lista, Reuniao("Workshop", 180));
    insereFimL(&lista, Reuniao("Chefia", 240));
    insereFimL(&lista, Reuniao("Revisão", 90));
    mostraL(&lista);
    dividirReunioesLongas(&lista);
    mostraL(&lista);
    destroiL(&lista);


    destroiL(&lista);
    return EXIT_SUCCESS;
}
