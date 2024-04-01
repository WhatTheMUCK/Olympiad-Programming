#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    set <string> settemp, set_intersect, set_union;
    int n, m;
    string language;
    cin >> n;
    cin >> m;
    for (int j = 0; j < m; j++){
        cin >> language;
        set_intersect.insert(language);
        set_union.insert(language);
    }
    for (int i = 1; i < n; i++){
        set <string> settemp, setswap;
        cin >> m;
        for (int j = 0; j < m; j++){
            cin >> language;
            settemp.insert(language);
            set_union.insert(language);
        }
        set_intersection(set_intersect.begin(), set_intersect.end(), settemp.begin(), settemp.end(), inserter(setswap, setswap.begin()));
        set_intersect = setswap;
        setswap = {};
    }
    cout << set_intersect.size() << "\n";
    for (auto elem : set_intersect)
        cout << elem << "\n";
    cout << set_union.size() << "\n";
    for (auto elem : set_union)
        cout << elem << "\n";
}
