## E. Пирамида

|                     |           |
|---------------------|-----------|
| Ограничение времени | 1 секунда |
| Ограничение памяти  | 64Mb      |
| Ввод                | стандартный ввод или input.txt  |
| Вывод               | стандартный вывод или output.txt |

<br>

Для строительства двумерной пирамиды используются прямоугольные блоки, каждый из которых характеризуется шириной и высотой.  
Можно поставить один блок на другой, только если ширина верхнего блока строго меньше ширины нижнего (блоки нельзя поворачивать). Самым нижним в пирамиде может быть блок любой ширины.

По заданному набору блоков определите, пирамиду какой наибольшей высоты можно построить из них.

# Формат ввода

В первой строке входных данных задается число ***N*** — количество блоков (**1** ≤ ***N*** ≤ **1000000**).  
В следующих ***N***  строках задаются пары натуральных чисел ***w<sub>i</sub>*** и ***h<sub>i</sub>*** (**1** ≤ ***w<sub>i</sub>, h<sub>i</sub>*** ≤ **10<sup>9</sup>**) — ширина и высота блока соответственно.

# Формат вывода

Выведите одно целое число — максимальную высоту пирамиды.
