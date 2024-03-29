#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a1, a2;
    cin >> n;
    cin >> a1;
    a1 %= 2;
    for (int i = 1; i < n; i++){
        cin >> a2;
        a2 %= 2;
        if (a1 % 2 != 0 && a2 % 2 != 0){
            cout << 'x';
        } else{
            cout << '+';
        }
        a1 = max(abs(a1), abs(a2));
    }
}
