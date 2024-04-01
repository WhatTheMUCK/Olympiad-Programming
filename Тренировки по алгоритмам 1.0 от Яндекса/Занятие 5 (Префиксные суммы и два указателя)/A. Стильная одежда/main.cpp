#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int minimum, Tshirt, pants;
} help;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> Tshirts(n);
    for (int i = 0; i < n; i++)
        cin >> Tshirts[i];
    cin >> m;
    vector<int> pants(m);
    vector<int>::iterator iter = Tshirts.begin();;
    help answer;
    answer.minimum = 10000001;
    for (int i = 0; i < m; i++){
        cin >> pants[i];
        while ((*iter) < pants[i] && iter != Tshirts.end())
            iter++;
        if (answer.minimum > abs(pants[i] - (*iter))){
            answer.minimum = abs(pants[i] - (*iter));
            answer.Tshirt = (*iter);
            answer.pants = pants[i];
        }
        iter != Tshirts.begin() ? iter-- : iter = iter;
        if (answer.minimum > abs(pants[i] - (*iter))){
            answer.minimum = abs(pants[i] - (*iter));
            answer.Tshirt = (*iter);
            answer.pants = pants[i];
        }
    }
    cout << answer.Tshirt << " " << answer.pants;
}
