#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int answer = 0;
    string in1, in2;
    cin >> in1 >> in2;
    unordered_map<string, int> map;
    set<string> set2;
    for (int i = 0; i < in1.size() - 1; i++){
        if (map.find(in1.substr(i,2)) != map.end())
            map[in1.substr(i,2)]++;
        else
            map[in1.substr(i,2)] = 1;
    }
    for (int i = 0; i < in2.size() - 1; i++)
        set2.insert(in2.substr(i,2));
    
    for (auto elem : set2){
        if (map.find(elem) != map.end())
            answer += map[elem];
    }
    cout << answer;
}
