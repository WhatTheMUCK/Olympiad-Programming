#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, ans = 0;
    vector<int> vec;
    while (cin >> a)
        vec.push_back(a);
    for (int i = 1; i < vec.size() - 1; i++)
        (vec[i] > vec[i - 1] && vec[i] > vec[i + 1] ? ans++ : ans = ans);
    cout << ans;
}
