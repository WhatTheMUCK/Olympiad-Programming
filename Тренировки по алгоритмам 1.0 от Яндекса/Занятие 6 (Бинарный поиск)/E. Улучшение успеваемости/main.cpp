#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long two, three, four;
    cin >> two >> three >> four;
    long long l = 0, r = (long long)1e18, m = (l + r) / 2;
    long double average;
    while (r - l > 1){
        average = (long double)(2 * two + 3 * three + 4 * four + 5 * m) / (two + three + four + m);
        if (average > 3.5){
            r = m;
        } else {
            l = m;
        }
        m = (l + r) / 2;
    }
    average = (long double)(2 * two + 3 * three + 4 * four + 5 * l) / (two + three + four + l);
    if (l < m && average >= 3.5){
        m = l;
    }
    average = (long double)(2 * two + 3 * three + 4 * four + 5 * m) / (two + three + four + m);
    if (average < 3.5){
        m = r;
    }
    cout << m;
}
