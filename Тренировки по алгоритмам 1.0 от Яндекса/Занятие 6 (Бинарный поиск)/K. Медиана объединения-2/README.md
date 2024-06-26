## K. Медиана объединения-2

|                     |           |
|---------------------|-----------|
| Ограничение времени | 5 секунд |
| Ограничение памяти  | 256Mb      |
| Ввод                | стандартный ввод или input.txt  |
| Вывод               | стандартный вывод или output.txt |

<br>

Дано N упорядоченных по неубыванию последовательностей целых чисел (т.е. каждый следующий элемент больше либо равен предыдущему), в каждой из последовательностей ровно L элементов. Для каждых двух последовательностей выполняют следующую операцию: объединяют их элементы (в объединенной последовательности каждое число будет идти столько раз, сколько раз оно встречалось суммарно в объединяемых последовательностях), упорядочивают их по неубыванию и смотрят, какой элемент в этой последовательности из 2L элементов окажется на месте номер L (этот элемент называют левой медианой).

Напишите программу, которая для каждой пары последовательностей выведет левую медиану их объединения.

# Формат ввода

Сначала вводятся числа N и L (2 ≤ N ≤ 200, 1 ≤ L ≤ 50000). В следующих N строках задаются параметры, определяющие последовательности.

Каждая последовательность определяется пятью целочисленными параметрами: *x<sub>1</sub>*, *d<sub>1</sub>*, a, c, m. Элементы последовательности вычисляются по следующим формулам: *x<sub>1</sub>* нам задано, а для всех i от 2 до L: *x<sub>i</sub>* = *x<sub>i-1</sub>*+*d<sub>i-1</sub>*. Последовательность *d<sub>i</sub>* определяется следующим образом: *d<sub>1</sub>* нам задано, а для i ≥ 2 *d<sub>i</sub>* = ((a*<i>d<sub>i-1</sub></i>+c) mod m), где mod – операция получения остатка от деления (a*<i>d<sub>i-1</sub></i>+c) на m.

Для всех последовательностей выполнены следующие ограничения: 1 ≤ m ≤ 40000, 0 ≤ a < m, 0≤c<m, 0≤<i>d<sub>1</sub></i><m. Гарантируется, что все члены всех последовательностей по модулю не превышают 109.

# Формат вывода

В первой строке выведите медиану объединения 1-й и 2-й последовательностей, во второй строке — объединения 1-й и 3-й, и так далее, в (N‑1)-ой строке — объединения 1-й и N-ой последовательностей, далее медиану объединения 2-й и 3-й, 2-й и 4-й, и т.д. до 2-й и N-ой, затем 3-й и 4-й и так далее. В последней строке должна быть выведена медиана объединения (N–1)-й и N-ой последовательностей.
