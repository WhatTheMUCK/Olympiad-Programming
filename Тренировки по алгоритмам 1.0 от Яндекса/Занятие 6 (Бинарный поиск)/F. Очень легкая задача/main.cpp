#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    long long answer = 0;
    long long l = 0, r = (long double)1e18, m = (l + r) / 2;
    if (n == 1){
        answer += min(x, y);
    } else {
        answer += min(x, y);
        n--;
        while (r - l > 1){
            if ((m / x) + (m / y) >= n){
                r = m;
            } else {
                l = m;
            }
            m = (l + r) / 2;
        }
        if (l < m && (l / x) + (l / y) >= n){
            m = l;
        }
        if ((m / x) + (m / y) < n){
            m = r;
        }
        answer += m;
    }
    cout << answer;
}
