#include <iostream>

using namespace std;

int main()
{
    int n, k, m, answer = 0, temp;
    cin >> n >> k >> m;
    while (true) {
        temp = n / k;
        n = n % k;
        answer += temp * (k / m);
        n += (k % m) * temp;
        if (temp * (k / m) == 0)
            break;
    }
    cout << answer;
}
