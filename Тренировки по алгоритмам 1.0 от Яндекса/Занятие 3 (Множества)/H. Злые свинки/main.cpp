#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    set<int> set;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        set.insert(x);
    }
    cout << set.size();
}
