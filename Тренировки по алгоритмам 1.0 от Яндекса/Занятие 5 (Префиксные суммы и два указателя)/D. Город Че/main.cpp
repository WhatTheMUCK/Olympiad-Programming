#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r, posR = 0;
    long long count = 0;
    cin >> n >> r;
    vector<int> monuments(n);
    for (int i = 0; i < n; i++)
        cin >> monuments[i];
    vector<int>::iterator iterL = monuments.begin(), iterR = monuments.begin();
    while (iterL != monuments.end() && iterR != monuments.end()){
        if (*iterR - *iterL <= r){
            iterR++;
            posR++;
        } else{
            count += n - posR;
            iterL++;
        }
    }
    cout << count;
}
