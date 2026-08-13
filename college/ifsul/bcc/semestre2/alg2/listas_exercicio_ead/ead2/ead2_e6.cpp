#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int TAMANHO_MAXIMO = 500;

    char texto_original[TAMANHO_MAXIMO];
    char texto_maiusculo[TAMANHO_MAXIMO];
    char texto_minusculo[TAMANHO_MAXIMO];

    cout << "Digite um texto qualquer: ";
    cin.getline(texto_original, TAMANHO_MAXIMO);

    int total_caracteres = strlen(texto_original);
    int total_vogais = 0;
    int total_consoantes = 0;
    int total_numeros = 0;
    int total_espacos = 0;

    // Percorre o texto para análise e conversão.
    for (int i = 0; i < total_caracteres; i++) {
        char caractere_atual = texto_original[i];
        
        // Converte para maiúsculo e minúsculo
        if (caractere_atual >= 'a' && caractere_atual <= 'z') {
            texto_maiusculo[i] = caractere_atual - 32;
            texto_minusculo[i] = caractere_atual;
        } else if (caractere_atual >= 'A' && caractere_atual <= 'Z') {
            texto_maiusculo[i] = caractere_atual;
            texto_minusculo[i] = caractere_atual + 32;
        } else {
            texto_maiusculo[i] = caractere_atual;
            texto_minusculo[i] = caractere_atual;
        }

        // Realiza a contagem dos tipos de caracteres
        char caractere_para_analise = texto_minusculo[i];
        if (caractere_para_analise == 'a' || caractere_para_analise == 'e' || caractere_para_analise == 'i' || caractere_para_analise == 'o' || caractere_para_analise == 'u') {
            total_vogais++;
        } else if (caractere_para_analise >= 'a' && caractere_para_analise <= 'z') {
            total_consoantes++;
        } else if (caractere_para_analise >= '0' && caractere_para_analise <= '9') {
            total_numeros++;
        } else if (caractere_para_analise == ' ') {
            total_espacos++;
        }
    }

    // Adiciona o caractere nulo terminador ao final das novas strings.
    texto_maiusculo[total_caracteres] = '\0';
    texto_minusculo[total_caracteres] = '\0';

    // Apresenta os resultados.
    cout << "ANALISE DO TEXTO:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "- Texto em maiusculo: " << texto_maiusculo << endl;
    cout << "- Texto em minusculo: " << texto_minusculo << endl;
    cout << "- Total de caracteres: " << total_caracteres << endl;
    cout << "- Total de vogais: " << total_vogais << endl;
    cout << "- Total de consoantes: " << total_consoantes << endl;
    cout << "- Total de numeros: " << total_numeros << endl;
    cout << "- Total de espacos em branco: " << total_espacos << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}