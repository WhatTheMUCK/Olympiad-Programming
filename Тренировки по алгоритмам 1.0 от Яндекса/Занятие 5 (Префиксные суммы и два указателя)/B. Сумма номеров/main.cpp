#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int minimum, Tshirt, pants;
} help;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, count = 0;
    cin >> n >> k;
    vector<int> cars(n + 1);
    cars[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a;
        cars[i] = cars[i - 1] + a;
    }
    vector<int>::iterator iterL = cars.begin(), iterR = cars.begin();
    while (iterL != cars.end() && iterR != cars.end()){
        if (*iterR - *iterL == k){
            count++;
            iterR++;
        } else if (*iterR - *iterL > k){
            iterL++;
        } else if (*iterR - *iterL < k){
            iterR++;
        }
    }
    cout << count;
}
