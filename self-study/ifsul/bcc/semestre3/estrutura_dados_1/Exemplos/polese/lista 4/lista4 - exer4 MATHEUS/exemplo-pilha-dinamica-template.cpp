#include <iostream>
#include <string>

using namespace std;

#include "pilha-dinamica-template.hpp"

int main(void)
{
    // MUDANÇA 1: Pilha de char, não de string
    Pilha<char> p1; 
    setlocale(LC_ALL, "Portuguese");

    string texto;
    cout << "Digite uma frase: ";
    getline(cin, texto);

    for (int i = 0; i < texto.size(); i++) 
    {
        char atual = texto[i];

        // MUDANÇA 2: Agrupar as aberturas (limpeza de código)
        if (atual == '{' || atual == '(' || atual == '[') 
        {
            empilhaP(&p1, atual);
        }
        // MUDANÇA 3: Verificar se está vazia antes de desempilhar
        else if (atual == '}' || atual == ')' || atual == ']') 
        {
            if (vaziaP(&p1)) 
            {
                // Se tentou fechar algo que nem abriu, empilha um "lixo" 
                // só para a pilha não terminar vazia e invalidar
                empilhaP(&p1, 'X'); 
                break; 
            }
            
            // Opcional: Verificar se o que sai combina com o que entra
            // Ex: Se atual for ']' o topo tem que ser '['
            desempilhaP(&p1);
        }
    }

    if (vaziaP(&p1)) 
    {
        cout << "Pilha Balanceada" << endl;
    } 
    else 
    {
        cout << "Pilha Desbalanceada" << endl;
    }

    return 0;
}