#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int g, s, sum, count = 0;
    cin >> g >> s;
    string word, text;
    cin >> word >> text;
    unordered_map<char, int> pronounce, dictionary, temp;
    for (char elem : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"){
        pronounce[elem] = 0;
        dictionary[elem] = 0;
    }
    for (int i = 0; i < g; i++)
        pronounce[word[i]]++;
    temp = pronounce;
    sum = g;
    for (int i = 0; i < g; i++)
        dictionary[text[i]]++;
    count += (pronounce == dictionary);
    for (int i = g; i < s; i++){
        dictionary[text[i - g]]--;
        dictionary[text[i]]++;
        count += (pronounce == dictionary);
    }
    cout << count;
    //cout << count;
}

// 3 10
// abb
// bbbabbbbba
