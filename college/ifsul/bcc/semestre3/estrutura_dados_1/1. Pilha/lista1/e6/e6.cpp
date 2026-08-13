#include <fstream>
#include <iostream>
#include "../../modules/vetor_dinamico.hpp"
#include "../../modules/text_files.hpp"
#include "../../modules/utils.hpp"


using namespace std;

struct Temperatura
{
    string dia;
    float temp_min;
    float temp_max;

    Temperatura(){
        dia = "";
        temp_min = 0.0;
        // // temp_max = 0.0;
    }

    Temperatura(string d, float t_min, float t_max){
    dia = d;
    temp_min = t_min;
    temp_max = t_max;
    }
};

void carregar_dados_temperatura(ifstream &arq, Temperatura* vet, int tam);
void exibir_valores(Temperatura* vet, int tam);

int main(){

    limpar_tela();
    // Abrir Arquivo
    ifstream leitura_temperaturas;
    string caminho = "C:\\Users\\pcarteli\\OneDrive - Alvarez and Marsal\\Repositories\\college_repo\\ifsul\\bcc\\semestre3\\estrutura_dados_1\\lista1\\e6\\temperatura.txt";
    if (!abrir_arquivo(leitura_temperaturas, caminho)) {
        // Encerra o programa se o arquivo for essencial
        return 1; 
    }

    // Reservar Espaço e preparar a classe
    int qtd_linhas = contar_linhas(leitura_temperaturas);
    Temperatura* lista_temperaturas = new Temperatura[qtd_linhas];
    
    // ler arquivo e Criar Objetos 
    carregar_dados_temperatura(leitura_temperaturas, lista_temperaturas, qtd_linhas);
   
    // Exibir resultados
    exibir_valores(lista_temperaturas, qtd_linhas);

    // Encerrar com Sucesso
    liberar_vetor_generico(lista_temperaturas);   
    leitura_temperaturas.close();
    return 0;
}


void carregar_dados_temperatura(ifstream &arq, Temperatura* vet, int tam) {

 for (int i = 0; i < tam; i++) {
        string d;
        float tmin, tmax;
        if (arq >> d >> tmin >> tmax) {
            vet[i] = Temperatura(d, tmin, tmax);
        }
    }

}

void exibir_valores(Temperatura* vet, int tam){
        // Exibir resultados
    for (int i = 0; i < tam; i++) {
        cout << "Dia: " << vet[i].dia << " (Temperatura Mininma: " << vet[i].temp_min << u8" Temperatura Maxima: "<< vet[i].temp_max <<")" << endl;
    }

}