#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<string, int> dictionary;
    string input;
    while (cin >> input){
        if (dictionary.find(input) == dictionary.end()){
            cout << "0 ";
            dictionary[input] = 1;
        } else {
            cout << dictionary[input] << " ";
            dictionary[input]++;
        }
    }
}
