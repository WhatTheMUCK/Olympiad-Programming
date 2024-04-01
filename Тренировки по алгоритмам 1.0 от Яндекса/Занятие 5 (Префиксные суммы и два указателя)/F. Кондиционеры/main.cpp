#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, m, b, c, maxInt = (1u << 31 - 1);
    long long sum = 0;
    unordered_map<int, int> classes;
    vector<int> confectioners(1001, maxInt);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        classes.find(a) != classes.end() ? classes[a]++ : classes[a] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> b >> c;
        if (confectioners[b] > c)
            confectioners[b] = c;
    }
    for (pair<int, int> elem : classes){
        int minCost = maxInt;
        for (int i = elem.first; i < confectioners.size(); i++){
            if (confectioners[i] < minCost)
                minCost = confectioners[i];
        }
        sum += minCost * elem.second;
    }
    cout << sum;
}
