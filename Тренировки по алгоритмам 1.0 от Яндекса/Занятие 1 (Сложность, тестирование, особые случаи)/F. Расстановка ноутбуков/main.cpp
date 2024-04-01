#include <iostream>

using namespace std;

void answer(int i, int a, int b, int c, int d){
    if (i == 1)
        cout << max(a,c) << " " << (b + d);
    if (i == 2)
        cout << max(a,d) << " " << (b + c);
    if (i == 3)
        cout << max(b,d) << " " << (a + c);
    if (i == 4)
        cout << max(b,c) << " " << (a + d);
    
}

int main()
{
    int a, b, c, d, s1, s2, s3, s4, mins, i = 1;
    cin >> a >> b >> c >> d;
    s1 = max(a,c) * (b + d);
    mins = s1;
    s2 = max(a,d) * (b + c);
    if (s2 < mins){
        mins = s2;
        i = 2;
    }
    s3 = max(b,d) * (a + c);
    if (s3 < mins){
        mins = s3;
        i = 3;
    }
    s4 = max(b,c) * (a + d);
    if (s4 < mins){
        mins = s4;
        i = 4;
    }
    answer(i, a, b, c, d);
}
