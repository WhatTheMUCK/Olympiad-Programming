#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string answer = "YES";
	vector<int> triangle(3);
	cin >> triangle[0] >> triangle[1] >> triangle[2];
	sort(triangle.begin(), triangle.end());
	if (triangle[0] + triangle[1] <= triangle[2])
		answer = "NO";
	cout << answer;
}

/*
Даны три натуральных числа. Возможно ли построить треугольник с такими сторонами. Если это возможно, выведите строку YES, иначе выведите строку NO.

Треугольник — это три точки, не лежащие на одной прямой.

Формат ввода
Вводятся три натуральных числа.

Формат вывода
Выведите ответ на задачу.

Пример 1
Ввод	Вывод
3
4
5

YES
Пример 2
Ввод	Вывод
3
5
4


YES
*/
