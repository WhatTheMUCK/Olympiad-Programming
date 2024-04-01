#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string in;
    int size1, a;
    set<int> set;
    for (int i = 0; i < 3 ; i++){
        cin >> a;
        set.insert(a);
    }
    size1 = set.size();
    cin >> in;
    for (int i = 0; i < in.size(); i++)
        set.insert(in[i] - '0');
    cout << set.size() - size1;
}
