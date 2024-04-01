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
    int a;
    set<int> set1, set2;
    vector<int> intersection;
    string s;
    getline(cin, s);
    stringstream ss1(s);
    getline(cin, s);
    stringstream ss2(s);
    while (ss1 >> a)
        set1.insert(a);
        //set.insert(a);
    while (ss2 >> a)
        set2.insert(a);
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(intersection));
    for(auto elem : intersection)
       cout << elem << " ";
    
    // cout << "\n";   
    // for (int i = 0; i < vec1.size(); i++)
    //     cout << vec1[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < vec2.size(); i++)
    //     cout << vec2[i] << " ";
}
