#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <set>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, x, y, vecx, vecy;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    vector<vector<long long>> segments(n, vector<long long>());
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        points[i] = {x, y};
    }
    long long sum = 0;
    for (int i = 0; i < n; i++){
        set<pair<long long, long long>> distincts;
        for (int j = 0; j < n; j++){
            vecx = points[i].first - points[j].first;
            vecy = points[i].second - points[j].second;
            segments[i].push_back(vecx * vecx  + vecy * vecy);
            if (distincts.find({vecx, vecy}) == distincts.end()){
                distincts.insert({-1 * vecx, -1 * vecy});
            } else {
                sum--;
            }
        }
        sort(segments[i].begin(), segments[i].end());
        int r = 0;
        for (int l = 0; l < segments[i].size(); l++){
            while (r < segments[i].size() && segments[i][l] == segments[i][r]){
                r++;
            }
            sum += r - l - 1;
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n - 1; j++){
    //         cout << segments[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << sum;
}



