#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, in, count = 0, max  = -1;
	vector<int> dict(100001, 0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> in;
		dict[in]++;
		count++;
	}
	for (int i = 1; i < dict.size(); i++){
		if (dict[i] + dict[i - 1] > max)
			max = dict[i] + dict[i - 1];
	}
	cout << count - max;
}
