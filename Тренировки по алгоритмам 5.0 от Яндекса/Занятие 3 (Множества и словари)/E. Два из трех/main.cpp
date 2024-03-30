#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int n, a;
	unordered_map<int, int> dict;
	vector<int> ans;
	for (int i = 0; i < 3; i++){
		cin >> n;
		set<int> st;
		for (int j = 0; j < n; j++){
			cin >> a;
			st.insert(a);
		}
		for (set<int>::iterator k = st.begin(); k != st.end(); k++){
			if (dict.find(*k) == dict.end()){
				dict[*k] = 1;
			} else {
				dict[*k]++;
			}
		}
	}
	for (auto elem : dict){
		if (elem.second > 1)
	    	ans.push_back(elem.first);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
}
