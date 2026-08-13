/*
    Autor: Pedro H.C Rossetto
    Data: 30/09/2025
    Descrição: Crie um programa que implemente uma criptografia de deslocamento de caractere ASCII
    Trabalho prático 6, Exercício 32, Algoritimos 2
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <cmath>
#include "ead6_e32.hpp"


using namespace std; 



int main(){
    int chave, opcao;
    char texto[99];
    do // validar chave
    {
        cout << "Informe chave da criptografia (deslocamento da letra): \n";
        cin >> chave;
    } while (!validar_chave(chave));

    do { // menu de escolha switch
        system("cls");
        cout << "1 - Criptografar (recebe um texto normal e apresenta o texto criptografado)\n";
        cout << "2 - Descriptografar (recebe um texto criptografado e apresenta o texto normal)\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
    switch (opcao) {
        case 1:{
            cout << "Digite texto (100) que deseja criptografar: ";
            cin.ignore();
            cin.getline(texto, sizeof(texto));
            criptografar(chave, texto);
            char escolha_usuario = solicitar_continuacao();
            if (escolha_usuario == 'N')
            {
                system("cls"); 
                cout << "Encerrando o programa." << endl;
                return 0; 
            }
            break;
        }
        case 2:{
            cout << "Digite texto (100) que deseja descriptografar: ";
            cin.ignore(); 
            cin.getline(texto, sizeof(texto));
            descriptografar(chave, texto);
            char escolha_usuario = solicitar_continuacao(); 
            if (escolha_usuario == 'N')
            {
                system("cls"); 
                cout << "Encerrando o programa." << endl;
                return 0; 
            }
            break;
        }
        case 0:
            system("cls");
            cout << "Encerrando o programa." << endl;
            break;
    
        default:
            system("cls");  
            cout << "Opcao invalida!" << endl;
            break;

        };

    if (opcao != 0) {
        cout << "\nPressione Enter para continuar...";
        cin.ignore();
        cin.get();
        }
    
    } while (opcao != 0);
    return 0;
}