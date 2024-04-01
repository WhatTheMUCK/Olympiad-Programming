#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long double a, b, c, d, e, f, x, y;
    cin >> a >> b >> c >> d >> e >> f;
    cout.precision(10);
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
        cout << 5;
    else if (a == 0 && c == 0 && e * d == f * b && (e * d != 0 || e == 0 && f == 0))
        cout << 4 << " " << e / b;
    else if (b == 0 && d == 0 && e * c == f * a && (e * c != 0 || e == 0 && f == 0))
        cout << 3 << " " << e / a;
    else if (a == 0 && b == 0 && e == 0 && c != 0 && d != 0)
        cout << 1 << " " << -1 * c / d << " " << f / d;
    else if (c == 0 && d == 0 && f == 0 && a != 0 && b != 0)
        cout << 1 << " " << -1 * a / b << " " << e / b;
    else if (a * f == c * e && a * d == b * c && b * f == e * d && a * f != 0)
        cout << 1 << " " << -1 * a / b << " " << e / b;
    else if (a * d == b * c && e == 0 && f == 0 && a * d != 0)
        cout << 1 << " " << -1 * a / b << " " << e / b;
    else if (a != 0 && d * a != b * c){
        y = (f - e * c / a) / (d - b * c / a);
        x = e / a - b / a * y;
        cout << 2 << " " << x << " " << y;
    }
    else if (c != 0 && b * c != a * d){
        y = (e - f * a / c) / (b - d * a / c);
        x = f / c - d / c * y;
        cout << 2 << " " << x << " " << y;
    }
    else if (a == 0 && b == 0 && e == 0 && c == 0 && d != 0)
        cout << 4 << " " << f / d;
    else if (a == 0 && c == 0 && d == 0 && f == 0 && b != 0)
        cout << 4 << " " << e / b;
    else if (a == 0 && b == 0 && e == 0 && d == 0 && c != 0)
        cout << 3 << " " << f / c;
    else if (b == 0 && c == 0 && d == 0 && f == 0 && a != 0)
        cout << 3 << " " << e / a;
    else
        cout << 0;
}

