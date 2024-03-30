#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	string first, second;
	cin >> first >> second;
	unordered_map<char, int> dictionary;
	for (int i = 0; i < first.size(); i++){
		if (dictionary.find(first[i]) == dictionary.end()){
			dictionary[first[i]] = 1;
		} else {
			dictionary[first[i]]++;
		}
	}
	for (int i = 0; i < second.size(); i++){
		if (dictionary.find(second[i]) == dictionary.end()){
			dictionary[second[i]] = -1;
		} else {
			dictionary[second[i]]--;
		}
	}
	bool flag = true;
	for(auto elem : dictionary){
		if (elem.second != 0){
			flag = false;
		}
	}
	cout << (flag ? "YES" : "NO");
}
