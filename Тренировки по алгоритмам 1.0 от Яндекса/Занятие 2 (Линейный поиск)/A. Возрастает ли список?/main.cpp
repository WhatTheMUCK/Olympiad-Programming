#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, preva = 0;
    bool flag = true;
    while (cin >> a){
        if (preva >= a)
            flag = false;
        preva = a;
    }
    cout << (flag ? "YES" : "NO");
}
