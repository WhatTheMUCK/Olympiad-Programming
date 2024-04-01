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
    int n, l, r, answer = 0;
    cin >> n;
    set<pair<int, int>> set;
    for (int i = 0; i < n; i++){
        cin >> l >> r;
        set.insert({l, r});
    }
    for (auto elem : set){
        answer += (elem.first + elem.second + 1 == n && (elem.first >= 0 && elem.second >= 0)? 1 : 0);
    }
    cout << answer;
}
