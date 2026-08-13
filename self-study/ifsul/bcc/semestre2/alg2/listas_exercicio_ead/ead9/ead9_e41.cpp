/*
    Autor: Pedro H.C Rossetto
    Data: 13/10/2025
    Descrição: Utilize ponteiros para calcular o custo de combustível de uma viagem.
    Algoritimos 2, Trabalho prático 9, Exercício 2
*/

#include <iostream>
#include <iomanip> // Para std::fixed e std::setprecision

// Define um namespace para evitar conflitos e organizar o código
using namespace std;

// Estrutura para agrupar os resultados do cálculo
struct ResultadoViagem {
    float litros_necessarios;
    float custo_total;
};

// --- Protótipos das Funções ---
void lerDadosViagem(float* ptr_distancia, float* ptr_consumo, float* ptr_preco_combustivel);
ResultadoViagem calcularGastos(float distancia_km, float consumo_km_l, float preco_litro);
void exibirResultadoViagem(ResultadoViagem resultado);


// --- Função Principal ---
int main() {
    // Variáveis que irão armazenar os dados da viagem
    float distancia_total_km;
    float consumo_medio_kml;
    float preco_por_litro;
    
    // Estrutura para receber o retorno da função de cálculo
    ResultadoViagem resultado_final;

    // 1. Chama a função para ler os dados, passando o endereço das variáveis
    lerDadosViagem(&distancia_total_km, &consumo_medio_kml, &preco_por_litro);
    
    // 2. Chama a função de cálculo com os valores lidos
    resultado_final = calcularGastos(distancia_total_km, consumo_medio_kml, preco_por_litro);

    // 3. Exibe o resultado final formatado
    exibirResultadoViagem(resultado_final);

    return 0;
}


/**
 * @brief Lê os dados da viagem informados pelo usuário usando ponteiros.
 * @param ptr_distancia Ponteiro para a variável que armazenará a distância.
 * @param ptr_consumo Ponteiro para a variável que armazenará o consumo do veículo.
 * @param ptr_preco_combustivel Ponteiro para a variável que armazenará o preço do litro.
 */
void lerDadosViagem(float* ptr_distancia, float* ptr_consumo, float* ptr_preco_combustivel) {
    cout << "--- Calculadora de Custo de Viagem ---\n";
    cout << "Digite a distancia total da viagem (em km): ";
    cin >> *ptr_distancia; // Armazena o valor no endereço apontado pelo ponteiro

    cout << "Digite o consumo medio do veiculo (em km/l): ";
    cin >> *ptr_consumo; // Armazena o valor no endereço apontado pelo ponteiro

    cout << "Digite o preco do litro do combustivel (em R$): ";
    cin >> *ptr_preco_combustivel; // Armazena o valor no endereço apontado pelo ponteiro
}


/**
 * @brief Calcula a quantidade de litros e o custo total da viagem.
 * @param distancia_km Distância total a ser percorrida.
 * @param consumo_km_l Consumo do veículo.
 * @param preco_litro Preço do combustível.
 * @return Uma estrutura ResultadoViagem com os valores calculados.
 */
ResultadoViagem calcularGastos(float distancia_km, float consumo_km_l, float preco_litro) {
    ResultadoViagem resultado;

    // Evita divisão por zero caso o consumo seja inválido
    if (consumo_km_l > 0) {
        resultado.litros_necessarios = distancia_km / consumo_km_l;
    } else {
        resultado.litros_necessarios = 0;
    }
    
    resultado.custo_total = resultado.litros_necessarios * preco_litro;
    
    return resultado;
}


/**
 * @brief Exibe o resultado formatado do cálculo de gastos da viagem.
 * @param resultado A estrutura contendo os dados calculados da viagem.
 */
void exibirResultadoViagem(ResultadoViagem resultado) {
    cout << "\n-----------------------------------------\n";
    cout << "           RESULTADO DA VIAGEM           \n";
    cout << "-----------------------------------------\n";
    
    // Configura a saída para mostrar 2 casas decimais
    cout << fixed << setprecision(2);

    cout << "Litros de combustivel necessarios: " << resultado.litros_necessarios << " L" << endl;
    cout << "Custo total da viagem: R$ " << resultado.custo_total << endl;
    
    cout << "-----------------------------------------\n";
}