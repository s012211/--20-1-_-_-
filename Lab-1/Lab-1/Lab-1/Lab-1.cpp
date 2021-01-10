// Lab-1.cpp - Лабораторная работа 1 - Задача 1

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    int a = 100;
    float b = 0.001;

    float res1 = pow((a - b), 4) - (pow(a, 4) - 4 * pow(a, 4) * b) / 6*pow(a,2)*pow(b,2) - 4*a*pow(b, 3) + pow(b, 4);
    double res2 = pow((a - b), 4) - (pow(a, 4) - 4 * pow(a, 4) * b) / 6 * pow(a, 2) * pow(b, 2) - 4 * a * pow(b, 3) + pow(b, 4);
    
    cout << "Результат выполнения(float): "<< res1 <<" \n";
    cout << "Результат выполнения(double): " << res2 << " \n";
}