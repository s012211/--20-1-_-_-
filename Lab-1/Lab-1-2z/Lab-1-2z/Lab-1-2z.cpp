// Lab-1.cpp - Лабораторная работа 1 - Задача 2

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    int m, n;

    cout << "Введите значение m ";
    cin >> m;

    cout << "Введите значение n ";
    cin >> n;
    
    // 1) ++n*++m
    int res1 = ++n * ++m;
   
    // 2) m++<n
    bool res2 = m++ < n;

    // 3) ++n*++m
    bool res3 = n++ > m;

    cout << "Результат опероации ++n * ++m  Равен " << res1 << "\n";
    cout << "Результат опероации m++ < n  Равен " << res2 << "\n";
    cout << "Результат опероации n++ > m  Равен " << res3 << "\n";
}