#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

typedef struct{
    int x, y;
}point;

typedef struct {
    point start, end;
}edge;

bool operator== (const edge& l, const edge& r){
    return (l.start.x == r.start.x) && (l.start.y == r.start.y) && (l.end.x == r.end.x) && (l.end.y == r.end.y);
}

namespace std{
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second) * 63;
        }
    };
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n, x1, y1, x2, y2;
    cin >> n;
    vector<edge> Aedge(n), Bedge(n);
    unordered_map<pair<int, int>, int> offsets;
    for (int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 < x2 || (x1 == x2 && y1 < y2)){
            Aedge[i].start.x = x1;
            Aedge[i].start.y = y1;
            Aedge[i].end.x = x2 - x1;
            Aedge[i].end.y = y2 - y1;
        } else{
            Aedge[i].start.x = x2;
            Aedge[i].start.y = y2;
            Aedge[i].end.x = x1 - x2;
            Aedge[i].end.y = y1 - y2;
        }
    }
    for (int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2; 
        if (x1 < x2 || (x1 == x2 && y1 < y2)){
            Bedge[i].start.x = x1;
            Bedge[i].start.y = y1;
            Bedge[i].end.x = x2 - x1;
            Bedge[i].end.y = y2 - y1;
        } else{
            Bedge[i].start.x = x2;
            Bedge[i].start.y = y2;
            Bedge[i].end.x = x1 - x2;
            Bedge[i].end.y = y1 - y2;
        }
    }
    int offsetx, offsety, maxeq = 0;
    for (edge& elemB : Bedge){
        for (edge& elemA : Aedge){
                if ((elemA.end.x  == elemB.end.x) && (elemA.end.y == elemB.end.y)){
                    offsetx = elemA.start.x - elemB.start.x;
                    offsety = elemA.start.y - elemB.start.y;
                    if (offsets.find({offsetx, offsety}) == offsets.end()){
                	    offsets[{offsetx, offsety}] = 0;
                    }
                	offsets[{offsetx, offsety}]++;
                	maxeq = max(maxeq, offsets[{offsetx, offsety}]);
                }
        }
    }
    cout << n - maxeq;
    return 0;
}


/*
5
0 0 1 2
1 0 0 2
2 0 2 2
4 0 3 2
4 0 5 2
9 -1 10 1
10 1 9 3
8 1 10 1
8 1 9 -1
8 1 9 3
*/
