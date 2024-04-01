#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    // sqrt(ax+b) = c
    // ax+b = c*c
    // x = (c*c - b)/a
    if (a == 0 && c*c - b == 0 && c >= 0)
        cout << "MANY SOLUTIONS";
    else if ((a == 0  && c*c - b != 0) || c < 0 || (c*c - b) % a != 0)
        cout << "NO SOLUTION";
    else 
        cout << (c*c - b)/a;
    
}
 
/*
Решите в целых числах уравнение:
sqrt(ax + b) = c,

a, b, c – данные целые числа: найдите все решения или сообщите, что решений в целых числах нет.

Формат ввода
Вводятся три числа a, b и c по одному в строке.

Формат вывода
Программа должна вывести все решения уравнения в порядке возрастания, либо NO SOLUTION (заглавными буквами), если решений нет. Если решений бесконечно много, вывести MANY SOLUTIONS.
*/
