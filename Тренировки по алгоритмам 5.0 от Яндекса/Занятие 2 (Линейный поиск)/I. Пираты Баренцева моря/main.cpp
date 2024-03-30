#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
 
using namespace std;

struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};


int allAtColumn(int column, vector<pair<int,int>>& cordinates, vector<vector<int>> startfield){
    int steps = 0, target;
    vector<bool> used(startfield.size(), false);
    for (int i = 0; i < cordinates.size(); i++){
        steps += abs(cordinates[i].second - column);
        startfield[cordinates[i].first][cordinates[i].second] = 0;
        startfield[cordinates[i].first][column] = 1;
    }
    // cout << "yoffset: " << steps << "\n";
    // for (int i = 0; i < startfield.size(); i++){
    //     for (int j = 0; j < startfield[i].size(); j++){
    //         cout << startfield[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return steps;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    int answer = n * n;
    vector<pair<int,int>> cordinates(n);
    vector<int> lines, fullLines;
    vector<vector<int>> startfield(n, vector<int>(n, 0));
    unordered_map<int, int> pointsAtLine;
    for (int i = 0; i  < n; i++){
        pointsAtLine[i] = 0;
    }
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        cordinates[i].first = x - 1;
        cordinates[i].second = y - 1;
        startfield[x - 1][y - 1] = 1;
        pointsAtLine[x - 1]++;
    }
    for (int i = 0; i  < n; i++){
        if (pointsAtLine[i] == 0){
            lines.push_back(i);
        }
        if (pointsAtLine[i] > 1){
            fullLines.push_back(i);
        }
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << startfield[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "pointsAtLine:\n";
    // for (int i = 0; i < n; i++){
    //     cout << pointsAtLine[i] << "\n";
    // }
    // cout << "lines:\n";
    // for (int i = 0; i < lines.size(); i++){
    //     cout << lines[i] << "\n";
    // }
    int xoffset = 0, minoffset, target = -1, k = 0;
    for (int i = 0; i < fullLines.size(); i++){
        for (int j = 0; j < pointsAtLine[fullLines[i]] - 1; j++){
            xoffset += abs(fullLines[i] - lines[k]);
            pointsAtLine[lines[k]]++;
            k++;
        }
    }
    
    // cout << "xoffset: " << xoffset << "\n";
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << startfield[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int yoffset = n * n;
    for (int i = 0; i < n; i++){
        yoffset = min(yoffset, allAtColumn(i, cordinates, startfield));
    }
    answer = xoffset + yoffset;
    cout << answer;
}    
