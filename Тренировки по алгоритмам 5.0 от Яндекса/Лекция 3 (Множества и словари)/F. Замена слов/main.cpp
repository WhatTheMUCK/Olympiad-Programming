#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

int main()
{
	string in, answer = "";
	unordered_map<string, int> dict;
	getline(cin, in);
	stringstream input1(in);
	while (input1 >> in){
		if (dict.find(in) == dict.end())
			dict[in] = 0;
	}
	getline(cin, in);
	stringstream input2(in);
	while (input2 >> in){
		string search = "";
		search += in[0];
        int i = 1;
        while (i < in.size() && dict.find(search) == dict.end()){
        	search += in[i];
        	i++;
        }
		answer += (search + " ");
	}
	answer.pop_back();
    cout << answer;
}
