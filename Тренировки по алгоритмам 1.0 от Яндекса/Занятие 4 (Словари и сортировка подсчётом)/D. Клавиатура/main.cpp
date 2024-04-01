#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<int, int> keyboard;
    int n, input, k;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        keyboard[i] = input;
    }
    cin >>  k;
    for (int i = 0; i < k; i++){
        cin >> input;
        input--;
        keyboard[input]--;
    }
    for (int i = 0; i < n; i++)
        cout << (keyboard[i] < 0 ? "YES\n" : "NO\n");
}
