#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool CustomLess1 (const pair<string, unordered_map<string, long long>>& lhs, const pair<string, unordered_map<string, long long>>& rhs){
    return lhs.first < rhs.first;
}

bool CustomLess2 (const pair<string, long long>& lhs, const pair<string, long long>& rhs){
    return lhs.first < rhs.first;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<string, unordered_map<string, long long>> database;
    string user, product;
    long long amount;
    while (cin >> user >> product >> amount){
        if (database.find(user) == database.end())
            database[user][product] = amount;
        else if (database[user].find(product) == database[user].end())
            database[user][product] = amount;
        else
            database[user][product] += amount;
    }
    vector<pair<string, unordered_map<string, long long>>> answer(database.begin(), database.end());
    sort(answer.begin(), answer.end(), CustomLess1);
    for (auto list : answer){
        cout << list.first << ":\n";
        vector<pair<string, long long>> sortedInner(list.second.begin(), list.second.end());
        sort(sortedInner.begin(), sortedInner.end(), CustomLess2);
        for (auto info : sortedInner){
            cout << info.first << " " << info.second << "\n";
        }
    }
}
