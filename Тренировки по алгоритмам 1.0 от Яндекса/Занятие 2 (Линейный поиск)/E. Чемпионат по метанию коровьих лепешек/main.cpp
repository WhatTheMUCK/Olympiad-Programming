#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, first = -1, second = -1, third = -1, firstPos = -1, secondPos = -1, thirdPos = -1, Vasilyi = -1;
    cin >> n;
    vector<int> vec(n), support(n);
    for (int i = 0; i < n; i++){
        cin >> vec[i];
        support[i] = vec[i];   
    }
    sort(support.rbegin(), support.rend());
    bool answer = false, flagFirst = (vec[0] == support[0] ? true : false);
    for (int i = 1; i < n - 1; i++){
        if (vec[i] % 10 == 5 && flagFirst && vec[i] > vec[i + 1] && vec[i] > Vasilyi)
            Vasilyi = vec[i];
        flagFirst = (vec[i] == support[0] ? true : flagFirst);
    }
    int amount = 1;
    for (int i = 0; i < n; i++){
        if (vec[i] > Vasilyi)
            amount++;
        if (vec[i] == Vasilyi){
            answer = true;
        }
    }
    cout << (answer ? amount : 0);
}    
