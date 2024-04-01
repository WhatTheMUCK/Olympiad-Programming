#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long w, h, n;
    cin >> w >> h >> n;
    long long l = 0, r = (long long)1e18, m = (l + r)/2;
    while (r - l > 1){
    	//cout << "l: " << l << " r: " << r << " m: " << m << " (m/w): " << (m/w) << " (m/h)" << (m/h) << " (m/w) * (m/h)" << (m/w) * (m/h) << " n: " << n << "\n";
    	if ((m/w) >= n && (m/w) * m >= (m/h) * m || (m/h) >= n && (m/h) * m >= (m/w) * m || (m/w) * (m/h) >= n){
    		r = m;
    	} else {
    		l = m;
    	}
    	m = (l + r)/2;
    }
    if (l < m && ((l/w) * (l/h) >= n)){
    	m = l;
    }
    if ((m/w) * (m/h) < n){
    	m = r;
    }
    cout << m;
}
