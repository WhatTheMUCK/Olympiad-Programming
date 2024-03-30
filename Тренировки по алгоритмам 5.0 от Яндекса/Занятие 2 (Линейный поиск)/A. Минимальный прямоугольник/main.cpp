#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, xlmin = 2000000000, ylmin =  2000000000, xrmax = -2000000000, yrmax = -2000000000, x, y;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> x >> y;
        if (x < xlmin)
            xlmin = x;
        if (x > xrmax)
            xrmax = x;
        if (y < ylmin)
            ylmin = y;
        if (y > yrmax)
            yrmax = y;
    }
    cout << xlmin << " " << ylmin << " " << xrmax << " " << yrmax << "\n";
    
}    
