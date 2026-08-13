// Autor: Pedro H.C Rossetto
// Data: 07/04/2025
// Descrição: Código para para registrar atletas e suas notas
// Lista de Exercícios, Exercício 1, EAD6

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int num_laps = 5, lap, slowest_lap, fastest_lap;
    float lap_time, time_total, slowest_time = 0, fastest_time = 1000.01;

    for (lap = 1; lap <= num_laps; lap++)
    {
        do
        {
            cout << "Informe o tempo em segundos da volta " << lap << ":" << endl;
            cin >> lap_time;
        } while (lap_time <= 0 || lap_time > 1000);
        time_total += lap_time;
        if (lap_time < fastest_time)
        {
            fastest_time = lap_time;
            fastest_lap = lap;
        }
        if (lap_time > slowest_time)
        {
            slowest_time = lap_time;
            slowest_lap = lap;
        }
    }

    cout << fixed << setprecision(2);
    float average_time = time_total / num_laps;
    cout << "Média das voltas: " << average_time << endl;
    cout << "Volta mais rápida:\nVolta " << fastest_lap << "\nTempo: " << fastest_time << "s\n";
    cout << "Volta mais lenta:\nVolta " << slowest_lap << "\nTempo: " << slowest_time << "s\n";
    cout << "Tempo total de prova: " << time_total << "s" << endl;
}
