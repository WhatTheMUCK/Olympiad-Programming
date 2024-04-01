#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

typedef struct {
    string word;
    char accent;
    int pos, amount;
}custom;

custom Helper(string a){
    custom answer;
    answer.word = "";
    answer.amount = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] - 'a' >= 0 && a[i] - 'z' <= 0)
            answer.word += a[i];
        if (a[i] - 'A' >= 0 && a[i] - 'Z' <= 0){
            answer.word += a[i] - 'A' + 'a';
            answer.accent = a[i];
            answer.amount++;
            answer.pos = i;
        }
    }
    return answer;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    custom temp;
    string word;
    unordered_map<string, vector<pair<char, int>>> dictionary;
    int n, count = 0, countAll = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> word;
        temp = Helper(word);
        dictionary[temp.word].push_back({temp.accent, temp.pos});
    }
    bool flag;
    while (cin >> word){
        countAll++;
        flag = false;
        temp = Helper(word);
        if (temp.amount == 1 && dictionary.find(temp.word) == dictionary.end())
            count++;
        else if (temp.amount == 1){
            for (pair<char, int> elem : dictionary[temp.word])
                temp.accent == elem.first && temp.pos == elem.second ? flag = true : flag = flag;
            flag ? count++ : count = count;
        }
    } 
    cout << countAll - count;
}

