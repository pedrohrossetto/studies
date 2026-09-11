#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct Pacote
{
    int codigo;
    float peso;
    Pacote()
    {
        codigo=0;
        peso=0.0f;
    }
    Pacote(int c, float p)
    {
        codigo=c;
        peso=p;
    }
};
#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"


bool ajustarMediaPeso(Fila *f, int cod1, int cod2)
{
    NoFila *no = f->inicio;
    while (no != NULL && no->prox != NULL)
    {
        if(no->dado.codigo == cod1 && no->prox->dado.codigo == cod2)
        {
            float novoPeso= (no->dado.peso +  no->prox->dado.peso) / 2.0f;
            no->dado.peso = novoPeso;
            no->prox->dado.peso = novoPeso;
            return true;
        }


        no = no->prox;
    }

    return false;
}

void fracionarPacotes(Pilha *p, float pesoMax)
{
    Pilha aux;

    while(!vaziaP(p))
    {
        Pacote pac = desempilhaP(p);
        float pesoRestante;
        do
        {
            pesoRestante = pac.peso - pesoMax;
            if(pesoRestante>0)
            {
                empilhaP(&aux, Pacote(pac.codigo, pesoMax));
                pac.peso = pesoRestante;
            }
            else
                empilhaP(&aux, pac);

        }while(pesoRestante>0);

    }

    while(!vaziaP(&aux))
        empilhaP(p, desempilhaP(&aux) );

    destroiP(&aux);
}

float espiaPesoF(Fila* f)
{
    float peso=0.0f;

    if (!vaziaF(f))
        peso = f->inicio->dado.peso;

    return peso;
}


int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    Fila f1, f2;
    Pilha p1;
    string op, linha;
    stringstream strBuffer;


    //comente as três linhas abaixo para exibir a saida no terminal
    //ofstream arqSaida("saidaEntrada2.txt");
    //streambuf *coutbuf = cout.rdbuf(); //salva o buffer de saida (cout)
    //cout.rdbuf(arqSaida.rdbuf());  //redireciona o cout para saidaCorrecao.txt !



    ifstream arq ("correcaoE3.txt");
    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }
    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE
        op = "";
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "ADICIONAR_FILA") //assumir códigos distintos
        {
            int idxFila;
            Pacote pac;
            strBuffer >> idxFila;
            strBuffer >> pac.codigo;
            strBuffer >> pac.peso;

            if(buscaF(&f1, pac.codigo) || buscaF(&f2, pac.codigo) )
                cout << "Erro: O pacote com o código " << pac.codigo << " já está enfileirado!\n";
            else if(idxFila == 1)
                enfileiraF(&f1, pac);
            else if(idxFila == 2)
                enfileiraF(&f2, pac);
            else
            {
                cout << "Erro: A fila " << idxFila << " não existe!\n";
            }

            if(idxFila>=1 && idxFila<=2)
                cout << "O pacote de código=" << pac.codigo << " foi enfileirado na Fila " << idxFila << endl;

        }
        else if(op == "MOSTRAR_FILAS")
        {
            mostraF(&f1, "F1");
            mostraF(&f2, "F2");
        }
        else if(op == "AJUSTAR_PESO_MEDIA_FILA")
        {
            //buscar a fila que contem, a partir de dois códigos, sendo que os pacotes devem ser adjacentes;
            //somar os pesos e dividir por dois e colocar os novos pesos nos pacotes.
            //mesma fila e serem adjancentes, sendo cótigo 2 na sequencia do codigo 1
            int cod1, cod2;
            strBuffer >> cod1;
            strBuffer >> cod2;
            bool resultado;


            resultado = ajustarMediaPeso(&f1, cod1, cod2);
            if(!resultado)
                resultado = ajustarMediaPeso(&f2, cod1, cod2);

            if(resultado)
               cout << "Os pesos dos pacotes de códigos " <<  cod1 << " e " << cod2 << " foram ajustados pela média.\n";
            else
                cout << "Os pesos dos pacotes de códigos " <<  cod1 << " e " << cod2 << " NÃO foram ajustados pela média.\n";
        }
        else if(op == "REMOVER_FILA")
        {

            //critério = mais pesado. Caso de empate, pega F1


            if(vaziaF(&f1)&& vaziaF(&f2))
            {
                cout << "Erro ao remover pacote da fila. Ambas as filas estão vazias!\n";
            }
            else
            {
                Pacote pac;
                if(!vaziaF(&f1) && espiaPesoF(&f1)>=espiaPesoF(&f2))
                    pac = desenfileiraF(&f1);
                else if(!vaziaF(&f2))
                    pac = desenfileiraF(&f2);
                empilhaP(&p1, pac);
                cout << "O pacote de código=" << pac.codigo << " foi retirado da fila e empilhado!\n";
            }

        }
        else if(op == "MOSTRAR_PILHA")
        {
            mostraP(&p1);
        }

        else if(op == "FRACIONAR_PACOTES_PILHA")
        {
            float pesoMax;
            strBuffer >> pesoMax;
            fracionarPacotes(&p1, pesoMax);
            cout << "Os pacotes da pilha foram fracionados respeitando o peso máximo de " <<pesoMax << "!\n";
        }

    } //fim while de leitura de arquivo




    //cout.rdbuf(coutbuf); //reseta o buffer de saida para o padrão novamente.
    arq.close();
    //arqSaida.close();


    //desalocar memória
    destroiF(&f1);
    destroiF(&f2);
    destroiP(&p1);


    return EXIT_SUCCESS;

}//final do main

