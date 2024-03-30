#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

namespace std {
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
};
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, y;
	cin >> n;
	unordered_set<pair<int, int>> demension;
	string cords;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		//cords = to_string(x) + " " + to_string(y);	    
		demension.insert({x, y});
	}
	int square = 4, temp, x1, x2, y1, y2;
	double dx, dy;
	pair<int, int> third, fourth;
	pair<double, double> center;
	vector<pair<int, int>> answer;
	answer.push_back({x + 1, y});
	answer.push_back({x, y + 1});
	answer.push_back({x + 1, y + 1});
	if (demension.size() > 0)
		square--;
	int mintemp = square;
	unordered_set<pair<int, int>>::iterator point1 = demension.begin(), point2 = demension.begin();
	for (; point1 != demension.end(); point1++){
		point2 = point1;
		point2++;
		for (; point2 != demension.end(); point2++){
			if (mintemp == 0){
			    cout << "\n" << mintemp;
	            //cout << "\nНедостающие точки:";
	           for (int i = 0; i < answer.size(); i++){
		           cout << "\n" << answer[i].first << " " << answer[i].second;
	            }
	            return 0;
			}
			vector<pair<int, int>> random;
				x1 = (*point1).first;
				y1 = (*point1).second;
				x2 = (*point2).first;
				y2 = (*point2).second;
				dx = x1 - x2;
				dy = y1 - y2;
				
				temp = square - 1;
				third.first = (int)(x1 - dy);
				third.second = (int)(y1 + dx);
				fourth.first = (int)(x2 - dy);
				fourth.second = (int)(y2 + dx);
				//cords = to_string(third.first) + " " +to_string(third.second);
				if (demension.find(third) != demension.end()){
					temp--;
				}else
					random.push_back(third);
				//cords = to_string(fourth.first) + " " + to_string(fourth.second);
				if (demension.find(fourth) != demension.end()){
					temp--;
				}else
					random.push_back(fourth);
				if (temp < mintemp){
					mintemp = temp;
					answer = random;
					/*cout <<"\n-----\n";
					cout << mintemp;
	                cout << "\nТип 1\nНедостающие точки:";
	                for (int i = 0; i < answer.size(); i++){
		                cout << "\n" << answer[i];
	                }
	                cout << "\nИмеющиеся точки:";
	                for (int i = 0; i < answer1.size(); i++){
		                cout << "\n" << answer1[i];
	                } */
				}
				random = {};
				
				temp = square - 1;
				third.first = (int)(x1 - dy);
				third.second = (int)(y1 + dx);
				fourth.first = (int)(x2 - dy);
				fourth.second = (int)(y2 + dx);
				//cords = to_string(third.first) + " "+to_string(third.second);
				if (demension.find(third) != demension.end()){
					temp--;
				}else
					random.push_back(third);
				//cords = to_string(fourth.first) + " " + to_string(fourth.second);
				if (demension.find(fourth) != demension.end()){
					temp--;
				}else
					random.push_back(fourth);
				if (temp < mintemp){
					mintemp = temp;
					answer = random;
					/*cout <<"\n-----\n";
					cout << mintemp;
	                cout << "\nТип 2\nНедостающие точки:";
	                for (int i = 0; i < answer.size(); i++){
		                cout << "\n" << answer[i];
	                }
	                cout << "\nИмеющиеся точки:";
	                for (int i = 0; i < answer1.size(); i++){
		                cout << "\n" << answer1[i];
	                } */
				}
				random = {};
				
				temp = square - 1;
				dx = dx/2;
				dy = dy/2;
				center.first = x2 + dx;
				center.second = y2 + dy;
				if (dx + dy == (int)(dx + dy)){
				    third.first = (int)(center.first - dy);
				    third.second = (int)(center.second + dx);
				    fourth.first = (int)(center.first + dy);
				    fourth.second = (int)(center.second - dx);
				    //cords = to_string(third.first) + " "+to_string(third.second);
				    if (demension.find(third) != demension.end()){
					    temp--;
				    }else
					    random.push_back(third);
				    //cords = to_string(fourth.first) + " " + to_string(fourth.second);
				    if (demension.find(fourth) != demension.end()){
					    temp--;
				    }else
					    random.push_back(fourth);
				    if (temp < mintemp){
					    mintemp = temp;
					    answer = random;
                        /*cout <<"\n-----\n";
					    cout << mintemp;
	                    cout << "\nТип 3\n"; 
	                    cout << x1 << " " << y1 << "\n" << x2 << " " << y2 << "\n" << center.first << " " << center.second ;
	                    cout << "\nНедостающие точки:";
	                    for (int i = 0; i < answer.size(); i++){
		                    cout << "\n" << answer[i];
	                    }
	                    cout << "\nИмеющиеся точки:";
	                    for (int i = 0; i < answer1.size(); i++){
		                    cout << "\n" << answer1[i];
	                    } */
				    }
			}
		}
	}
	cout << "\n" << mintemp;
	//cout << "\nНедостающие точки:";
	for (int i = 0; i < answer.size(); i++){
		cout << "\n" << answer[i].first << " " << answer[i].second;
	}
	/*cout << "\nИмеющиеся точки:";
	for (int i = 0; i < answer1.size(); i++){
		cout << "\n" << answer1[i];
	}*/
}

/* 
21
-3 3
5 4
-9 -1
0 4
7 -2
1 8
3 4
8 -1
-1 -2
10 6
-2 -8
-6 -6
5 -10
1 5
-4 -4
-9 6
-9 -7
0 7
3 -7
-4 1
1 0
*/
