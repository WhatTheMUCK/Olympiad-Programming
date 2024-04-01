#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    set <string> set;
    while (cin >> a)
        set.insert(a);
    cout << set.size();
}
