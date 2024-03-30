#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

int n, m;
vector<vector<int>> grid, prefixSum;

// Функция для преобразования числа в строку с центрированием в заданной ширине
// string centerNumber(int number, int width) {
//     ostringstream oss;
//     oss << number;
//     string numStr = oss.str();

//     int padding = width - numStr.length();
//     int paddingLeft = padding / 2;
//     int paddingRight = padding - paddingLeft;

//     return string(paddingLeft, ' ') + numStr + string(paddingRight, ' ');
// }

bool checkPlus(int k) {
    int sumrd, sumld, sumru, sumlu, sum;
    //cout << "\nk: " << k << " n: " << n << " m: " << m << "\n";
    for (int i = k; i <= n - 2 * k; i++) {
        for (int j = k; j <= m - 2 * k; j++) {
            sum = prefixSum[i + 2 * k][j + 2 * k] - (prefixSum[i + 2 * k][j - k] + prefixSum[i - k][j + 2 * k]) + prefixSum[i - k][j - k]; //Квадрат размером 3k x 3k
            sumrd = prefixSum[i + 2 * k][j + 2 * k] - (prefixSum[i + 2 * k][j + k] + prefixSum[i + k][j + 2 * k]) + prefixSum[i + k][j + k]; //Правая нижняя пустота
            sumld = prefixSum[i + 2 * k][j] - (prefixSum[i + 2 * k][j - k] + prefixSum[i + k][j]) + prefixSum[i + k][j - k]; //Левая нижняя пустота
            sumru = prefixSum[i][j + 2 * k] - (prefixSum[i - k][j + 2 * k] + prefixSum[i][j + k]) + prefixSum[i - k][j + k]; //Правая верхняя пустота
            sumlu = prefixSum[i][j] - (prefixSum[i - k][j] + prefixSum[i][j - k]) + prefixSum[i - k][j - k]; //Левая верхняя пустота
            //cout << "i: " << i << " j: " << j << " sumrd: " << sumrd << " sumld: " << sumld << " sumru: " << sumru << " sumlu: " << sumlu << " sum: " << sum << " cross: " << sum - (sumrd + sumld + sumru + sumlu) << "\n";
            sum -= (sumrd + sumld + sumru + sumlu);
            if (sum == 5 * k * k) {
                return true;
            }
        }
    }
    return false;
}


int rBinarySearch(int l, int r, function<bool(int)> check){
    int m;
    while (r - l > 0){
       m = (l + r + 1) / 2;
       if (check(m)){
           l = m;
       } else {
           r = m - 1;
       }
    }
    return l;
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    prefixSum.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            grid[i][j] = (ch == '#');
            prefixSum[i + 1][j + 1] = grid[i][j] + (prefixSum[i][j + 1] + prefixSum[i + 1][j]) - prefixSum[i][j];
        }
    }
    
    // Найти максимальное число в prefixSum
    // int maxNum = 0;
    // for (const auto& row : prefixSum) {
    //     maxNum = max(maxNum, *max_element(row.begin(), row.end()));
    // }

    // Определить ширину поля для каждого числа
    // ostringstream oss;
    // oss << maxNum;
    // int fieldWidth = oss.str().length() + 2; // Длина максимального числа + 2 пробела

    // Вывод таблицы с центрированными числами
    // for (int i = 1; i < n + 1; ++i) {
    //     for (int j = 1; j < m + 1; ++j) {
    //         cout << centerNumber(prefixSum[i][j], fieldWidth);
    //     }
    //     cout << "\n";
    // }

    // Остальной код...
    // int lo = 0, hi = min(n, m), mid;
    // while (lo < hi) {
    //     mid = (hi + lo + 1) / 2;
    //     cout << "\nl: " << lo << " r: " << hi << " m: " << mid << "\n";
    //     if (checkPlus(mid)) {
    //         lo = mid;
    //     } else {
    //         hi = mid - 1;
    //     }
    // }
    cout << rBinarySearch(0, min(n,m), checkPlus);
    return 0;
}
/*
3 3
.#.
###
...
*/
