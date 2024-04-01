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
    int k;
    string text;
    cin >> k >> text;
    int l, r;
    long long sum = 0, tempsum;
    int i = 0;
    for (i ; i < text.size() - k;){
        tempsum = 0;
        l = i;
        r = i + k;
        while (text[r] == text[l]){
            tempsum++;
            l++;
            r++;
        }
        sum += tempsum * (tempsum + 1) / 2;
        i = r - k + 1;
    }
    cout << sum;
}



