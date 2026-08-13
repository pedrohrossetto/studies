// Autor: Pedro H.C Rossetto
// Data: 02/04/2025
// Descrição: Código para verificar média da turma
// Lista de Exercícios, Exercício 1, EAD6

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main () {

int size_class,i;
vector<float> grades;
float student_grade, sum_grades;
float smallest_grade = 11, largest_grade = 0;


do {cout << "Informe o tamanho da turma: \n";
cin >> size_class;} while (size_class <= 0);

for (i = 1; i <= size_class;i++)
{
cout << "Nota do Aluno " << i << ": \n";
cin >> student_grade;
sum_grades += student_grade;
grades.push_back(student_grade);
if (student_grade < smallest_grade) {
	smallest_grade = student_grade;
if (student_grade >= largest_grade) {
	largest_grade = student_grade; // Erro, não sei o que está acontecendo
}
}
}

// Exibe o resultado com 2 casas decimais
cout << fixed << setprecision(2);
float average = sum_grades / size_class;
cout << "Média da turma: " << average << endl;
cout << "Notas da turma: " << endl;
cout << "Menor nota: " << smallest_grade << endl;
cout << "Maior nota: " << largest_grade << endl;
cout << "Notas dos alunos: ";
// Exibe as notas dos alunos
for (int i = 0; i < size_class; i++) { 
	cout << grades[i] << " ";
}
cout << endl;
return 0;

}
