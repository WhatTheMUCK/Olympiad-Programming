#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	int n, k;
	string in;
	ifstream file("input.txt");
	unordered_map<string, int> dict;
	vector<string> ans;
	file >> n;
	for (int i = 0; i < n; i++){
		file >> k;
		for (int j = 0; j < k; j++){
			file >> in;
			if (dict.find(in) == dict.end()){
				dict[in] = 1;
			} else {
				dict[in]++;
			}
		}
	}
	for (auto elem : dict){
		if (elem.second == n){
			ans.push_back(elem.first);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++){
	    cout << ans[i] << " ";
	}
}
