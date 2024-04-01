#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double f1, f2, l = 30.0, r = 4000.0;
    string info;
    cin >> n;
    cin >> f1;
    for (int i = 0; i < n - 1; i++){
        cin >> f2 >> info;
        if (f2 <= f1 && info == "closer")
            r > (f1 + f2) / 2 ? r = (f1 + f2) / 2 : r = r; 
        else if (f2 <= f1 && info == "further")
            l < (f1 + f2) / 2 ? l = (f1 + f2) / 2 : l = l;
        else if (f2 >= f1 && info == "closer")
            l < (f1 + f2) / 2 ? l = (f1 + f2) / 2 : l = l;
        else if (f2 >= f1 && info == "further")
            r > (f1 + f2) / 2 ? r = (f1 + f2) / 2 : r = r; 
        f1 = f2;
    }
    cout.precision(7);
    cout << l << " " << r;
    
}    
