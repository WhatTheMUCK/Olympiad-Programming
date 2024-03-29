#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    int L, x1, v1, x2, v2, l, r, vl, vr;
    pair<int, int> lengthsToStartL, lengthsToStartR;
    cin >> L >> x1 >> v1 >> x2 >> v2;
    x1 %= L;
    x2 %= L;
    x1 = (x1 + L) % L;
    x2 = (x2 + L) % L;
    if (x1 >= x2){
        l = x1;
        r = x2;
        vl = v1;
        vr = v2;
    } else {
        l = x2;
        r = x1;
        vl = v2;
        vr = v1;
    }
    // lengthsToStartL  = {l, l - L};
    // lengthsToStartR = {r, r - L};
    double centerxIn, vIn, vInToL, centerxOut, vOut, vOutToR, t = 0;
    centerxIn = (double)(r + l) / 2;
    vIn = (double)(vl + vr) / 2;
    vInToL = (double)(vr - vl) / 2;
    centerxOut = (centerxIn >= (double)L / 2 ? centerxIn - (double)L / 2 : centerxIn + (double)L / 2);
    vOut = (double)(vl + vr) / 2;
    vOutToR = (double)(vl - vr) / 2;
    if (l == r || l == L - r){
        cout << "YES\n" << t;
        return 0;
    } else {
        if (vl == 0 && vr == 0){
            cout << "NO\n";
            return 0;
        } else {
            cout << "YES\n";
            if (centerxIn / vIn > 0){
                t = abs((centerxIn - L) / vIn);
            } else {
                t = abs(centerxIn / vIn);
            }
            if (centerxOut / vOut > 0){
                t = min(t, abs((centerxOut - L) / vOut));
            } else {
                t = min(t, abs(centerxOut / vOut));
            }
            if (vl != vr){
                if (vInToL > 0){
                    t = min(t, abs(l - centerxIn) / vInToL);
                } else {
                    if (centerxOut > (double)L / 2){
                        t = min(t, abs(r + L - centerxOut) / vOutToR);
                    } else {
                        t = min(t, abs(r  - centerxOut) / vOutToR);
                    }
                }
            }
        }
    }
    cout << t;
}
    
