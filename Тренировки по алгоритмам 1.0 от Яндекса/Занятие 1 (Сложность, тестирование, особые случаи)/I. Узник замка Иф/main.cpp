#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d, e, x, y;
    cin >> a >> b >> c >> d >> e;
    vector <pair<int, int>> vec = {{a, 1}, {b, 2}, {c, 3}, {d, 4}, {e, 5}};
    sort(vec.begin(), vec.end());
    for (int i = 0; i < 5; i++){
        if (vec[i].second == 4)
            x = i;
        if (vec[i].second == 5)
            y = i;
    }
    cout << ((x + y <= 4 ^ (x + y == 4 && (x == 1 || y == 1))) ? "NO" : "YES");
}
