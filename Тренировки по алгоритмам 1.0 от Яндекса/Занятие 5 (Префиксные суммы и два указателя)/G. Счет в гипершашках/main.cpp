#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;
    unordered_map<int, int> cards;
    vector<pair<int, int>> order;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> x;
        cards.find(x) == cards.end() ? cards[x] = 1 : cards[x]++;
    }
    for (pair<int, int> elem : cards){
        order.push_back(elem);
    }
    sort(order.begin(), order.end());
    int j = 0, count2 = 0, count3 = 0, len;
    unsigned long long sum = 0;
    for (int i = 0; i < order.size(); i++){
        while (j < order.size()  && order[j].first <= 1ull * k * order[i].first){
            if (order[j].second >= 2) 
                count2++;
            j++;
        }
        len = j - i;
        if (order[i].second >= 2)
            sum += 1ull * (len - 1) * 3;
        if (order[i].second >= 3)
            sum++;
        sum += 1ull * (len - 1) * (len - 2) * 3;
        if (order[i].second >= 2)
            count2--;
        sum += 1ull * count2 * 3;
    }
    cout << sum;
    
}

/*
10 2
1 1 3 4 5 7 7 7 8 9

10 2 
1 1 3 4 5 11 11 11 12 13

8 99
100 99 2 1 100 99 2 1

*/
