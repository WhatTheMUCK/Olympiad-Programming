#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, a;
	cin >> n >> k;
	unordered_map<int, int> dict;
	long long min = 10000000000;
	for (int i = 0; i < n; i++){
		cin >> a;
		if (dict.find(a) == dict.end())
			dict[a] = i;
		else {
			if (i - dict[a] < min)
				min = i - dict[a];
			dict[a] = i;
		}
	}
	cout << (min <= k ? "YES" : "NO");
}
