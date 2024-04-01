#include <iostream>

using namespace std;

int main()
{
    int a, b, n, m, minn, maxn, minm, maxm;
    cin >> a >> b >> n >> m;
    minn = (a + 1) * (n - 1) + 1;
    maxn = (a + 1) * n + a;
    minm = (b + 1) * (m - 1) + 1;
    maxm = (b + 1) * m + b;
    //cout << minn << " " << maxn << " " << minm << " " << maxm << "\n";
    if (minn > maxm || minm > maxn)
        cout << "-1";
    else
        cout << max(minn, minm) << " " << min(maxn, maxm);
}
