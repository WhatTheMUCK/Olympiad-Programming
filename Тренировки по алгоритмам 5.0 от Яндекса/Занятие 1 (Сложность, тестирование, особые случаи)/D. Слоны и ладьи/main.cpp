#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

void bishop(vector<vector<int>>& chessboard, int x, int y){
    for (int i = 1; x + i < 8 && y + i < 8 && chessboard[x + i][y + i] < 2; i++)
        chessboard[x + i][y + i] = 1;
    for (int i = 1; x + i < 8 && y - i >= 0 && chessboard[x + i][y - i] < 2; i++)
        chessboard[x + i][y - i] = 1;
    for (int i = 1; x - i >= 0 && y - i >= 0 && chessboard[x - i][y - i] < 2; i++)
        chessboard[x - i][y - i] = 1;
    for (int i = 1; x - i >= 0 && y + i < 8 && chessboard[x - i][y + i] < 2; i++)
        chessboard[x - i][y + i] = 1;
}
void rook(vector<vector<int>>& chessboard, int x, int y){
    for (int i = 1; x + i < 8 && chessboard[x + i][y] < 2; i++)
        chessboard[x + i][y] = 1;
    for (int i = 1; x - i >= 0 && chessboard[x - i][y] < 2; i++)
        chessboard[x - i][y] = 1;
    for (int i = 1; y + i < 8 && chessboard[x][y + i] < 2; i++)
        chessboard[x][y + i] = 1;
    for (int i = 1; y - i >= 0 && chessboard[x][y - i] < 2; i++)
        chessboard[x][y - i] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> chessboard(8, vector<int>(8,0));
    string line;
    for (int i = 0; i < 8; i++){
        cin >> line;
        for (int j = 0; j < 8; j++){
            if (line[j] == 'R')
                chessboard[i][j] = 2;
            if (line[j] == 'B')
                chessboard[i][j] = 3;
        }
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (chessboard[i][j] == 2)
                rook(chessboard, i, j);
            if (chessboard[i][j] == 3)
                bishop(chessboard, i, j);
        }
    }
    
    int count0 = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            //cout << chessboard[i][j] << " ";
            if (!chessboard[i][j])
                count0++;
        }
        //cout << "\n";
    }
    cout << count0;
}
/*
********
*RB*****
********
********
********
********
********
********
*/
