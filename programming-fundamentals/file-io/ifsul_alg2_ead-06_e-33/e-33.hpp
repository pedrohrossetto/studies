
#ifndef EAD6_E33_HPP
#define EAD6_E33_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>



bool reiniciar();
bool validar_base_cpf(char entrada_texto[]);
void aguardar_entrada();
int calcular_dv2(int digitos_cpf[]);
int calcular_dv1(int digitos_cpf[]);
int calcular_soma_recursiva(int digitos[], int indice, int fator);
void calcular_cpf_completo(int cpf[]);
void formatar_cpf_para_texto(const int cpf_inteiros[], char cpf_destino_texto[]);
void escrever_cpf(const char cpf_formatado_texto[], ofstream &arquivo_saida);
void ler_cpf_do_arquivo(ifstream &arquivo, int cpf_digitos[]);

void formatar_e_exibir(const int cpf_completo[], ofstream& arquivo_saida);

#endif // EAD6_E31_HPP