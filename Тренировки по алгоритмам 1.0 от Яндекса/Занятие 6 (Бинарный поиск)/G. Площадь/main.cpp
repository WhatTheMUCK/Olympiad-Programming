#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    long long t;
    cin >> n >> m >> t;
    long long l = 0, r = (long long)1e18, average = (l + r)/2, square;
    while (r - l > 1){
        //cout << "aSquare: " << (n - 2 * average) << " bSquare: " << (m - 2 * average) << "\n";
        if ((n - 2 * average) > 0 && (m - 2 * average) > 0){
            square = (n - 2 * average) * (m - 2 * average);
            //cout << "n*m - square: " << 1ll * n * m - square << "\nl:" << l << " r: " << r << " average: " << average << "\n";
            if (1ll * n * m - square <= t){
                l = average;
            } else {
                r = average;
            }
        } else {
            r = average;
        }
        average = (l + r) / 2;
    }
    //cout << "l:" << l << " r: " << r << " average: " << average << "\n";
    square = (n - 2 * r) * (m - 2 * r);
    //cout << "square: " << square << "\n";
    if (1ll * n * m - square <= t && (n - 2 * r) > 0 && (m - 2 * r) > 0){
    	average = r;
    }
    cout << average;
}

//5 20 46
//1000000000 1000000000 1000000000000000000
