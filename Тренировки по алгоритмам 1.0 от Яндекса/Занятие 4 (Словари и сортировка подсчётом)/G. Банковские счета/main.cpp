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
    string operation, name, nameTo, in;
    long long sum, percent;
    unordered_map<string, int> user;
    while (getline(cin, in)){
        stringstream input(in);
        input >> operation;
        // DEPOSIT INCOME BALANCE TRANSFER WITHDRAW
        if (operation == "DEPOSIT"){
            input >> name >> sum;
            user.find(name) == user.end() ? user[name] = sum : user[name] += sum;
        }
        if (operation == "WITHDRAW"){
            input >> name >> sum;
            user.find(name) == user.end() ? user[name] = -sum : user[name] -= sum;
        }
        if (operation == "BALANCE"){
            input >> name;
            cout << (user.find(name) == user.end() ? "ERROR\n" : to_string(user[name]) + "\n");
        }
        if (operation == "TRANSFER"){
            input >> name >> nameTo >> sum;
            user.find(name) == user.end() ? user[name] = -sum : user[name] -= sum;
            user.find(nameTo) == user.end() ? user[nameTo] = sum : user[nameTo] += sum;
        }
        if (operation == "INCOME"){
            input >> percent;
            for (pair<string, int> elem : user)
                user[elem.first] > 0 ? user[elem.first] += user[elem.first] * percent / 100 : user[elem.first] = user[elem.first];
        }
    }
}
