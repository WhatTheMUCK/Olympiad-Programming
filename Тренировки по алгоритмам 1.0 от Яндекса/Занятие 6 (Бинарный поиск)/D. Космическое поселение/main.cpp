#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    tie(a, b) = make_tuple(min(a,b), max(a,b));
    tie(w, h) = make_tuple(min(w,h), max(w,h));
    long long l = 0, r = (long long)1e18, m = (l + r)/2, thickness, length, checker;
    int temp1, temp2, helper;
    while (r - l > 1){
        thickness = a + 2 * m;
        length = b + 2 * m;
        checker = max((w/thickness) * (h/length), (w/length) * (h/thickness));
        // temp1 = (w/(a + 2 * m)); 
        // temp2 = (h/(b + 2 * m));
        // helper = temp1 * temp2;
    	if (checker >= n){
    		l = m;
    	} else {
    		r = m;
    	}
    	m = (l + r)/2;
    }
    if (r > m && (max((w/(a + 2 * r)) * (h/(b + 2 * r)), (w/(b + 2 * r)) * (h/(a + 2 * r)))  >= n)){
    	m = r;
    }
    if (max((w/(a + 2 * m)) * (h/(b + 2 * m)), (w/(b + 2 * m)) * (h/(a + 2 * m))) < n){
    	m = l;
    }
    cout << m;
}
