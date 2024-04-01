#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string lowRegister(string in){
    string answer = "";
    for (char elem : in){
        if (elem - 'A' >= 0 && elem - 'Z' <= 0)
            answer += elem - 'A' + 'a';
        else
            answer += elem;
    }
    return answer;
}
void identificators(string word, bool figureStart, unordered_map<string, int>& dictionary, unordered_map<string, int>& keywords, vector<string>& orderInsert){
    string identificator = "";
    bool condition, haveNotOnlyFigures = false;
    for (int i = 0; i < word.size(); i++){
        condition = ((word[i] - 'a' >= 0 && word[i] - 'z' <= 0) || (word[i] - 'A' >= 0 && word[i] - 'Z' <= 0) 
                    || (word[i] - '0' >= 0 && word[i] - '0' <= 9) || word[i] == '_');
        if (condition){
            identificator += word[i];
            condition && !(word[i] - '0' >= 0 && word[i] - '0' <= 9) ? haveNotOnlyFigures = true : haveNotOnlyFigures = haveNotOnlyFigures;
        } 
        if (identificator.size() && (!condition || i == word.size() - 1)){
            if (dictionary.find(identificator) == dictionary.end() && keywords.find(identificator) == keywords.end() 
                && haveNotOnlyFigures && (!(identificator[0] - '0' >= 0 && identificator[0] - '0' <= 9) || figureStart)){
                dictionary[identificator] = 1;
                orderInsert.push_back(identificator);
            } else if (dictionary.find(identificator) != dictionary.end() && keywords.find(identificator) == keywords.end()
                        && haveNotOnlyFigures && (!(identificator[0] - '0' >= 0 && identificator[0] - '0' <= 9) || figureStart))
                dictionary[identificator]++;
            identificator = "";
            haveNotOnlyFigures = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, maxRepeat, minPos = -1;
    vector<string> orderInsert;
    unordered_map<string, int> dictionary, keywords, final;
    string word, reg, figS;
    cin >> n >> reg >> figS;
    bool registr = (reg == "yes"), figureStart = (figS == "yes");
    for (int i = 0; i < n; i++){
        cin >> word;
        if (!registr)
            word = lowRegister(word);
        keywords[word] = 0;
    }
    while (cin >> word){
        if (!registr)
            word = lowRegister(word);
        identificators(word, figureStart, dictionary, keywords, orderInsert);
    }
    maxRepeat = (*dictionary.begin()).second;
    for (pair<string, int> elem : dictionary)
        elem.second > maxRepeat ? maxRepeat = elem.second : maxRepeat = maxRepeat;
    for (pair<string, int> elem : dictionary){
        if (elem.second == maxRepeat){
            for (int i = 0; i < orderInsert.size(); i++){
                if (orderInsert[i] == elem.first){
                    final[elem.first] = i;
                    if (i < minPos || minPos == -1)
                        minPos = i;
                }
            }
        }
    }
    // cout << maxRepeat << "\n";
    // for (auto elem : dictionary)
    //     cout << elem.second << " " << elem.first << "\n";
    // for (auto elem : orderInsert)
    //     cout << elem << "\n";
    cout << orderInsert[minPos];
}

/*
1 yes no
int
int main() {
  int a;
  int b;
  scanf("%d%d", &a, &b);
  printf("%d", a + b);
}
*/
