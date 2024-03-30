#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n, m, count = 0, countstart;
    char input;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> input;
            if (input == '#'){
                matrix[i][j] = 1;
                count++;
            }
        }
    }
    countstart = count;
    // cout << "countstart: " << countstart << "\n";
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    bool left = false, right = false;
    int l = -1, r = -1, i = 0, startline;
    while(i < n && (!left || !right)){
        for (int j = 0; j < m; j++){
            if (!left && matrix[i][j] == 1){
                l = j;
                left = true;
                startline = i;
            }
            if (!right && left && matrix[i][j] == 0){
                r = j - 1;
                right = true;
                count -= r - l + 1;
            }
            if (left && !right){
                matrix[i][j] = 2;
            }
        }
        if (!right && left){
            r = m - 1;
            right = true;
            count -= r - l + 1;
        }
        i++;
    }
    //cout << "l: " << l << " r: " << r << " count: " << count << "\n";
    
    int tempcount, rows = 1, columns = r - l + 1;
    bool end = false;
    for (int k = i; k < n && !end; k++){
        tempcount = 0;
        for (int ind = l; ind <= r; ind++){
            tempcount += (matrix[k][ind] > 0);
        }
        if (tempcount < r - l + 1){
            end = true;
        } else {
            rows++;
            for (int ind = l; ind <= r; ind++){
                matrix[k][ind] = 2;
            }
            count -= r - l + 1;
        }
    }
    //cout << "countstart: " << countstart << "\n";
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    //cout << "count: " << count << "\n";
    if (countstart <= 1){
        cout << "NO\n";
    } else {
        if (count == 0){
            cout << "YES\n";
            if (rows == 1){
                matrix[startline][r - l] = 3;
            } else {
                for (int ind = l; ind <= r; ind++){
                    matrix[startline][ind] = 3;
                }
            }
            //cout << "startline: " << startline << " r - l: " << r - l << " rows: " << rows << "\n"; 
            for (int k = 0; k < n; k++){
                for (int j = 0; j < m; j++){
                    if (matrix[k][j] == 0)
                        cout << ".";
                    if (matrix[k][j] == 2)
                        cout << "a";
                    if (matrix[k][j] == 3)
                        cout << "b";
                }
                cout << "\n";
            }
        } else {
            //cout << "МОЖЕТ БЫТЬ";
            
            left = false; right = false;
            l = -1; r = -1; i = 0;
            while(i < n && (!left || !right)){
                for (int j = 0; j < m; j++){
                    if (!left && matrix[i][j] == 1){
                        l = j;
                        left = true;
                        startline = i;
                    }
                    if (!right && left && matrix[i][j] != 1){
                        r = j - 1;
                        right = true;
                        count -= r - l + 1;
                    }
                    if (left && !right){
                        matrix[i][j] = 3;
                    }
                }
                if (!right && left){
                    r = m - 1;
                    right = true;
                    count -= r - l + 1;
                }
                i++;
            }
            // cout << "l: " << l << " r: " << r << " count: " << count << "\n";
            
            rows = 1; columns = r - l + 1;
            end = false;
            for (int k = i; k < n && !end; k++){
                tempcount = 0;
                for (int ind = l; ind <= r; ind++){
                    tempcount += (matrix[k][ind] == 1);
                }
                if (tempcount < r - l + 1){
                    end = true;
                } else {
                    rows++;
                    for (int ind = l; ind <= r; ind++){
                        matrix[k][ind] = 3;
                    }
                    count -= r - l + 1;
                }
            }
            // for (int i = 0; i < n; i++){
            //     for (int j = 0; j < m; j++){
            //         cout << matrix[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            if (count == 0){
                cout << "YES\n";
                for (int k = 0; k < n; k++){
                    for (int j = 0; j < m; j++){
                        if (matrix[k][j] == 0)
                            cout << ".";
                        if (matrix[k][j] == 2)
                            cout << "a";
                        if (matrix[k][j] == 3)
                            cout << "b";
                    }
                    cout << "\n";
                }
            } else {
                //cout << "NO\n";
                for (int k = 0; k < n; k++){
                    for (int j = 0; j < m; j++){
                        if (matrix[k][j] != 0)
                            matrix[k][j] = 1;
                    }
                }
                count = countstart;
                left = false; right = false;
                i = n - 1; l = -1; r = -1;
                // for (int i = 0; i < n; i++){
                //     for (int j = 0; j < m; j++){
                //         cout << matrix[i][j] << " ";
                //     }
                //     cout << "\n";
                // }
                while(i >= 0 && (!left || !right)){
                    for (int j = 0; j < m; j++){
                        if (!left && matrix[i][j] == 1){
                            l = j;
                            left = true;
                            startline = i;
                        }
                        if (!right && left && matrix[i][j] == 0){
                            r = j - 1;
                            right = true;
                            count -= r - l + 1;
                        }
                        if (left && !right){
                            matrix[i][j] = 2;
                        }
                    }
                    if (!right && left){
                        r = m - 1;
                        right = true;
                        count -= r - l + 1;
                    }
                    i--;
                }
                rows = 1; columns = r - l + 1;
                end = false;
                // for (int i = 0; i < n; i++){
                //     for (int j = 0; j < m; j++){
                //         cout << matrix[i][j] << " ";
                //     }
                //     cout << "\n";
                // }
                //cout << "i: " << i << " l: " << l << " r: " << r << "\n";
                for (int k = max(i,0); k >= 0 && !end; k--){
                    tempcount = 0;
                    for (int ind = l; ind <= r; ind++){
                        tempcount += (matrix[k][ind] == 1);
                    }
                    if (tempcount < r - l + 1){
                        end = true;
                    } else {
                        rows++;
                        for (int ind = l; ind <= r; ind++){
                            matrix[k][ind] = 2;
                        }
                        count -= r - l + 1;
                    }
                }
                
                left = false; right = false;
                i = n - 1; l = -1; r = -1;
                while(i >= 0 && (!left || !right)){
                    for (int j = 0; j < m; j++){
                        if (!left && matrix[i][j] == 1){
                            l = j;
                            left = true;
                            startline = i;
                        }
                        if (!right && left && matrix[i][j] != 1){
                            r = j - 1;
                            right = true;
                            count -= r - l + 1;
                        }
                        if (left && !right){
                            matrix[i][j] = 3;
                        }
                    }
                    if (!right && left){
                        r = m - 1;
                        right = true;
                        count -= r - l + 1;
                    }
                    i--;
                }
                
                rows = 1; columns = r - l + 1;
                end = false;
                for (int k = max(i,0); k >= 0 && !end; k--){
                    tempcount = 0;
                    for (int ind = l; ind <= r; ind++){
                        tempcount += (matrix[k][ind] == 1);
                    }
                    if (tempcount < r - l + 1){
                        end = true;
                    } else {
                        rows++;
                        for (int ind = l; ind <= r; ind++){
                            matrix[k][ind] = 3;
                        }
                        count -= r - l + 1;
                    }
                }
                
                if (count == 0){
                    cout << "YES\n";
                    for (int k = 0; k < n; k++){
                        for (int j = 0; j < m; j++){
                            if (matrix[k][j] == 0)
                                cout << ".";
                            if (matrix[k][j] == 2)
                                cout << "a";
                            if (matrix[k][j] == 3)
                                cout << "b";
                        }
                        cout << "\n";
                    }
                } else {
                    cout << "NO\n";
                    // for (int k = 0; k < n; k++){
                    //     for (int j = 0; j < m; j++){
                    //         if (matrix[k][j] == 0)
                    //             cout << ".";
                    //         if (matrix[k][j] == 2)
                    //             cout << "a";
                    //         if (matrix[k][j] == 3)
                    //             cout << "b";
                    //     }
                    //     cout << "\n";
                    // }
                    // for (int i = 0; i < n; i++){
                    //     for (int j = 0; j < m; j++){
                    //         cout << matrix[i][j] << " ";
                    //     }
                    //     cout << "\n";
                    // }
                }
            
            }
        }
    } 
}
/*
2 4
.#..
###.

4 3
..#
.##
.#.
...

3 2
#.
##
.#

3 3
.#.
###
.#.
*/
