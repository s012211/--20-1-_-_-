// Lab-7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int fnc(int a[]) {
    int cl = 0;

    for (int i = 0; i <= sizeof(a); i++)
    {
        if (a[i] % 2 != 0) {

            cl++;
        };
    }
    return cl;
}

int fnc(string flow) {
    int flow_cl = 0;
    bool flow_start = false;
    
    for (int i = 0; i < flow.length(); i++)
    {
        if ((flow.substr(i, 1) != " " || flow.substr(i, 1) != ",") && flow_start == false) {
            flow_cl++;
            flow_start = true;
        }

        if (flow.substr(i, 1) == " " || flow.substr(i, 1) == "," ) {
            flow_start = false;
        }
    }

    return flow_cl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a[5] = { 1, 2, 3, 4, 5 };
    string b = "Тут цельное предложение из слов";
    
    cout << "а) для массива целых чисел находит количество нечетных элементов" << endl;
    cout << fnc(a) << "\n\n" ; 

    cout << "б) для строки находит количество слов в ней" << endl;
    cout << fnc(b) << endl;

    return 0;
}

