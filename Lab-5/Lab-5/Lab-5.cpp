// Lab-5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    int t;

    cout << "Введите длину строк массива ";
    cin >> n;

    cout << "Введите длину столбцов массива ";
    cin >> t;

    int** A = new int*[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[t];
    }

    for (int i = 0; i < n; i++)
    {

        for (int z = 0; z < t; z++)
        {             
            A[i][z] = rand() % 10;
            cout << A[i][z] << " ";
        }
        cout << endl;
    }
    cout << endl;

    double first = 0;
    int stlb_sum = 0;
    for (int z = 0; z < t; z++)
    {
        double sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += A[i][z];
        }        

        if (z == 0) {
            first = sum / n;
        }

        if (first < sum / n) {
            stlb_sum++;
        }

        cout << "Среднее арефмитическое стобца " << z + 1 << " = " << sum/n << endl;
        cout << endl;
    }
    
    cout << "Сумма столбцов " << stlb_sum << endl;
    cout << endl;
    return 0;
}