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
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (int i = 0; i < n; i++){
    	cin >> l[i];
    }
    sort(l.rbegin(), l.rend());
    int left = 0, right = l[0], m = (left + right) / 2;
    long long temp;
    while (right - left > 1){
    	//cout << "l: " << left << " r: " << right << " m: " << m;
    	temp = 0;
    	for (int i = 0; i < n; i++){
    		temp += l[i]/m;
    	}
    	//cout << " temp: " << temp << "\n";
    	if (temp < k){
    		right = m;
    	} else {
    		left = m;
    	}
    	m = (left + right)/2;
    }
    temp = 0;
    for (int i = 0; i < n; i++){
    	temp += l[i]/right;
    }
    if (temp >= k){
    	m = right;
    }
    cout << m;
}
