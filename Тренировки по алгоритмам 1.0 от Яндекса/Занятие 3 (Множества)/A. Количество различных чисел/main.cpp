#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    set<int> set;
    while (cin >> a)
        set.insert(a);
    cout << set.size();
}
