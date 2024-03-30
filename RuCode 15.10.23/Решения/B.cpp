#include <iostream>

using namespace std;

int main()
{
    long long a = 1, b = 2, c = 3, d = 5, a_last, a_prev = 1, a_prev_prev;
    int n, a_len = 1, temp = 1;
    cin >> n;
    while (n - a_len > 0){
        a_last = b;
        b = c;
        c = d;
        d = (b + c) % 998244353;
        a_len += ++temp;
    }
    while (n - a_len + temp != 1){
        a_prev_prev = a_prev;
        a_prev = a;
        a = (a_prev_prev + a_prev) % 998244353;
        temp--;
    }
    cout << (a + b + c + d) % 998244353;
}
