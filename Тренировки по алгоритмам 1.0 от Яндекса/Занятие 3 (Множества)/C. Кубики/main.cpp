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
    int a, n, m;
    cin >> n >> m;
    set<int> set1, set2, intersection;
    for (int i = 0; i < n; i++){
        cin >> a;
        set1.insert(a);
    }
    for (int i = 0; i < m; i++){
        cin >> a;
        set2.insert(a);
    }
    
    vector<int> vec1, vec2;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersection, intersection.begin()));
    set_symmetric_difference(set1.begin(), set1.end(), intersection.begin(), intersection.end(), back_inserter(vec1));
    set_symmetric_difference(set2.begin(), set2.end(), intersection.begin(), intersection.end(), back_inserter(vec2));
    cout << intersection.size() << "\n";
    for (auto elem : intersection)
       cout << elem << " ";
    cout << "\n" << vec1.size() << "\n";
    for (auto elem : vec1)
       cout << elem << " ";
    cout << "\n" << vec2.size() << "\n";
    for (auto elem : vec2)
       cout << elem << " ";
    cout << "\n";

}
