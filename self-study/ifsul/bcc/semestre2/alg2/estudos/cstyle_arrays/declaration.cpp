#include <iostream>
using namespace std;

struct Motor {
    int potencia;
};

struct Carro {
    Motor motor_fixo;    // Objeto normal
    Motor* motor_turbo;  // Ponteiro para Motor
};

int main() {
    // Preparando os dados
    Motor m1 = {100};
    Motor m2 = {200};
    
    Carro c;
    c.motor_fixo = m1;
    c.motor_turbo = &m2; // Aponta para m2
    
    // Criando um ponteiro para o carro
    Carro* ptrCarro = &c;

    // --- ACESSANDO ---

    // Caminho A: Ponteiro -> Objeto -> Campo
    // ptrCarro (Seta) motor_fixo (Ponto) potencia
    cout << "Normal: " << ptrCarro->motor_fixo.potencia << endl;

    // Caminho B: Ponteiro -> Ponteiro -> Campo
    // ptrCarro (Seta) motor_turbo (Seta) potencia
    cout << "Turbo:  " << ptrCarro->motor_turbo->potencia << endl;

    return 0;
}