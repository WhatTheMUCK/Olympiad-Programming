#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        sum += a / 4;
        a %= 4;
        if (a >= 2)
            sum += 2;
        else 
            sum += a;
    }
    cout << sum;
}
