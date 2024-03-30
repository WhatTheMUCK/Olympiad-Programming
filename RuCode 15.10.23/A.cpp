#include <iostream>

using namespace std;

int main()
{
    int pf, pe, pd, k;
    cin >> pf >> pe >> pd >> k;
    if (k == 0){
        cout << "F";
    } else if (k == 1){
        cout << "E";
    } else if (k - pf < (pe + 1)/2){
        cout << "E";
    } else if (k - pf == (pe + 1)/2){
        cout << "D/E";
    } else if ( k - pf > (pe + 1)/2 && k - pf - pe < (pd + 1)/2){
        cout << "D";
    } else if (k - pf > (pe + 1)/2 && k - pf - pe == (pd + 1)/2){
        cout << "C/D";
    } else if (k - pf > (pe + 1)/2 && k - pf - pe > (pd + 1)/2 && k != pf + pe + pd + 1){
        cout << "C";
    } else if (k == pf + pe + pd + 1){
        cout << "Champ AB";
    }
}
