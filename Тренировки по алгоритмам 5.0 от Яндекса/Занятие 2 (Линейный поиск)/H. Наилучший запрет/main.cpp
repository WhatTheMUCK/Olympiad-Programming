#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, max1 = -1, max2 = -1, max3 = -1, maxend1 = -1, maxend2 = -1, line1, column1, line2, column2;
    cin >> n >> m;
    vector<vector<int>> power(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> power[i][j]; 
            if (power[i][j] > max1){
                max1 = power[i][j];
                line1 = i;
                column2 = j;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (i != line1){
            for (int j = 0; j < m; j++){
                if (power[i][j] > max2){
                    max2 = power[i][j];
                    column1 = j;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j != column2){
                if (power[i][j] > max3){
                    max3 = power[i][j];
                    line2 = i;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        if (i != line1){
            for (int j = 0; j < m; j++){
                if (j != column1){
                    if (power[i][j] > maxend1){
                        maxend1 = power[i][j];
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        if (i != line2){
            for (int j = 0; j < m; j++){
                if (j != column2){
                    if (power[i][j] > maxend2){
                        maxend2 = power[i][j];
                    }
                }
            }
        }
    }
    
    if (maxend2 < maxend1){
        cout << line2 + 1 << " " << column2 + 1;
    } else {
        cout << line1 + 1 << " " << column1 + 1;
    }
}    
