#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin >> n >> l;
    vector<vector<int>> vecs(n, vector<int>(l, 0));
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < l; j++){
    		cin >> vecs[i][j];
    	}
    }
    vector<int> temp;
    for (int i = 0; i < n; i++){
    	for (int j = i + 1; j < n; j++){
    		temp = vecs[i];
    		for (int k = 0; k < l; k++){
    			temp.push_back(vecs[j][k]);
    		}
    		sort(temp.begin(), temp.end());
    		cout << temp[l - 1] << "\n";
    	}
    }
}
