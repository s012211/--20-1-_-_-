// Lab-7.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

using namespace std;

int sqr_tr(int a, int b, int c) {
    int p = (a + b + c) / 2;
    int s = sqrt(p*(p - a)*(p - b)*(p - c));
    return s;
}

int square(int n, ...)
{       
    int* ptr = &n;
    int p = 0;
    int s = 0;

    if(n < 3){
        cout << "Недостаточно параметров" << endl;
        return 0;
    }

    if (n == 3) {
        return sqr_tr(ptr[1], ptr[2], ptr[3]);
    }

    for(int i = n; i > 0; i--)
    {
        p+= ptr[i];
    }

	p = p / 2;

    for (int i = n; i >= 0; i--)
    {
        if (i == n) {
            s += p * (p * ptr[i]);
        } else {
            s += p * ptr[i];
        }        
    }

    s = sqrt(s);

    return s;
}


 
int main(void)
{
    setlocale(LC_ALL, "Russian");
    
    printf("%d \n", square(3, 5, 3, 4));
    printf("%d \n", square(5, 1, 2, 3, 4, 5));
    printf("%d \n", square(8, 12, 21, 13, 4, 6, 9, 5, 6));
    
    return 0;
}