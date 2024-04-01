#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n, a;
    string input = "", help = "", answer = "";
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        input += to_string(a);
        help = to_string(a) + help;
    }
    for (int i = 0; i < n; i++)
        input += "|";
    int i = 0, j = 0;
    while (j < n){
        if (input[i] == help[j]){
            i++; j++;    
        } else if (input[i] == '|'){
            answer += help[j];
            answer += " ";
            i++; j++;
        } else {
            i++;
            j = 0;
        }
    }
    cout << answer.size()/2 << "\n" << answer;
}
