#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Предикат, который мы хотим использовать
bool checkForLBS(int m, int value) {
    return m >= value;
}

bool checkForRBS(int m, int value) {
    return m <= value;
}

int lBinarySearch(int l, int r, function<bool(int, int)> check, vector<int>& vec, int target){
    int m;
    while (r - l > 0){
        m = (l + r) / 2;
        if (check(vec[m], target)){
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int rBinarySearch(int l, int r, function<bool(int, int)> check, vector<int>& vec, int target){
    int m;
    while (r - l > 0){
       m = (l + r + 1) / 2;
       if (check(vec[m], target)){
           l = m;
       } else {
           r = m - 1;
       }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, targetl, targetr, l, r;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++){
        cin >> vec[i]; 
    }
    cin >> k;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < k; i++){
        cin >> targetl >> targetr;
        l = lBinarySearch(0, vec.size() - 1, checkForLBS, vec, targetl);
        r = rBinarySearch(0, vec.size() - 1, checkForRBS, vec, targetr);
        if (vec[l] <= targetr && vec[r] >= targetl)
            cout << r - l + 1 << " ";
        else 
            cout << "0 ";
    }
}
