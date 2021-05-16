// Lab-1.cpp - Лабораторная работа 1 - Задача 1

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    float aF = 100;
    float bF = 0.001;
    
    double aD = 100;
    double bD = 0.001;

    float res1_1 = pow((aF - bF), 4) - (pow(aF, 4) - 4 * pow(aF, 4) * bF);
    float res1_2 = 6*pow(aF,2)*pow(bF,2) - 4*aF*pow(bF, 3) + pow(bF, 4);
    float res1 = res1_1 / res1_2;
    
    double res2_1 = pow((aD - bD), 4) - (pow(aD, 4) - 4 * pow(aF, 4) * bD);
    double res2_2 = 6*pow(aD,2)*pow(bD,2) - 4*aD*pow(bD, 3) + pow(bD, 4);
    double res2 = res2_1 / res2_2;
    
    cout << "Результат выполнения(float): "<< res1 <<" \n";
    cout << "Результат выполнения(double): " << res2 << " \n";
}
