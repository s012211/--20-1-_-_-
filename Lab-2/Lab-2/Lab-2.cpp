// Lab-2.cpp - Лабораторная работа 2
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    float arr[15];
    float sum = 0;
    int n;

    cout << "Введите начальное значение ";
    cin >> n;

    for (int i = 0; i < 15; i++) {
        arr[i] = pow(n, log(n)) / pow(log(n), n);

        cout << (i + 1) << ") " << arr[i] << "\n";

        sum += arr[i];

        n++;
    }

    cout << "Сумма: " << sum << "\n";

}