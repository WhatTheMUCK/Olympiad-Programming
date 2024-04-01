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
    int n, w, h;
    long long height = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> w >> h;
        if (keyboard.find(w) == keyboard.end())
            keyboard[w] = h;
        else
            keyboard[w] < h ? keyboard[w] = h : h = h;
    }
    for (auto elem : keyboard)
        height += elem.second;
    cout << height;
}
