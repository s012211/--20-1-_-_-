// Lab-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, a = 0.1, b = 1;
    int k = 10;
    double Summ_n = 0, Summ_E = 0;
    int n = 35;
    
    float step = (b - a) / k;
    for (x = a; x <= b; x += step)
    {
        for (int i = 0; i < n; i++)
        {

            Summ_n = Summ_n + pow(-1, i) * ((2 * pow(i, 2) + 1)/ (2 * i)) * pow(x, 2*i) ;
        }

        int j = 0;

        while (pow(-1, j) * ((2 * pow(j, 2) + 1) / (2 * j)) * pow(x, 2 * j) >= 0.0001)
        {
            Summ_E = Summ_E + pow(-1, j) * ((2 * pow(j, 2) + 1) / (2 * j)) * pow(x, 2 * j);
            j++;
        }

        y = (1 - pow(x, 2) / 2) * cos(x) - x/2 * sin(x);
        
        cout << "X= " << x << "  SN= " << Summ_n
             << "  SE= " << Summ_E << "  Y= " << y << "\n";
        
        Summ_n = 0;
        Summ_E = 0;
    }
}