#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>

using namespace std;

bool checkCrackedTiles(int m, int h, vector<pair<int, int>>& crackedTiles, vector<int>& minYBefore, vector<int>& maxYBefore, vector<int>& minYAfter, vector<int>& maxYAfter) {
    int right = 0, maxY, minY;
    for (int left = 0; left < crackedTiles.size(); left++) {
        while (right < crackedTiles.size() && crackedTiles[right].first - crackedTiles[left].first < m) {
            right++;
        }
        right--;
        // cout << "ans?: " << m << " left: " << left << " right: " << right; 
        maxY = max(left - 1 >= 0 ? maxYBefore[left - 1] : -1, right <= crackedTiles.size() - 2 ? maxYAfter[right + 1] : -1);
        minY = min(left - 1 >= 0 ? minYBefore[left - 1] : h + 1, right <= crackedTiles.size() - 2 ? minYAfter[right + 1] : h + 1);
        // cout << " maxY: " << maxY << " minY: " << minY << "\n";

        if (minY == -1 || maxY - minY + 1 <= m) {
            //cout << "\n@@@\n";
            return true;
        }
    }
    return false;
}

int lBinarySearch(int l, int r, int h, function<bool(int, int, vector<pair<int, int>>&, vector<int>&, vector<int>&, vector<int>&, vector<int>&)> check, vector<pair<int, int>>& crackedTiles, vector<int>& minYBefore, vector<int>& maxYBefore, vector<int>& minYAfter, vector<int>& maxYAfter){
    int m;
    while (r - l > 0){
        m = (l + r) / 2;
        //cout << "\nl: " << l << " r: " << r << " m: " << m << "\n";
        if (check(m, h, crackedTiles, minYBefore, maxYBefore, minYAfter, maxYAfter)){
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w, h, n;
    cin >> w >> h >> n;
    vector<pair<int, int>> crackedTiles(n);
    for (int i = 0; i < n; i++){
        cin >> crackedTiles[i].first >> crackedTiles[i].second;
    }
    sort(crackedTiles.begin(), crackedTiles.end());
    vector<int> y(n);
    for (int i = 0; i < n; i++){
        y[i] = crackedTiles[i].second;
    }
    vector<int> minYBefore = y, maxYBefore = y, minYAfter = y, maxYAfter = y;
    for (int i = 1; i < n; ++i) {
        minYBefore[i] = min(minYBefore[i], minYBefore[i - 1]);
        maxYBefore[i] = max(maxYBefore[i], maxYBefore[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        minYAfter[i] = min(minYAfter[i], minYAfter[i + 1]);
        maxYAfter[i] = max(maxYAfter[i], maxYAfter[i + 1]);
    }
    // cout << "\ncrackedTiles:\n";
    // for (int i = 0; i < crackedTiles.size(); i++){
    //     cout << "crackedTiles[" << i << "]: " << crackedTiles[i].first << " " << crackedTiles[i].second << "\n";
    // }
    // cout << "\nminYBefore:\n";
    // for (int i = 0; i < n; i++){
    //     cout << "i:" << i << " " << minYBefore[i] << "\n";
    // }
    // cout << "\nmaxYBefore:\n";
    // for (int i = 0; i < n; i++){
    //     cout << "i:" << i << " " << maxYBefore[i] << "\n";
    // }
    // cout << "\nminYAfter:\n";
    // for (int i = 0; i < n; i++){
    //     cout << "i:" << i << " " << minYAfter[i] << "\n";
    // }
    // cout << "\nmaxYAfter:\n";
    // for (int i = 0; i < n; i++){
    //     cout << "i:" << i << " " << maxYAfter[i] << "\n";
    // }
    cout << lBinarySearch(1, min(w, h), h, checkCrackedTiles, crackedTiles, minYBefore, maxYBefore, minYAfter, maxYAfter);
    
}
