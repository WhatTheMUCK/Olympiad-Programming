#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, r, c, tempr;
    cin >> n >> r >> c;
    vector<int> heights(n, 0);
    for (int i = 0; i < n; i++){
    	cin >> heights[i];
    }
    sort(heights.begin(), heights.end());
    long long left = 0, right = (long long)1e10, m = (left + right)/2;
    while (right - left > 0){
    	tempr = 0;
    	for (int i = 0; i < n - c + 1; ){
    		if (heights[i + c - 1] - heights[i] <= m){
    			tempr++;
    			i += c;
    		} else {
    			i++;
    		}
    	}
    	if (tempr >= r){
    		right = m;
    	} else {
    		left = m + 1;
    	}
    	m = (left + right)/2;
    }
    cout << m;
}
