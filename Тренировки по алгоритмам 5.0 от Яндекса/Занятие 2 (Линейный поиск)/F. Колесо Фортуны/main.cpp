#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, k, maxnumber;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    cin >> a >> b >> k;
    if (b <= k){
        maxnumber = numbers[0];
    } else {
        if (b - a > k * numbers.size()){
            maxnumber = numbers[0];
            for (int i = 1; i < n; i++){
                maxnumber = max(maxnumber, numbers[i]);
            }
        } else {
            // cout << (a - 1) / k << " " << (b - 1) / k << "\n";
            maxnumber = numbers[((a - 1) / k) % numbers.size()];
            // cout << maxnumber << "\n";
            for (int i = (a - 1) / k; i <= (b - 1) / k; i++){
                maxnumber = max(maxnumber, numbers[i % numbers.size()]);
            }
            // cout << maxnumber << "\n-:\n";
            for (int i =-((a - 1) / k); i >= -((b - 1) / k); i--){
                // cout << "i: " << i << "\n";
                // cout << "(n): " << n << "\n";
                // cout << "(n + i): " << n + i << "\n";
                maxnumber = max(maxnumber, numbers[(n + (i % n)) % n]);
                // cout << numbers[(numbers.size() + (i % numbers.size())) % numbers.size()] << " ";
            }
            // cout << "\nmax: " << maxnumber << "\n";
        }
    }
    cout << maxnumber;
}
