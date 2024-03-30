#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

typedef struct{
    int up, down, index;
}info;

bool compare(const info& lhs, const info& rhs){
    return lhs.down < rhs.down;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, x, y, maxlast = -1, ilast = -1, maxsum = -1;
    cin >> n;
    vector<info> input(n);
    vector<int> skip, answer;
    for (int i = 0 ; i < n; i++){
        cin >> input[i].up >> input[i].down;
        input[i].index = i;
    }
    // for (info elem : input){
    //     cout << elem.up << " " << elem.down << " " << elem.up - elem.down << "\n";
    // } 
    sort(input.begin(), input.end(), compare);
    // cout << "=====\n";
    // for (info elem : input){
    //     cout << elem.up << " " << elem.down << " " << elem.index << "\n";
    // } 
    // cout << "=====\n";
    long long sum = 0;
    for (int i = 0; i < n; i++){
        if (input[i].up - input[i].down > 0){
            answer.push_back(input[i].index);
            sum += input[i].up - input[i].down;
            if (sum + input[i].down > maxsum){
                maxsum = sum + input[i].down;
            }
        } else {
            if (input[i].up > maxlast){
                maxlast = input[i].up;
            }
            skip.push_back(i);
        }
    }
    if (maxlast > -1){
        int size = skip.size();
        bool end = false;
        vector<int>::iterator iter = skip.begin();
        for (int i = 0; i < size && !end; i++){
            if (input[skip[i]].up == maxlast){
                end = true;
                answer.push_back(input[skip[i]].index);
                skip.erase(iter);
                sum += maxlast;
                maxsum = max(sum, maxsum);
            }
            iter++;
        }
    }
    cout << maxsum << "\n";
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] + 1 << " ";
    }
    for (int i = 0; i < skip.size(); i++){
        cout << input[skip[i]].index + 1 << " ";
    }
}    
