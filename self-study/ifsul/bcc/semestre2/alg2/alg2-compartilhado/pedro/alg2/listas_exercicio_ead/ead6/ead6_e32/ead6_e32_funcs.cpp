
#include "ead6_e32.hpp"

using namespace std;

bool validar_chave(int chave){
   if (chave < 1 || chave > 15){
    cout << "Chave inválida. Informe nova chave.\n";
    return false;
   }
   else return true;
}

int criptografar(int chave, char texto[101]){

    
    cout << "Texto Original: " << texto << endl;
    
        for (int i = 0; i < strlen(texto); i++)
    {
                if (isspace(texto[i])) {
                    continue;
                }

                if(!isalpha(texto[i])){
            cout << "Texto contém valores que não são letras. Processo interrompido.";
            return 1;
        }
    
        char caractere_maiusculo = toupper(texto[i]); 
                
        int posicao_base_zero = caractere_maiusculo - 'A';

        int nova_posicao = (posicao_base_zero + chave) % 26;

        texto[i] = (char)(nova_posicao + 'A');
    }
    
    cout << "Texto Criptografado: " << texto << endl;
    return 0;
}

int descriptografar(int chave, char texto[101]) {

    cout << "Texto Original: " << texto << endl;

    for (int i = 0; i < strlen(texto); i++) 
    {
        if (isspace(texto[i])) {
            continue;
        }

            if(!isalpha(texto[i])){
            cout << "Texto contém valores que não são letras. Processo interrompido.";
            return 1;
        }
        
        char caractere_maiusculo = toupper(texto[i]); 
        
        int posicao_base_zero = caractere_maiusculo - 'A';

        int nova_posicao = (posicao_base_zero - chave + 26) % 26;

        texto[i] = (char)(nova_posicao + 'A');
    }
    
        cout << "Texto Normal: " << texto << endl;
    return 0; }


    char solicitar_continuacao() {
    char reiniciar;
    
    // O loop garante que a entrada seja 'S' ou 'N'
    do
    {
        cout << "\n\nContinuar ou encerrar o programa? (S/N)\n\n";
        // Usa cin para ler um único caractere
        cin >> reiniciar; 
        
        // toupper(x) transforma o caractere para maiúsculo [3]
        reiniciar = toupper(reiniciar); 
    } while (reiniciar != 'S' && reiniciar != 'N');
    
    // Retorna o caractere validado para que o chamador decida o fluxo
    return reiniciar; 
}