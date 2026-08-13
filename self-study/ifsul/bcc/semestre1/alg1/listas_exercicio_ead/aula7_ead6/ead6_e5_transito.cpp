// Autor: Pedro H.C Rossetto
// Data: 21/04/2025
// Descrição: Código cidades e transito
// Lista de Exercícios, Exercício 5, EAD6
// a) qual é o maior e qual é o menor índice de acidentes de trânsito e a que cidades pertencem;
// b) qual é a média de veículos nas cinco cidades juntas;
// c) qual é a média de acidentes de trânsito nas cidades com menos de 2.000 veículos de passeio.

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int small_town_counter = 0, city_counter, city_code; // configurar iteração e referencia
	int city_cars, city_accidents, small_town_accidents; // imput de cada cidade
	int sum_cars, sum_accidents;						 // armazenar de cada cidade
	float average_cars, average_small_town_accidents;	 // média final
	int highest_average_accidents = 0, lowest_average_accidents = INT_MAX;
	int cityCode_highest_average, cityCode_lowest_average; // definir código da cidade por comparação

	for (city_counter = 0; city_counter < 5; city_counter++)
	{
		cout << "Informe o número de código da cidade:\n";
		cin >> city_code;

		cout << "Informe número de acidentes de trânsito com vítimas:\n";
		cin >> city_accidents;
		while (city_accidents < 0)
		{
			cout << "Erro: O número de acidentes não pode ser negativo. Tente novamente:\n";
			cin >> city_accidents;
		}
		sum_accidents += city_accidents;

		cout << "Informe número de veículos:\n";
		cin >> city_cars;
		while (city_cars < 0)
		{
			cout << "Erro: O número de veículos não pode ser negativo. Tente novamente:\n";
			cin >> city_cars;
		}
		sum_cars += city_cars;

		if (city_cars < 2000)
		{
			small_town_counter++;
			small_town_accidents += city_accidents;
			average_small_town_accidents = small_town_accidents / small_town_counter;
		}

		if (city_accidents > highest_average_accidents)
		{
			cityCode_highest_average = city_code;
			highest_average_accidents = city_accidents;
		}
		if (city_accidents < lowest_average_accidents)
		{
			cityCode_lowest_average = city_code;
			lowest_average_accidents = city_accidents;
		}
	}
	average_cars = sum_cars / city_counter;

	cout << "Cidade com maior índice de acidentes de trânsito:\n";
	cout << "Código da cidade: " << cityCode_highest_average << "\n";
	cout << "Número de acidentes: " << highest_average_accidents << "\n\n";

	cout << "Cidade com menor índice de acidentes de trânsito:\n";
	cout << "Código da cidade: " << cityCode_lowest_average << "\n";
	cout << "Número de acidentes: " << lowest_average_accidents << "\n\n";

	cout << "Média de veículos nas cinco cidades: " << average_cars << "\n\n";

	if (small_town_counter > 0)
	{
		cout << "Média de acidentes de trânsito nas cidades com menos de 2.000 veículos de passeio: " << average_small_town_accidents << "\n";
	}
	else
	{
		cout << "Nenhuma cidade com menos de 2.000 veículos de passeio foi registrada.\n";
	}
	return 0;
}
