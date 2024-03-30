#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, count3 = 0, count4 = 0, count5 = 0, countAll = 0;
    double percent;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        if (a == 3) count3++;
        if (a == 4) count4++;
        if (a == 5) count5++;
    }
    countAll = count3 + count4 + count5;
    percent = 100.0 * (count3 + count4)/countAll;
    if (count3 <= 1 && percent <= 25.0) 
        cout << "Red";
    else
        cout << "Blue";
}
