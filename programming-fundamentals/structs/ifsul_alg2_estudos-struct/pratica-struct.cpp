#include <iostream>

using namespace std;

struct User_struct
{
    //private: // nao obrigatorio, structs são publico por padrão

    // DECLARAÇÃO DE VARIAVEIS
    string first_name, last_name;
    string status;
    int idade;

    // DECLARAÇÃO DE FUNÇÕES
    string get_status(){
        return status;
    }
};

int main()
{
    User_struct usuario;
    usuario.first_name = "Pedro";
    usuario.last_name = "Carteli";
    usuario.status = "Ativo";

    cout << "First Name: " << usuario.first_name<< endl; // utilizando variaveis de structs
    cout << "Status do Usuario: " << usuario.get_status() << endl; // utilizando funções

    return 0;
}