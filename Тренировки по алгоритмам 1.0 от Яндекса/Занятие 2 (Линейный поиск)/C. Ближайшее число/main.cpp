#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, difference, differencePrev;
    cin >> n;
    vector <int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    cin >> x;
    if (n == 1){
        cout << vec[0];
    } else {
        int i = 1;
        differencePrev = abs(x - vec[0]);
        difference = abs(x - vec[1]);
        while (difference <= differencePrev && difference != 0 && i != vec.size() - 1){
            differencePrev = abs(x - vec[i++]);
            difference = abs(x - vec[i]);
        }
        if (difference <= differencePrev)
            cout << vec[i];
        else 
            cout << vec[i - 1];
    }
        
}
