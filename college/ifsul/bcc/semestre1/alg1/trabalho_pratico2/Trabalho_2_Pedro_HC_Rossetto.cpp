// Autor: Pedro H.C Rossetto
// Data: 29/03/2025
// Descrição: Código para simular controle bancário
// Trabalho prático 2, exercicio unico

#include <iostream>
#include <iomanip>
using namespace std;

int const TAMANHO_VETOR = 10;


bool unique_em_lista(int valor, int contas[]) {
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (contas[i] == valor) {
            cout << "Conta já foi cadastrada na posição " << i;
            return false;
        }
    }
    return true;
}



int cadastrar_contas(int contas[],int saldos[]){
    int conta, i;
        for (i = 0; i < TAMANHO_VETOR; i++){
    cout << "\nInforme número de conta para posição " << i << ": ";
    cin >> conta;
    if (unique_em_lista(conta, contas) == true){
        contas[i] = conta;
        saldos[i] = 0;
        }
        else{
            i--;
        }
    }
    return 0;
}


void consultar_ativos(int contas[],int saldos[]){
    int i;
    float saldos_soma = 0;
    cout << "Conta\t\tSaldo\n";
    for (i = 0 ;i < TAMANHO_VETOR; i++){
        cout << contas[i] << "\t\t" << saldos[i] << "\n";
        saldos_soma += saldos[i];

    }
    cout << "Total: --------------" << "\n" << "\t\t" << saldos_soma << endl;
    return;
}


void print_menu(){
    cout << "\n----------- MENU -----------\n";
    cout << "0. Inicializar Contas\n";
    cout << "1. Efetuar depósito\n";
    cout << "2. Efetuar saque\n";
    cout << "3. Consultar o ativo bancário\n";
    cout << "4. Finalizar o programa\n";
    cout << "Escolha Opção: ";
    return;
}



int encontrar_conta(int conta, int contas[]) {
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (contas[i] == conta) {
            // [DEBUG] cout << "Conta " << conta << " encontrada na posição " << i << "\n";
            return i; // index se encontrado
        }
    }
    cout << "\nConta não encontrada\n";
    return -1; // -1 se não encontrado
}

int efetuar_deposito(int contas[], int saldos[]){
    int conta, response;
    float valor_deposito;
    do {
    cout << "Informe o número da conta: ";
    cin >> conta;
    response = encontrar_conta(conta, contas);} 
    while (response == -1);
    do {cout << "\nInforme valor para depósito: ";
    cin >> valor_deposito;
    } while (valor_deposito < 0);
    saldos[response] += valor_deposito;
    cout << "\nDepósito efetuado\n";
    return 0;
}

int efetuar_saque(int contas[], int saldos[]){
    int conta, response;
    float valor_saque;
    do {
        cout << "Informe o número da conta: ";
        cin >> conta;
        response = encontrar_conta(conta, contas);} 
        while (response == -1);
    do {
        cout << "\nSaldo da conta: R$" << saldos[response] << "\n"; // Não foi requisitado, mas quis incluir
        cout << "\nInforme valor para Saque: ";
        cin >> valor_saque;} 
        while (valor_saque < 0);
    if (saldos[response] -= valor_saque <= 0)
        {
        saldos[response] -= valor_saque;
        cout << "\nSaque efetuado\n";}
    else 
        {cout << "\nSaldo Insuficiente para Saque\n";}
    return 0;
}



int main(){
    setlocale(LC_ALL,"PORTUGUESE");
    cout << fixed << setprecision(2);
    int contas[TAMANHO_VETOR];
    int saldos[TAMANHO_VETOR];
    bool contas_inicializadas = false;
    int opcao;
    do {
        print_menu();
        cin >> opcao;
        switch (opcao) {
            case 0:
                cadastrar_contas(contas, saldos);
                contas_inicializadas = true;
                break;
            case 1:
                if (!contas_inicializadas) {
                    cout << "\nOpção Inválida, é necessário selecionar anteriormente a opção 0\n";
                } else {
                    efetuar_deposito(contas, saldos);
                }
                break;
            case 2:
                if (!contas_inicializadas) {
                    cout << "\nOpção Inválida, é necessário selecionar anteriormente a opção 0\n";
                } else {
                    efetuar_saque(contas, saldos);
                }
                break;
            case 3:
                if (!contas_inicializadas) {
                    cout << "\nOpção Inválida, é necessário selecionar anteriormente a opção 0\n";
                } else {
                    consultar_ativos(contas, saldos);
                }
                break;
            case 4:
                cout << "Programa finalizado.\n";
                break;
            default:
                cout << "Opção inválida\n";
        }
    } while (opcao != 4);
}

