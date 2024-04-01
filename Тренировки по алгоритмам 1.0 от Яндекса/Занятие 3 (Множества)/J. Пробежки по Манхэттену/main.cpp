#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, d, n, x, y;
    cin >> t >> d >> n;
    vector<int> XminusY = {0 - t, 0 + t}, XplusY = {0 - t, 0 + t};
    for (int i = 0; i < n; i++){
        vector<int> XminusYtemp, XplusYtemp;
        cin >> x >> y;
        XminusY.push_back(x - y - d); XminusY.push_back(x - y + d);
        XplusY.push_back(x + y - d); XplusY.push_back(x + y + d); 
        sort(XminusY.begin(), XminusY.end());
        sort(XplusY.begin(), XplusY.end());
        XminusYtemp.push_back(XminusY[1]); XminusYtemp.push_back(XminusY[2]);
        XplusYtemp.push_back(XplusY[1]); XplusYtemp.push_back(XplusY[2]);
        if (i != n - 1){
            XminusY = {XminusYtemp[0] - t, XminusYtemp[1] + t};
            XplusY = {XplusYtemp[0] - t, XplusYtemp[1] + t};
        } else {
            XminusY = XminusYtemp;
            XplusY = XplusYtemp;
        }
    }
    int xmin, xmax, ymin, ymax;
    xmin = (XminusY[0] + XplusY[0]) / 2;
    xmax = (XminusY[1] + XplusY[1]) / 2;
    ymin = (XplusY[0] - XminusY[1]) / 2;
    ymax = (XplusY[1] - XminusY[0]) / 2;
    set<pair<int,int>> answer;
    for (int i = xmin; i <= xmax; i++)
        for (int j = ymin; j <= ymax; j++)
            if (i - j >= XminusY[0] && i - j <= XminusY[1] && i + j >= XplusY[0] && i + j <= XplusY[1])
                answer.insert({i,j});
    
    cout << answer.size();
    for (auto elem : answer)
        cout << "\n" << elem.first << " " << elem.second;
    //cout << "Ответ:\n" << XminusY[0] << " " << XminusY[1] << "\n" << XplusY[0] << " " << XplusY[1];
}
