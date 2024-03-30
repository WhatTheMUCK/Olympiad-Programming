#include <iostream>
#include <vector>
#include <functional>
#include <fstream>

using namespace std;

bool checkEq(int m, int groups, long long amount, vector<long long>& pref){
    //cout << " m - groups: " << m - groups << " pref[m] - pref[m - groups]:" << pref[m] - pref[m - groups] << "\n";
    if (m - groups >= 0)
        return (pref[m] - pref[m - groups] <= amount);
    else
        return true;
}

int rBinarySearch(int l, int r, function<bool(int, int, long long, vector<long long>&)> check, vector<long long>& pref, int groups, long long amount){
    int m;
    while (r - l > 0){
       m = (l + r + 1) / 2;
       //cout << "l: " << l << " r: " << r << " m: " << m;
       if (check(m, groups, amount, pref)){
           l = m;
       } else {
           r = m - 1;
       }
    }
    return l;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int n, m, groups, pos;
    long long amount;
    cin >> n >> m;
    vector<int> orcs(n);
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++){
        cin >> orcs[i];
    }
    pref[0] = 0;
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + orcs[i - 1];
        //cout << "pref[" << i << "]: " << pref[i] << "\n";
    }
    //vector<int> answer;
    for (int i = 0; i < m; i++){
        cin >> groups >> amount;
        if (groups > n){
            cout << "-1\n";
            } else {
                pos = rBinarySearch(0, pref.size() - 1, checkEq, pref, groups, amount);
            if (pref[pos] - pref[pos - groups] != amount){
                cout << "-1\n";
            } else {
                cout << pos - (groups - 1) << "\n";
            }
        }
    }
}

/*
5 1
1 3 5 7 9
6 9

*/
