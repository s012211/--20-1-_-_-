// Lab-6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string alf[26][2] = {
        {"a", "э"}, {"b", "б"}, {"c", "с"}, {"d", "д"},
        {"e", "е"}, {"f", "ф"}, {"g", "г"}, {"h", ""},
        {"i", "и"}, {"j", "ж"}, {"k", "к"}, {"l", "л"},
        {"m", "м"}, {"n", "н"}, {"o", "о"}, {"p", "п"},
        {"q", "ку"}, {"r", "р"}, {"s", "с"}, {"t", "т"},
        {"u", "ю"}, {"v", "в"}, {"w", "въ"}, {"x", "икс"},
        {"y", "у"}, {"z", "з"}
    };
    string flow_w;

    while (true)
    {
        cout << "Введите слово ";
        getline(cin, flow_w);
        string new_flow = "";
        
        for (int i = 0; i < flow_w.length(); i++)
        {
            for (int g = 0; g < 26; g++)
            {
                if (alf[g][0] == flow_w.substr(i, 1))
                {
                    new_flow += alf[g][1];
                } else if(flow_w.substr(i, 1) == "_" && new_flow.substr(new_flow.length() - 1, 1) != "_"){
                    new_flow += flow_w.substr(i, 1);
                }
                //cout << flow_w[i] << endl;
            }            
        }

        cout << " - ";
        cout << new_flow << endl;
        cout << " -> ";
        getline(cin, flow_w);
    }

    return 0;
}
