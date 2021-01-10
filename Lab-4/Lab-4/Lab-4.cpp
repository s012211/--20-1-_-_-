// Lab-4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int n;
    bool play = true;

    cout << "Введите длину массива ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        // Заполнение массива
        arr[i] = rand() % 100 + 1;
        cout << (i + 1) << ") " << arr[i] << endl;
    }

    while (play)
    {
        int r;
        cout << "\nВведите новый эллемент ";
        cin >> r;

        for (int i = n; i > 1; i--) {
            arr[i - 1] = arr[i - 2];
        }

        arr[0] = r;

        cout << "\nНовый Массив \n";
        for (int i = 0; i < n; i++) {
            cout << (i + 1) << ") " << arr[i] << endl;
        }
    }
    return 0;
}