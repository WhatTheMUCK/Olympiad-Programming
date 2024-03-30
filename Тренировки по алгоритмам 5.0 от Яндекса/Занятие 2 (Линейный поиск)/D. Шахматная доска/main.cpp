#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int perimeter(int x, int y, vector<vector<int>>& chessboard){
    if (chessboard[x][y] == 0)
        return 1;
    if (chessboard[x][y] == 2)
        return 0;
    chessboard[x][y] = 2;
    return (perimeter(x, y + 1, chessboard) + perimeter(x, y - 1, chessboard) + perimeter(x + 1, y, chessboard) + perimeter(x - 1, y, chessboard));
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, x, y, answer;
    cin >> n;
    vector<vector<int>> chessboard(10, vector<int>(10, 0));
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        chessboard[x][y] = 1;
    }
    // for (int i = 0; i < 10; i++){
    //     for (int j = 0; j < 10; j++){
    //         cout << chessboard[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << x << " " <<  y << "\n";
    //cout << perimeter(3, 1, chessboard) << "\n";
    answer = perimeter(x, y, chessboard);
    cout << answer;
}    
