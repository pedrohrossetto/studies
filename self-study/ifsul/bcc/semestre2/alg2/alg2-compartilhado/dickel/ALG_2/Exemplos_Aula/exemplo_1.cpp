// Para rodar o código utilizar .\Exemplos_Aula\exemplo_1.exe no terminal do VS Code
#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

main(){

    setlocale (LC_ALL, "portuguese");

    char nome[100];

    cout << "Informe o nome: ";
    cin >> nome;

    cout << "Nome Informado: " << nome << endl;
    // A função apresentará apenas o primeiro nome do usuário, ignorando mais elementos sequentes do primário digitado

    return 0;
}