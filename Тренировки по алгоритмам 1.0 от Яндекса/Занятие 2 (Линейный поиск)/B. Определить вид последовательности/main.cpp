#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, preva;
    cin >> a;
    preva = a;
    bool constant = true, ascending = true, weakly_ascending = true, descending = true, weakly_descending = true;
    while (1){
        cin >> a;
        if (a == -2000000000)
            break;
        if (a != preva)
            constant = false;
        if (a <= preva)
            ascending = false;
        if (a < preva)
            weakly_ascending = false;
        if (a >= preva)
            descending = false;
        if (a > preva)
            weakly_descending = false;
        preva = a;
    }
    if (constant)
        cout << "CONSTANT";
    else if (ascending)
        cout << "ASCENDING";
    else if (weakly_ascending)
        cout << "WEAKLY ASCENDING";
    else if (descending)
        cout << "DESCENDING";
    else if (weakly_descending)
        cout << "WEAKLY DESCENDING";
    else
        cout << "RANDOM";
}
