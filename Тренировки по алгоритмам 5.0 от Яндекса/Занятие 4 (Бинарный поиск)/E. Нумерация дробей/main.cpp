#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    long long l = 1, r = (long long)1e10, m;
    while (r - l > 0){
        m = (l + r) / 2;
        if ((m + 1) * m / 2 < n){
            l = m + 1;
        } else {
            r = m;
        }
    }
    long long diag = l, sumNumeratorWithDenominator = diag + 1, numerator, denumerator, amountNumbersBeforeDiag = (l - 1) * ((l - 1) + 1) / 2;
    //cout << diag << "\n";
    if (diag % 2)
        numerator = n - amountNumbersBeforeDiag;
    if (!(diag % 2))
        numerator = diag - (n - amountNumbersBeforeDiag) + 1;
    denumerator = sumNumeratorWithDenominator - numerator;
    cout << numerator << "/" << denumerator;
}
