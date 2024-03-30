#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, sum = 0, maxl = -1, answer;
    cin >> n;
    vector<int> lengths(n);
    while (cin >> l){
        sum += l;
        if (maxl < l)
            maxl = l;
    }
    answer = 2 * maxl - sum;
    if (answer <= 0)
        answer = sum;
    cout << answer;
    
}    
