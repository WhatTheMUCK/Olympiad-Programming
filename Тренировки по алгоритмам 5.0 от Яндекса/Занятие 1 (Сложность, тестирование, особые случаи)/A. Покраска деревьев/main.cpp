#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, v, q, m, min1, min2, max1, max2;
    cin >> p >> v >> q >> m;
    if (p <= q){
        min1 = p - v, max1 = p + v, min2 = q - m, max2 = q + m;
    } else {
        min2 = p - v, max2 = p + v, min1 = q - m, max1 = q + m;
    }
    int sum = 0;
    sum += (abs(max1 - min1) + 1) + (abs(max2 - min2) + 1);
    //cout << min1 << " " << max1 << " " << min2 << " " << max2 << "\n";
    vector<int> a = {min1, max1, min2, max2};
    if (max1 >= min2){
        sort(a.begin(), a.end());
        sum -= abs(a[2] - a[1]) + 1;
    }
    cout << sum;
}
