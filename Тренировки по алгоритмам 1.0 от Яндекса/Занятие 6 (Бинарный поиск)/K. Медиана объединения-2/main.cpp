#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binsearch(vector<int>& search, int target){
    int l = 0, r = search.size() - 1, m;
    while (r - l > 0){
        m = (l + r) / 2;
        if (search[m] >= target){
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int cntless(vector<int>& search, int target){
    int ans = binsearch(search, target);
    if (search[ans] < target){
        return search.size();
    } 
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, l, x, d, a, c, m;
    cin >> n >> l;
    vector<vector<int>> vecs(n, vector<int>(l, 0));
    for (int i = 0; i < n; i++){
        cin >> x >> d >> a >> c >> m;
        vecs[i][0] = x;
        for (int j = 1; j < l; j++){
            x += d;
            d = (a * d + c) % m;
            vecs[i][j] = x;
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < l; j++){
    //         cout << vecs[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            long long left = min(vecs[i][0], vecs[j][0]), right = max(vecs[i][l - 1], vecs[j][l - 1]), medium, before, after;
            while (right - left > 0){
                medium = (left + right) / 2;
                before = 0;
                after = 0;
                before += cntless(vecs[i], medium);
                before += cntless(vecs[j], medium);
                after += l - cntless(vecs[i], medium + 1);
                after += l - cntless(vecs[j], medium + 1);
                if(before <= l - 1 && after <= l){
                    left = medium;
                    break;
                } 
                if (before > l - 1){
                    right = medium - 1; 
                } 
                if (after > l){
                    left = medium + 1;
                }
            }
            cout << left << "\n";
        }
    }
}
