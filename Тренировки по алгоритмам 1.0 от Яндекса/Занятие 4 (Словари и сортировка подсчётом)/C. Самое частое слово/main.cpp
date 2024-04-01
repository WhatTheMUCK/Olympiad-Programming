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
    string input, answerString;
    cin >> answerString;
    dictionary[answerString] = 1;
    int maxRepeat = 1;
    while (cin >> input){
        if (dictionary.find(input) == dictionary.end())
            dictionary[input] = 1;
        else 
            dictionary[input]++;
        if (maxRepeat < dictionary[input]){
            maxRepeat = dictionary[input];
            answerString = input;
        } else if (maxRepeat == dictionary[input])
            answerString > input ? answerString = input : answerString = answerString;
    }
    cout << answerString;
}
