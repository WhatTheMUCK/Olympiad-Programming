#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k1, m, k2, p2, n2, p1 = -2, n1 = -2, p1temp, n1temp, p2temp, n2temp, people;
    cin >> k1 >> m >> k2 >> p2 >> n2;
    for (int peopleLevel = 1; peopleLevel <= 1000000; peopleLevel++){
        people = m * peopleLevel;
        p2temp = (k2 - 1) / people + 1;
        n2temp = (((k2 - 1) % people + 1) - 1) / peopleLevel + 1;
        p1temp = (k1 - 1) / people + 1;
        n1temp = (((k1 - 1) % people + 1) - 1) / peopleLevel + 1;
        if (p2temp == p2 && n2temp == n2){
            if (p1 == -2 && n1 == -2){
                p1 = p1temp;
                n1 = n1temp;
            }
            if (p1 != p1temp)
                p1 = 0;
            if (n1 != n1temp)
                n1 = 0;
        }
    }
    if (p1 == -2 && n1 == -2){
        p1 = -1;
        n1 = -1;
    }
    cout << p1 << " " << n1;
}
