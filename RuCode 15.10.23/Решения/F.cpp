#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    while (a != b && a > 1 && b > 1){
        if (a > b){
            a %= b;
        } else {
            b %= a;
        }
    }
    if (a == 1 || b ==1)
        return 1;
    if (a*b != 0)
        return a;
    return max(a,b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> del;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= 1;
    }
    int prev;
    prev = gcd(a[0], a[1]);
    for (int i = 2; i < n; i++){
        prev = gcd(prev, a[i]);
    }
    for (int i = 1; i <= sqrt(prev); i++){
        if (prev % i == 0){
            if (i * i == prev){
                del.push_back(i);
            } else {
                del.push_back(i);
                del.push_back(prev/i);
            }
        }
        
    }
    sort(del.begin(), del.end());
    for (int i = 0; i < del.size(); i++){
        cout << del[i] << "\n";
    }
}
