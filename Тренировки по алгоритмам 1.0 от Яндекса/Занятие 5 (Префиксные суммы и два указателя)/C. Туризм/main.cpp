#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, lift, x, y, prevy = -1, start, end;
    cin >> n;
    vector<pair<int, int>> points(n);
    points[0] = {0,0};
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (prevy != -1){
            if (y - prevy > 0)  points[i].first += y - prevy;
            else points[i].second += + prevy - y;
            points[i].first += points[i - 1].first;
            points[i].second += points[i - 1].second;
        }
        prevy = y;
    }
    // for (int i = 0; i < n; i++){
    //     cout << i << ": " << points[i].first << "   " << points[i].second << "\n";
    // }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> start >> end;
        cout << (start <= end ? points[end - 1].first - points[start - 1].first : points[start - 1].second - points[end - 1].second) << "\n";
    }
}
