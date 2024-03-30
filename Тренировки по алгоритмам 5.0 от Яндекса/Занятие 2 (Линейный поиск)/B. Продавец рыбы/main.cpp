#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, cost, maxplus = 0;
    cin >> n >> k;
    vector<int> costs(n);
    for (int i = 0; i < n; i++){
        cin >> costs[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= k && i + j < n; j++){
            if (costs[i + j] - costs[i] > maxplus)
                maxplus = costs[i + j] - costs[i];
        }
    }
    cout << maxplus;
}    
