#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

// Предикат, который мы хотим использовать
bool checkForLBS(long long m, long long value) {
    return m >= value;
}

bool checkForRBS(long long m, long long value) {
    return m <= value;
}

bool checkShip(long long m, long long n, vector<long long>& sum){
    if (m > sum.size()){
        return false;
    } else {
        //cout << " m: " << m << " сумма клеток: " << sum[m - 1] << "\n";
        return sum[m - 1] <= n;
    }
}

long long rBinarySearch(long long l, long long r, function<bool(long long, long long, vector<long long>&)> check, long long n, vector<long long>& sum){
    long long m;
    while (r - l > 0){
        m = (l + r + 1) / 2;
        //cout << "\nl: " << l << " r: " << r;
        if (check(m, n, sum)){
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, temp = 1, i = 1;
    cin >> n;
    vector<long long> sum;
    while (temp < (long long)1e18){
        sum.push_back(temp);
        temp += (2 + (i + 2)) * (i + 1) / 2;
        i++;
    }
    if (n == 0){
        cout << "0";
    } else {
        cout << rBinarySearch(1, (long long)sqrt(n), checkShip, n, sum);
    }
}
