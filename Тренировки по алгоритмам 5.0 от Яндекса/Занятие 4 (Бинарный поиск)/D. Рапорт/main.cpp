#include <iostream>
#include <vector>
#include <functional>
#include <tuple>

using namespace std;

pair<int, int> simulation(vector<int>& a, vector<int>& b, int m, int w){
    int ha = 1, hb = 1, linea = m, lineb = w - m;
    for (int i = 0; i < a.size(); i++){
        if (linea == m){
            linea -= a[i];
        } else {
            if (linea >= a[i] + 1)
                linea -= a[i] + 1;
            else{
                linea = m - a[i];
                ha++;
            }
        }
    }
    for (int i = 0; i < b.size(); i++){
        if (lineb == w - m){
            lineb -= b[i];
        } else {
            if (lineb >= b[i] + 1)
                lineb -= b[i] + 1;
            else{
                lineb = w - m - b[i];
                hb++;
            }
        }
    }
    return {ha, hb};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int w, n, m;
    cin >> w >> n >> m;
    vector<int> a(n), b(m);
    int l = 0, r = w, medium, h = max(n,m), ha, hb;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        l = max(l, a[i]);
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
        r = min(r, w - b[i]);
    }
    //cout << "l: " << l << " r: " << r << "\n";
    while (r - l > 0){
        medium = (l + r) / 2;
        tie(ha, hb) = simulation(a, b, medium, w);
        //cout << "1)l: " << l << " r: " << r << " m: " << medium << " h: " << h << " simulation: " << ha << " " << hb << "\n";
        if (max(ha, hb) < h){
            h = max(ha, hb);
        }
        if (ha == max(ha, hb)){
            l = medium + 1;
        } else {
            r = medium;
        }
        //cout << "2)l: " << l << " r: " << r << " m: " << medium << " h: " << h << " simulation: " << ha << " " << hb << "\n";
    }
    tie(ha, hb) = simulation(a, b, l, w);
    h = min(h, max(ha, hb));
    cout << h;
}
