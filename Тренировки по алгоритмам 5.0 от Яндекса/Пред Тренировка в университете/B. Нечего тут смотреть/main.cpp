#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
 
using namespace std;

int check(unordered_map<string,int>& mp,int x, int y){
    int ans = 0;
    if (mp.find(to_string(x)+" "+to_string(y))==mp.end()){
        return 1;
    }
    if (mp[to_string(x)+" "+to_string(y)]>0){
        return 0;
    }
    mp[to_string(x)+" "+to_string(y)]++;
    return check(mp,x+1,y)+check(mp,x-1,y)+check(mp,x,y+1)+check(mp,x,y-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    double percent;
    cin >> n;
    vector<pair<int, int>> graph;
    unordered_map<string,int> mp;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        string cord = to_string(x)+" "+to_string(y);
        mp[cord]=0;
    }
    cout << check(mp,x,y);
}
