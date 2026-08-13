
#ifndef EAD6_E32_HPP
#define EAD6_E32_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>


bool validar_chave(int chave);
int criptografar(int chave, char texto[101]);
int descriptografar(int chave, char texto[101]);
char solicitar_continuacao();

#endif // EAD6_E31_HPP