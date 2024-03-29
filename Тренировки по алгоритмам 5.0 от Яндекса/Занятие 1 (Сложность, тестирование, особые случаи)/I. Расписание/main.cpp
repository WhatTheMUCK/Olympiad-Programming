#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string month, firstDayAtYear;
    int n, year, day;
    unordered_map<string, int> week;
    vector<string> vec = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cin >> n >> year;
    vector<pair<int, string>> input(n);
    for (int i = 0; i < n; i++){
        cin >> input[i].first >> input[i].second;
    }
    cin >> firstDayAtYear;
    bool days366 = ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? true : false);
    int j = 0;
    for (j; j < 7 && vec[j] != firstDayAtYear; j++);
    for (int i = 0; i < 7; i++){
        week[vec[i]] = (365 + days366) / 7;
    }
    for (int i = 0; i < (365 + days366) % 7; i++){
        week[vec[(j + i) % 7]]++;
    }
    // for (pair<string, int> elem : week){
    //     cout << elem.first << ": " << elem.second << "\n";
    // }
    unordered_map<string, vector<string>> wholeYear;
    int pos;
    pos = j;
    for (int i = 0; i < 31; i++){
        wholeYear["January"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 31) % 7;
    for (int i = 0; i < 28 + days366; i++){
        wholeYear["February"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 28 + days366) % 7; 
    for (int i = 0; i < 31; i++){
        wholeYear["March"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 31) % 7;
    for (int i = 0; i < 30; i++){
        wholeYear["April"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 30) % 7;
    for (int i = 0; i < 31; i++){
        wholeYear["May"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 31) % 7;
    for (int i = 0; i < 30; i++){
        wholeYear["June"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 30) % 7;
    for (int i = 0; i < 31; i++){
        wholeYear["July"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 31) % 7;
    for (int i = 0; i < 31; i++){
        wholeYear["August"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 31) % 7;
    for (int i = 0; i < 30; i++){
        wholeYear["September"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 30) % 7;
    for (int i = 0; i < 31; i++){
        wholeYear["October"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 31) % 7;
    for (int i = 0; i < 30; i++){
        wholeYear["November"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 30) % 7;
    for (int i = 0; i < 31; i++){
        wholeYear["December"].push_back(vec[(pos + i) % 7]);
    }
    pos = (pos + 31) % 7;
    
    for (int i = 0; i < n; i++){
        week[wholeYear[input[i].second][input[i].first - 1]]--;
    }
    
    int max = 0, min = 100;
    for (pair<string, int> elem : week){
        if (elem.second > max)
            max = elem.second;
        if (elem.second < min)
            min = elem.second;
    }
    for (pair<string, int> elem : week){
        if (elem.second == max){
            cout << elem.first << " ";
            break;
        }
    }
    for (pair<string, int> elem : week){
        if (elem.second == min){
            cout << elem.first << "\n";
            break;
        }
    }
    // for (pair<string, int> elem : week){
    //     if (elem.second == max){
    //         cout << elem.first << " ";
    //     }
    // }
    // for (pair<string, vector<string>> elem : wholeYear){
    //     cout << elem.first << ":\n";
    //     cout << 1 << ": " << elem.second[0] << "\n";
    //     cout << elem.second.size() << ": " << elem.second[elem.second.size() - 1] << "\n"; 
    // }
}
