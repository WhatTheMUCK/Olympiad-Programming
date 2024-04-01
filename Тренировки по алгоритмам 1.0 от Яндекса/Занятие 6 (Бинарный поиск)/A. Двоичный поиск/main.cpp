#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, in;
    cin >> n >> k;
    set<int> search;
    for (int i = 0; i < n; i++){
    	cin >> in;
    	search.insert(in);
    }
    for (int i = 0; i < k; i++){
    	cin >> in;
    	cout << (search.find(in) != search.end() ? "YES\n" : "NO\n");
    }
}
