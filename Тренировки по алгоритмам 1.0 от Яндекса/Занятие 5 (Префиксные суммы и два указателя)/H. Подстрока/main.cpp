#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string text;
    unordered_map<char, int> chars;
    cin >> n >> k >> text;
    for (int i = 0; i < n; i++){
        chars.find(text[i]) == chars.end() ? chars[text[i]] = 0 : chars[text[i]] = chars[text[i]];
    }
    
    int l = 0, r = 0, answerL, length = 0;
    for (l; l < n; l++){
        while (r < n && chars[text[r]] < k){
            chars[text[r]]++;
            r++;
        }
        if (length < r - l){
            length = r - l;
            answerL = l + 1;
        }
         chars[text[l]]--;
    }
    cout << length << " " << answerL; 
    
    
    
}



