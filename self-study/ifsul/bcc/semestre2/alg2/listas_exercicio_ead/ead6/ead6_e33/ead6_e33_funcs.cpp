
#include "ead6_e33.hpp"
#include <fstream>

using namespace std;


bool validar_base_cpf(char entrada_texto[]) {


    if (strlen(entrada_texto) != 10) {
        return false; 
    }


    for (int i = 0; i < 10; i++) {
        
        if (!isdigit(entrada_texto[i])) { 
            return false;
        }
    }

    return true;
}

bool reinicar() {
    char reiniciar;
    
        do
    {
        cout << "\n\nContinuar ou encerrar o programa? (S/N)\n\n";
                cin >> reiniciar; 
        
                reiniciar = toupper(reiniciar); 
    } while (reiniciar != 'S' && reiniciar != 'N');
    
        if (reiniciar == 'S')
    {
        return true; 
    }
    else return false;
}
    
void aguardar_entrada() {
        cout << "\nPressione Enter para continuar...";
    
            cin.ignore(); 
    cin.get();
}

void ler_cpf_do_arquivo(ifstream &arquivo, int cpf_digitos[]) {
    char buffer_digito[10]; 
    for (int i = 0; i < 9; i++) {
        arquivo >> buffer_digito; 
        if (arquivo.fail()) {
        break; 
    }
        cpf_digitos[i] = atoi(buffer_digito);
    }
}

int calcular_dv2(int digitos_cpf[]) {
        int fator = 11;
    int soma = 0;
    int resto;
    int dv2;

        for (int i = 0; i < 10; i++) {
                soma += digitos_cpf[i] * fator;
        fator--; 
    }
    
        resto = soma % 11; 
        if (resto < 2) {
        dv2 = 0;
    } else {
        dv2 = 11 - resto;     }

    return dv2; }

int calcular_dv1(int digitos_cpf[]) {
        int fator = 10;
    int soma = 0;
    int resto;
    int dv1;

                for (int i = 0; i < 9; i++) {
                soma += digitos_cpf[i] * fator; 
        fator--;     }

        resto = soma % 11; 
        if (resto < 2) {
        dv1 = 0;     } else {
        dv1 = 11 - resto;     }

    return dv1; }

int calcular_soma_recursiva(int digitos[], int indice, int fator) {

            if (fator == 1) {
        return 0;     }

            return (digitos[indice] * fator) + 
           calcular_soma_recursiva(digitos, indice + 1, fator - 1);
}

void calcular_cpf_completo(int cpf[]) { 
    
    int soma_dv1;
    int resto_dv1;
    int dv1;
    
                
        soma_dv1 = calcular_soma_recursiva(cpf, 0, 10);     
        resto_dv1 = soma_dv1 % 11;
    
    if (resto_dv1 < 2) {
        dv1 = 0;
    } else {
        dv1 = 11 - resto_dv1;     }
    
        cpf[8] = dv1;

            
    int soma_dv2;
    int resto_dv2;
    int dv2;
    
            
        soma_dv2 = calcular_soma_recursiva(cpf, 0, 11);     
        resto_dv2 = soma_dv2 % 11;

    if (resto_dv2 < 2) {
        dv2 = 0;
    } else {
        dv2 = 11 - resto_dv2;     }
    
        cpf[10] = dv2;

        }

void formatar_cpf_para_texto(const int cpf_inteiros[], char cpf_destino_texto[]) {
    
    int indice_texto = 0; // Índice para escrever na string de destino
    
    // Itera sobre os 11 dígitos
    for (int i = 0; i < 11; i++) {
        
        // Converte o dígito inteiro para seu caractere ASCII correspondente (ex: 5 -> '5')
        cpf_destino_texto[indice_texto++] = cpf_inteiros[i] + '0';

        // Regras de Formatação:
        // Ponto: após o 3º dígito (índice i=2) e após o 6º dígito (índice i=5)
        if (i == 2 || i == 5) {
            cpf_destino_texto[indice_texto++] = '.';
        }
        // Hífen: após o 9º dígito (índice i=8)
        else if (i == 8) {
            cpf_destino_texto[indice_texto++] = '-';
        }
    }
    
    // Finaliza a string com o terminador nulo ('\0')
    // Uma string é uma matriz tipo char que termina com '\0' [3].
    cpf_destino_texto[indice_texto] = '\0';
}

void ler_cpf_do_arquivo(ifstream &arquivo, int cpf_digitos[]) {
    
    // O buffer deve ser char para ler um dígito de cada vez do arquivo (que é texto)
    char buffer_digito[2]; 
    
    // O loop deve iterar 9 vezes para ler os 9 dígitos originais do CPF
    for (int i = 0; i < 9; i++) {
        
        // 1. Leitura do Arquivo: O operador '>>' lê uma palavra (o dígito),
        // ignorando espaços, tabulações ou quebras de linha [9].
        arquivo >> buffer_digito; 
        
        // 2. Verificação de Estado: Checa se a leitura falhou (incluindo EOF) [9, 10].
        if (arquivo.fail()) {
            // Se o arquivo terminou antes de ler 9 dígitos, interrompe a rotina.
            break; 
        }
        
        // 3. Conversão: Usa atoi para converter o dígito (que é texto) para inteiro [4, 6].
        // Esta é a forma de garantir que o cálculo do Módulo 11 seja feito com inteiros.
        cpf_digitos[i] = atoi(buffer_digito);
    }
}

void formatar_e_exibir(const int cpf_completo[], ofstream& arquivo_saida) {
    // Para a tela (cout)
    cout << setw(3) << setfill('0') << cpf_completo << cpf_completo[19] << cpf_completo[20] << "."; 
    cout << setw(3) << setfill('0') << cpf_completo[8] << cpf_completo[5] << cpf_completo[21] << ".";
    cout << setw(3) << setfill('0') << cpf_completo[22] << cpf_completo[23] << cpf_completo[24] << "-";
    cout << cpf_completo[6] << cpf_completo[17] << endl; // Exibe o formato 111.444.777-35 [3]

    // Para o arquivo de saída (ofstream)
    arquivo_saida << cpf_completo << cpf_completo[19] << cpf_completo[20] << "."; 
    arquivo_saida << cpf_completo[8] << cpf_completo[5] << cpf_completo[21] << ".";
    arquivo_saida << cpf_completo[22] << cpf_completo[23] << cpf_completo[24] << "-";
    arquivo_saida << cpf_completo[6] << cpf_completo[17] << "\n";
}

void escrever_cpf(const char cpf_formatado_texto[], ofstream &arquivo_saida) {

    // 1. Exibir o CPF Formatado na Tela (cout)
    // O comando cout pode ser utilizado para escrever strings [5].
    cout << "CPF Completo: " << cpf_formatado_texto << endl; 

    // 2. Escrever o CPF Formatado no Arquivo (ofstream)
    // Após associar o objeto ao arquivo, pode-se enviar dados através dele, como no comando cout [6].
    arquivo_saida << cpf_formatado_texto << endl; 
}