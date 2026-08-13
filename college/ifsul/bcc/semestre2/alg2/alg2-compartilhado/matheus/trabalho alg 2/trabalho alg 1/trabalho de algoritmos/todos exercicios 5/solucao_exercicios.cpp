#include <iostream>
#include <cstdio>    // Para NULL
#include <cstdlib>   // Para rand(), srand()
#include <fstream>   // Para ifstream, ofstream
#include <cstring>   // Pode ser necessário para algumas operações de string estilo C
#include <cmath>     // Para funções matemáticas
#include <iomanip>   // Para setprecision(), fixed
#include <ctime>     // Para time()

using namespace std;

//------------------------------------------------------------------
// EXERCÍCIO 21
//------------------------------------------------------------------
/**
 * @brief Calcula o peso ideal com base na altura e no sexo.
 * @param alt A altura da pessoa.
 * @param sexo O sexo da pessoa ('M' para masculino, 'F' para feminino).
 * @return O peso ideal calculado.
 */
float calcularPesoIdeal(float alt, char sexo) {
    if (sexo == 'M' || sexo == 'm') {
        return (72.7 * alt) - 58.0;
    } else if (sexo == 'F' || sexo == 'f') {
        return (62.1 * alt) - 44.7;
    }
    return 0; // Retorna 0 se o sexo for inválido
}

void exercicio21() {
    cout << "\n--- Exercício 21: Cálculo de Peso Ideal ---\n";
    float altura;
    char sexo;

    cout << "Digite sua altura (ex: 1.75): ";
    cin >> altura;
    cout << "Digite seu sexo (M/F): ";
    cin >> sexo;

    float peso = calcularPesoIdeal(altura, sexo);

    if (peso > 0) {
        cout << "Seu peso ideal é: " << fixed << setprecision(2) << peso << " kg." << endl;
    } else {
        cout << "Sexo inválido. Por favor, use 'M' ou 'F'." << endl;
    }
}


//------------------------------------------------------------------
// EXERCÍCIO 22
//------------------------------------------------------------------
/**
 * @brief Calcula a média de 3 notas com base no tipo especificado.
 * @param n1 Primeira nota.
 * @param n2 Segunda nota.
 * @param n3 Terceira nota.
 * @param letra 'A' para Aritmética, 'P' para Ponderada, 'H' para Harmônica.
 * @return A média calculada.
 */
float calcularMediaAluno(float n1, float n2, float n3, char letra) {
    switch (letra) {
        case 'A':
        case 'a':
            return (n1 + n2 + n3) / 3.0;
        case 'P':
        case 'p':
            return (n1 * 5 + n2 * 3 + n3 * 2) / (5.0 + 3.0 + 2.0);
        case 'H':
        case 'h':
            if (n1 == 0 || n2 == 0 || n3 == 0) return 0; // Evita divisão por zero
            return 3.0 / ((1.0 / n1) + (1.0 / n2) + (1.0 / n3));
        default:
            return -1; // Indica opção inválida
    }
}

void exercicio22() {
    cout << "\n--- Exercício 22: Cálculo de Média de Aluno ---\n";
    float n1, n2, n3;
    char tipoMedia;

    cout << "Digite as 3 notas do aluno: ";
    cin >> n1 >> n2 >> n3;
    cout << "Digite o tipo de média (A - Aritmética, P - Ponderada, H - Harmônica): ";
    cin >> tipoMedia;

    float media = calcularMediaAluno(n1, n2, n3, tipoMedia);

    if (media != -1) {
        cout << "A média calculada é: " << fixed << setprecision(2) << media << endl;
    } else {
        cout << "Opção de média inválida!" << endl;
    }
}


//------------------------------------------------------------------
// EXERCÍCIO 23
//------------------------------------------------------------------
/**
 * @brief Soma todos os inteiros entre B e C (inclusive) que são divisíveis por A.
 * @param A O divisor (deve ser > 1).
 * @param B O início do intervalo.
 * @param C O fim do intervalo.
 * @return A soma dos números divisíveis.
 */
int somarDivisiveis(int A, int B, int C) {
    if (A <= 1) {
        return 0; // Condição do problema: A > 1
    }

    int soma = 0;
    // Garante que o loop funcione independentemente se B > C ou C > B
    int inicio = min(B, C);
    int fim = max(B, C);

    for (int i = inicio; i <= fim; ++i) {
        if (i % A == 0) {
            soma += i;
        }
    }
    return soma;
}

void exercicio23() {
    cout << "\n--- Exercício 23: Soma de Divisíveis em um Intervalo ---\n";
    int a, b, c;

    cout << "Digite um número inteiro A (maior que 1): ";
    cin >> a;
    if (a <= 1) {
        cout << "Erro: A deve ser maior que 1." << endl;
        return;
    }
    cout << "Digite o intervalo de inteiros (B e C): ";
    cin >> b >> c;

    int resultado = somarDivisiveis(a, b, c);
    cout << "A soma dos números divisíveis por " << a << " entre " << b << " e " << c << " é: " << resultado << endl;
}


//------------------------------------------------------------------
// EXERCÍCIO 24 - Repositório de Funções
//------------------------------------------------------------------

// Protótipos das funções do repositório
float formata(float n);
void gera_vetor(int v[], int tam, int menor, int maior);
void ordena_vetor(int v[], int tam, char ordem);
bool primo(int n);
bool perfeito(int n);
void imprimir_vetor(int v[], int tam);

// Função 1: Retorna o número com precisão de 2 casas.
// Nota: Floats não guardam "formatação". A formatação é aplicada na exibição.
// Esta função arredonda o número para 2 casas decimais.
float formata(float n) {
    return round(n * 100.0) / 100.0;
}

// Função 2: Gera um vetor com valores pseudoaleatórios sem repetição.
void gera_vetor(int v[], int tam, int menor, int maior) {
    if (maior - menor + 1 < tam) {
        cout << "Erro: Impossível gerar " << tam << " números únicos no intervalo [" << menor << ", " << maior << "]." << endl;
        return;
    }
    bool repetido;
    int temp;
    for (int i = 0; i < tam; ++i) {
        do {
            repetido = false;
            temp = rand() % (maior - menor + 1) + menor;
            for (int j = 0; j < i; ++j) {
                if (v[j] == temp) {
                    repetido = true;
                    break;
                }
            }
        } while (repetido);
        v[i] = temp;
    }
}

// Função 3: Ordena um vetor (Bubble Sort).
void ordena_vetor(int v[], int tam, char ordem) {
    for (int i = 0; i < tam - 1; ++i) {
        for (int j = 0; j < tam - i - 1; ++j) {
            bool deveTrocar = false;
            if (ordem == 'c' || ordem == 'C') { // Crescente
                if (v[j] > v[j + 1]) deveTrocar = true;
            } else if (ordem == 'd' || ordem == 'D') { // Decrescente
                if (v[j] < v[j + 1]) deveTrocar = true;
            }
            if (deveTrocar) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// Função 4: Verifica se um número é primo.
bool primo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Função 5: Verifica se um número é perfeito.
bool perfeito(int n) {
    if (n <= 1) return false;
    int soma = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            soma += i;
            if (i * i != n) {
                soma += n / i;
            }
        }
    }
    return soma == n;
}

// Função auxiliar para imprimir vetores
void imprimir_vetor(int v[], int tam) {
    cout << "[ ";
    for (int i = 0; i < tam; ++i) {
        cout << v[i] << (i == tam - 1 ? "" : ", ");
    }
    cout << " ]" << endl;
}


void exercicio24() {
    cout << "\n--- Exercício 24: Teste do Repositório de Funções ---\n";
    int opcao;
    const int TAM_VETOR = 10;
    int vetor[TAM_VETOR];
    gera_vetor(vetor, TAM_VETOR, 1, 100); // Gera um vetor inicial para os testes

    do {
        cout << "\nMenu de Testes - Ex. 24:\n";
        cout << "1. Formatar número real\n";
        cout << "2. Gerar novo vetor aleatório\n";
        cout << "3. Ordenar vetor\n";
        cout << "4. Verificar número primo\n";
        cout << "5. Verificar número perfeito\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                float num;
                cout << "Digite um número real (ex: 123.456): ";
                cin >> num;
                cout << "Número original: " << num << endl;
                cout << "Número formatado (arredondado): " << formata(num) << endl;
                cout << "Usando iomanip para exibição: " << fixed << setprecision(2) << num << endl;
                break;
            }
            case 2: {
                int menor, maior;
                cout << "Gerando novo vetor de " << TAM_VETOR << " posições.\n";
                cout << "Digite o valor mínimo do intervalo: ";
                cin >> menor;
                cout << "Digite o valor máximo do intervalo: ";
                cin >> maior;
                gera_vetor(vetor, TAM_VETOR, menor, maior);
                cout << "Novo vetor gerado: ";
                imprimir_vetor(vetor, TAM_VETOR);
                break;
            }
            case 3: {
                char ordem;
                cout << "Vetor atual: ";
                imprimir_vetor(vetor, TAM_VETOR);
                cout << "Digite a ordem (c - crescente, d - decrescente): ";
                cin >> ordem;
                ordena_vetor(vetor, TAM_VETOR, ordem);
                cout << "Vetor ordenado: ";
                imprimir_vetor(vetor, TAM_VETOR);
                break;
            }
            case 4: {
                int n;
                cout << "Digite um número para verificar se é primo: ";
                cin >> n;
                if (primo(n)) {
                    cout << n << " é um número primo." << endl;
                } else {
                    cout << n << " não é um número primo." << endl;
                }
                break;
            }
            case 5: {
                int n;
                cout << "Digite um número para verificar se é perfeito: ";
                cin >> n;
                if (perfeito(n)) {
                    cout << n << " é um número perfeito." << endl;
                } else {
                    cout << n << " não é um número perfeito." << endl;
                }
                break;
            }
            case 0:
                cout << "Saindo do teste do repositório...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}


//------------------------------------------------------------------
// EXERCÍCIO 25 - Análise de Temperaturas
//------------------------------------------------------------------

const int MESES = 12;
const string nomesMeses[MESES] = {
    "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
};

bool lerTemperaturas(float temps[]) {
    ifstream arquivo("temperaturas.txt");
    if (!arquivo.is_open()) {
        cout << "Erro: Não foi possível abrir o arquivo 'temperaturas.txt'." << endl;
        cout << "Por favor, crie o arquivo com 12 temperaturas, uma por linha." << endl;
        return false;
    }
    for (int i = 0; i < MESES; ++i) {
        if (!(arquivo >> temps[i])) {
            cout << "Erro ao ler o arquivo. Verifique se ele contém 12 números." << endl;
            arquivo.close();
            return false;
        }
    }
    arquivo.close();
    cout << "Temperaturas lidas com sucesso." << endl;
    return true;
}

void menorTemperatura(const float temps[]) {
    float menor = temps[0];
    int mes = 0;
    for (int i = 1; i < MESES; ++i) {
        if (temps[i] < menor) {
            menor = temps[i];
            mes = i;
        }
    }
    cout << "Menor temperatura do ano foi " << fixed << setprecision(2) << menor << "°C em " << nomesMeses[mes] << "." << endl;
}

void maiorTemperatura(const float temps[]) {
    float maior = temps[0];
    int mes = 0;
    for (int i = 1; i < MESES; ++i) {
        if (temps[i] > maior) {
            maior = temps[i];
            mes = i;
        }
    }
    cout << "Maior temperatura do ano foi " << fixed << setprecision(2) << maior << "°C em " << nomesMeses[mes] << "." << endl;
}

float mediaAnual(const float temps[]) {
    float soma = 0;
    for (int i = 0; i < MESES; ++i) {
        soma += temps[i];
    }
    return soma / MESES;
}

void mesesAbaixoDaMedia(const float temps[]) {
    float media = mediaAnual(temps);
    int contador = 0;
    for (int i = 0; i < MESES; ++i) {
        if (temps[i] < media) {
            contador++;
        }
    }
    cout << "A temperatura foi inferior à média anual (" << fixed << setprecision(2) << media << "°C) em " << contador << " meses." << endl;
}

void exercicio25() {
    cout << "\n--- Exercício 25: Análise de Temperaturas Anuais ---\n";
    float temperaturas[MESES];
    if (!lerTemperaturas(temperaturas)) {
        return; // Não continua se o arquivo não puder ser lido
    }

    int opcao;
    do {
        cout << "\nMenu de Análise de Temperaturas:\n";
        cout << "1. Menor temperatura do ano\n";
        cout << "2. Maior temperatura do ano\n";
        cout << "3. Temperatura média anual\n";
        cout << "4. Meses com temperatura abaixo da média\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: menorTemperatura(temperaturas); break;
            case 2: maiorTemperatura(temperaturas); break;
            case 3: cout << "Temperatura média anual: " << fixed << setprecision(2) << mediaAnual(temperaturas) << "°C" << endl; break;
            case 4: mesesAbaixoDaMedia(temperaturas); break;
            case 0: cout << "Saindo da análise de temperaturas...\n"; break;
            default: cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

//------------------------------------------------------------------
// EXERCÍCIO 26 - Operações com Vetores
//------------------------------------------------------------------
const int TAM_26 = 10;

// Reuso da função do Ex24 para gerar um único vetor
void gerarVetorUnico(int v[], int tam, int min, int max) {
    bool repetido;
    int temp;
    for (int i = 0; i < tam; ++i) {
        do {
            repetido = false;
            // Intervalo é [36, 84]
            temp = rand() % (max - min - 1) + (min + 1);
            for (int j = 0; j < i; ++j) {
                if (v[j] == temp) {
                    repetido = true;
                    break;
                }
            }
        } while (repetido);
        v[i] = temp;
    }
}

void gerarVetores_26(int x1[], int x2[]) {
    gerarVetorUnico(x1, TAM_26, 35, 85);
    gerarVetorUnico(x2, TAM_26, 35, 85);
    cout << "Vetores x1 e x2 gerados com sucesso." << endl;
}

void mostrarVetores_26(const int x1[], const int x2[]) {
    cout << "Vetor x1: ";
    imprimir_vetor((int*)x1, TAM_26);
    cout << "Vetor x2: ";
    imprimir_vetor((int*)x2, TAM_26);
}

void interseccao_26(const int x1[], const int x2[], int x3[], int& tam_x3) {
    tam_x3 = 0;
    for (int i = 0; i < TAM_26; ++i) {
        for (int j = 0; j < TAM_26; ++j) {
            if (x1[i] == x2[j]) {
                // Checa se o elemento já está em x3 para evitar duplicatas na intersecção
                bool encontrado = false;
                for (int k = 0; k < tam_x3; ++k) {
                    if (x3[k] == x1[i]) {
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    x3[tam_x3++] = x1[i];
                }
                break; // Otimização: passa para o próximo elemento de x1
            }
        }
    }

    ofstream arquivo("exer_26.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao criar o arquivo 'exer_26.txt'." << endl;
        return;
    }

    // Escreve x1
    for (int i = 0; i < TAM_26; ++i) arquivo << x1[i] << (i == TAM_26 - 1 ? "" : ",");
    arquivo << endl;
    // Escreve x2
    for (int i = 0; i < TAM_26; ++i) arquivo << x2[i] << (i == TAM_26 - 1 ? "" : ",");
    arquivo << endl;
    // Escreve x3
    for (int i = 0; i < tam_x3; ++i) arquivo << x3[i] << (i == tam_x3 - 1 ? "" : ",");
    arquivo << endl;

    arquivo.close();
    cout << "Vetor de intersecção gerado e os três vetores foram salvos em 'exer_26.txt'." << endl;
}

void exercicio26() {
    cout << "\n--- Exercício 26: Operações com Vetores ---\n";
    int x1[TAM_26], x2[TAM_26], x3[TAM_26];
    int tam_x3 = 0;
    bool vetoresGerados = false;
    int opcao;

    do {
        cout << "\nMenu de Operações com Vetores:\n";
        cout << "1. Gerar vetores\n";
        cout << "2. Mostrar vetores\n";
        cout << "3. Gerar Intersecção e salvar em arquivo\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                gerarVetores_26(x1, x2);
                vetoresGerados = true;
                break;
            case 2:
                if (vetoresGerados) {
                    mostrarVetores_26(x1, x2);
                } else {
                    cout << "Primeiro gere os vetores (opção 1)." << endl;
                }
                break;
            case 3:
                if (vetoresGerados) {
                    interseccao_26(x1, x2, x3, tam_x3);
                    cout << "Intersecção x3: ";
                    imprimir_vetor(x3, tam_x3);
                } else {
                    cout << "Primeiro gere os vetores (opção 1)." << endl;
                }
                break;
            case 0:
                cout << "Saindo das operações com vetores...\n";
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);
}


//------------------------------------------------------------------
// EXERCÍCIO 27 - Operações com Matrizes
//------------------------------------------------------------------
const int DIM_27 = 5;

// Verifica se um valor já existe na matriz
bool valorExisteNaMatriz(const int mat[DIM_27][DIM_27], int linhas, int cols, int valor) {
    for (int i = 0; i < DIM_27; ++i) {
        for (int j = 0; j < DIM_27; ++j) {
            if (i < linhas || (i == linhas && j < cols)) {
                if (mat[i][j] == valor) return true;
            }
        }
    }
    return false;
}

bool lerMatriz(int mat[DIM_27][DIM_27]) {
    ifstream arquivo("matriz.txt");
    if (!arquivo.is_open()) {
        cout << "Erro: Não foi possível abrir o arquivo 'matriz.txt'." << endl;
        cout << "Por favor, crie o arquivo com valores inteiros separados por ';'." << endl;
        return false;
    }

    int valor;
    char delimitador;
    int count = 0;

    while (count < DIM_27 * DIM_27 && arquivo >> valor) {
        if (valor <= 50 && !valorExisteNaMatriz(mat, count / DIM_27, count % DIM_27, valor)) {
            mat[count / DIM_27][count % DIM_27] = valor;
            count++;
        }
        // Consome o delimitador ';'
        if (arquivo.peek() == ';') {
             arquivo >> delimitador;
        }
    }

    arquivo.close();

    if (count < DIM_27 * DIM_27) {
        cout << "Aviso: Não foi possível preencher a matriz. Foram lidos apenas " << count << " valores válidos e únicos." << endl;
        return false;
    }

    cout << "Matriz lida e preenchida com sucesso." << endl;
    return true;
}

void mostrarMatrizETransposta(const int mat[DIM_27][DIM_27]) {
    cout << "\nMatriz Original:\n";
    for (int i = 0; i < DIM_27; ++i) {
        for (int j = 0; j < DIM_27; ++j) {
            cout << setw(4) << mat[i][j];
        }
        cout << endl;
    }

    cout << "\nMatriz Transposta:\n";
    for (int i = 0; i < DIM_27; ++i) {
        for (int j = 0; j < DIM_27; ++j) {
            cout << setw(4) << mat[j][i];
        }
        cout << endl;
    }
}

void infoDiagonalPrincipal(const int mat[DIM_27][DIM_27]) {
    cout << "\nDiagonal Principal: ";
    for (int i = 0; i < DIM_27; ++i) cout << mat[i][i] << " ";
    cout << endl;

    cout << "Acima da Diagonal Principal: ";
    for (int i = 0; i < DIM_27; ++i) {
        for (int j = i + 1; j < DIM_27; ++j) {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;

    cout << "Abaixo da Diagonal Principal: ";
    for (int i = 0; i < DIM_27; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;
}


void infoDiagonalSecundaria(const int mat[DIM_27][DIM_27]) {
    cout << "\nDiagonal Secundária: ";
    for (int i = 0; i < DIM_27; ++i) cout << mat[i][DIM_27 - 1 - i] << " ";
    cout << endl;

    cout << "Acima da Diagonal Secundária: ";
     for (int i = 0; i < DIM_27; ++i) {
        for (int j = 0; j < DIM_27 - 1 - i; ++j) {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;

    cout << "Abaixo da Diagonal Secundária: ";
    for (int i = 0; i < DIM_27; ++i) {
        for (int j = DIM_27 - i; j < DIM_27; ++j) {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;
}

void exercicio27() {
    cout << "\n--- Exercício 27: Operações com Matrizes 5x5 ---\n";
    int matriz[DIM_27][DIM_27];
    bool matrizLida = false;
    int opcao;

    do {
        cout << "\nMenu de Operações com Matriz:\n";
        cout << "1. Ler matriz do arquivo 'matriz.txt'\n";
        cout << "2. Mostrar matriz e sua transposta\n";
        cout << "3. Informações da Diagonal Principal\n";
        cout << "4. Informações da Diagonal Secundária\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao > 1 && opcao < 5 && !matrizLida) {
            cout << "Erro: A opção 1 deve ser executada primeiro para ler a matriz." << endl;
            continue;
        }

        switch (opcao) {
            case 1:
                matrizLida = lerMatriz(matriz);
                break;
            case 2:
                mostrarMatrizETransposta(matriz);
                break;
            case 3:
                infoDiagonalPrincipal(matriz);
                break;
            case 4:
                infoDiagonalSecundaria(matriz);
                break;
            case 0:
                cout << "Saindo das operações com matrizes...\n";
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);
}


//------------------------------------------------------------------
// FUNÇÃO MAIN - MENU PRINCIPAL
//------------------------------------------------------------------
int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    int escolha;
    do {
        cout << "\n\n========= MENU DE EXERCÍCIOS DE ALGORITMOS II =========\n";
        cout << "21. Calcular Peso Ideal\n";
        cout << "22. Calcular Média de Aluno\n";
        cout << "23. Somar Divisíveis\n";
        cout << "24. Repositório de Funções\n";
        cout << "25. Análise de Temperaturas (requer 'temperaturas.txt')\n";
        cout << "26. Operações com Vetores\n";
        cout << "27. Operações com Matrizes (requer 'matriz.txt')\n";
        cout << "0. Sair do Programa\n";
        cout << "=========================================================\n";
        cout << "Escolha o exercício que deseja executar: ";
        cin >> escolha;

        switch (escolha) {
            case 21: exercicio21(); break;
            case 22: exercicio22(); break;
            case 23: exercicio23(); break;
            case 24: exercicio24(); break;
            case 25: exercicio25(); break;
            case 26: exercicio26(); break;
            case 27: exercicio27(); break;
            case 0: cout << "Programa finalizado." << endl; break;
            default: cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (escolha != 0);

    return 0;
}
