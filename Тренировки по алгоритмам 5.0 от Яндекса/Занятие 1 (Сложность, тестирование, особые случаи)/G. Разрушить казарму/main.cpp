#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int model(int x, int y, int p){
    int count = 0;
    p -= x - y;
    x -= p;
    count++;
    while (p > 0 && x > 0){
        p -= x;
        x -= p;
        count++;
    }
    if (x > 0)
        return count;
    else
        return 500000000;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, p, rounds = 0;
    cin >> x >> y >> p;
    y -= x;
    rounds++;
    if (y <= 0){
        cout << rounds;
    } else {
        if (x - p > 0){
            while (y > x){
                y -= (x - p);
                rounds++;
            }
            int count = 0, tempcount = 500000000;
            // теперь y <= x
            while (y > 0){
                tempcount = min(model(x, y, p) + count, tempcount);
                y -= (x - p);
                count++;
            }
            while (p > 0 && x > 0){
                x -= p;
                p -= x;
                count++;
            }
            rounds += min(tempcount, count);
            
        } else if (y < x){
            p -= x  - y;
            y = 0;
            rounds++;
            while (p > 0 && x > 0){
                x -= p;
                p -= x;
                rounds++;
            }
            if (x <= 0){
                cout << "-1";
                return 0;
            }
        } else {
            cout << "-1";
            return 0;
        }
        cout << rounds;
    }
}
/*
250
500
187
Ответ: 4

250
500
125
Ответ: 3

250
500
230
Ответ: 8

250
500
208
Ответ: 5
*/
