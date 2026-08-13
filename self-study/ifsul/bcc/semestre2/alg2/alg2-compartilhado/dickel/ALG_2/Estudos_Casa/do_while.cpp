#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int magico, chute;

    magico = rand();

    do{
        cout << "Faça seu chute: ";
        cin >> chute;

        if (chute == magico){
            cout << "Parabéns, você acertou!" << endl;
        } else {
            cout << "Errado, tente novamente!" << endl;
            if (chute < magico){
                cout << "O número mágico é maior que " << chute << endl;
            } else {
                cout << "O número mágico é menor que " << chute << endl;
            }
        }
    } while (chute != magico);
    return 0;    
}