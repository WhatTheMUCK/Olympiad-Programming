#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int countMines(vector<vector<int>> sapper, int i, int j){
    int count = 0;
    if (i == 0 & j == 0){
        if (sapper[i + 1][j] == -1) count++;
        if (sapper[i + 1][j + 1] == -1) count++;
        if (sapper[i][j + 1] == -1) count++;
    } else if (i == 0 && j < sapper[i].size() - 1){
        if (sapper[i + 1][j] == -1) count++;
        if (sapper[i + 1][j + 1] == -1) count++;
        if (sapper[i + 1][j - 1] == -1) count++;
        if (sapper[i][j + 1] == -1) count++;
        if (sapper[i][j - 1] == -1) count++;
    } else if (i == 0 && j == sapper[i].size() - 1){
        if (sapper[i + 1][j] == -1) count++;
        if (sapper[i + 1][j - 1] == -1) count++;
        if (sapper[i][j - 1] == -1) count++;
    } else if (i < sapper.size() - 1 && j == 0){
        if (sapper[i + 1][j] == -1) count++;
        if (sapper[i + 1][j + 1] == -1) count++;
        if (sapper[i][j + 1] == -1) count++;
        if (sapper[i - 1][j] == -1) count++;
        if (sapper[i - 1][j + 1] == -1) count++;
    } else if (i == sapper.size() - 1 && j == 0){
        if (sapper[i][j + 1] == -1) count++;
        if (sapper[i - 1][j] == -1) count++;
        if (sapper[i - 1][j + 1] == -1) count++;
    } else if (i < sapper.size() - 1 && j == sapper[i].size() - 1){
        if (sapper[i + 1][j] == -1) count++;
        if (sapper[i + 1][j - 1] == -1) count++;
        if (sapper[i][j - 1] == -1) count++;
        if (sapper[i - 1][j] == -1) count++;
        if (sapper[i - 1][j - 1] == -1) count++;
    } else if (i == sapper.size() - 1 && j == sapper[i].size() - 1){
        if (sapper[i][j - 1] == -1) count++;
        if (sapper[i - 1][j] == -1) count++;
        if (sapper[i - 1][j - 1] == -1) count++;
    } else if (i == sapper.size() - 1 && j < sapper[i].size() - 1){
        if (sapper[i][j - 1] == -1) count++;
        if (sapper[i - 1][j] == -1) count++;
        if (sapper[i - 1][j - 1] == -1) count++;
        if (sapper[i - 1][j + 1] == -1) count++;
        if (sapper[i][j + 1] == -1) count++;
    } else {
        if (sapper[i][j - 1] == -1) count++;
        if (sapper[i - 1][j - 1] == -1) count++;
        if (sapper[i - 1][j] == -1) count++;
        if (sapper[i - 1][j + 1] == -1) count++;
        if (sapper[i][j + 1] == -1) count++;
        if (sapper[i + 1][j + 1] == -1) count++;
        if (sapper[i + 1][j] == -1) count++;
        if (sapper[i + 1][j - 1] == -1) count++;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, p, q;
    cin >> n >> m >> k;
    vector<vector<int>> sapper(n, vector<int> (m, 0));
    for (int i = 0; i < k; i++){
        cin >> p >> q;
        p--; q--;
        sapper[p][q] = -1; 
    }
    
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << (sapper[i][j] == -1 ? "*" : to_string(sapper[i][j])) << " ";
    //     }
    //     cout << "\n";
    // }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (sapper[i][j] != -1)
                sapper[i][j] = countMines(sapper, i, j);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << (sapper[i][j] == -1 ? "*" : to_string(sapper[i][j])) << " ";
        }
        cout << "\n";
    }
    
}    
