#include <iostream>
#include <vector>
#include <set>

using namespace std;

int binsearch(vector<int>& search, int target){
	//cout << "\nSearch: " << target << "\n";
	int l = 0, r = search.size() - 1, m = (l + r) / 2;
	//cout << "search[" << m << "]: " << search[m] << "\n";
	while (search[m] != target){
		//cout << "l: " << l << " r: " << r << " search[" << m << "]: " << search[m] << "\n";
		if (search[m] > target){
			r = m;
		} else {
			l = m + 1;
		}
		m = (l + r) / 2;
		if (r - l <= 1){
			m = l;
			break;
		}
	}
	return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, in;
    cin >> n >> k;
    vector<int> search;
    for (int i = 0; i < n; i++){
    	cin >> in;
    	search.push_back(in);
    }
    for (int i = 0; i < k; i++){
    	cin >> in;
    	cout << search[binsearch(search, in)] << "\n";
    }
}
