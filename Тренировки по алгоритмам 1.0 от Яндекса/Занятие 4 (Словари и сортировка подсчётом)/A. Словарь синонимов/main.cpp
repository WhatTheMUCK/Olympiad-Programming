#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<string, vector<string>> dictionary;
    int n;
    string first, second;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> first >> second;
        if (dictionary.find(first) == dictionary.end())
            dictionary[first] = {second};
        else
            dictionary[first].push_back(second);
        if (dictionary.find(second) == dictionary.end())
            dictionary[second] = {first};
        else
            dictionary[second].push_back(first);
    }
    cin >> first;
    for (int i = 0; i < dictionary[first].size(); i++)
        cout << dictionary[first][i] << "\n";
}
