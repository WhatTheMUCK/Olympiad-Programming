#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t, n, a, count, length, answer;
    cin >> t;
    for (int i = 0; i < t; i++){
        vector<int> out;
        cin >> n;
        answer = 1;
        cin >> length;
        count = 1;
        for (int j = 1; j < n; j++){
            cin >> a;
            count++;
            length = min(a, length);
            if (length - count < 0){
                answer++;
                out.push_back(count - 1);
                length = a;
                count = 1;
            }
        }
        out.push_back(count);
        cout << answer << "\n";
        for (int k = 0; k < out.size(); k++){
            cout << out[k] << " ";
        }
        cout << "\n";
    }
}    
