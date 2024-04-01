#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

bool operator==(const string& lhs, const string& rhs){
    if (lhs.size() != rhs.size())
        return false;
    for (int i = 0; i < lhs.size(); i++)
        if (lhs[i] != rhs[i])
            return false;
    return true;
}
 
string DashDestroyer(string input)
{
    string answer = "";
    for (int i = 0; i < input.size(); i++)
        (input[i] != '-' && input[i] != '(' && input[i] != ')') ? answer += input[i] : answer = answer;
    return answer;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <string> first;
    string start, temp;
    bool flag;
    cin >> start;
    start = DashDestroyer(start);
    //cout << start << " "  << start.size() - 10 << " " << start.size() - 8 << " " << start.substr(start.size() - 10, start.size() - 8) << "\n";
    first.push_back(start.substr(start.size() - 7, 7));
    if (start.size() > 7) 
        first.push_back(start.substr(start.size() - 10, 3));
    else
        first.push_back("495");
    //cout << first[0] << "\n" << first[1];
    for (int i = 0; i < 3; i++){
        vector <string> unfirst;
        flag = true;
        cin >> temp;
        temp = DashDestroyer(temp);
        unfirst.push_back(temp.substr(temp.size() - 7, 7));
        if (temp.size() > 7) 
            unfirst.push_back(temp.substr(temp.size() - 10, 3));
        else 
            unfirst.push_back("495");
        for (int j = 0; j < 2; j++)
            if (!(first[j] == unfirst[j]))
                flag = false;
        cout << (flag ? "YES\n" : "NO\n");
    }
}
 
/*
Телефонные номера в адресной книге мобильного телефона имеют один из следующих форматов: +7<код><номер>, 8<код><номер>, <номер>, где <номер> — это семь цифр, а <код> — это три цифры или три цифры в круглых скобках. Если код не указан, то считается, что он равен 495. Кроме того, в записи телефонного номера может стоять знак “-” между любыми двумя цифрами (см. пример). На данный момент в адресной книге телефона Васи записано всего три телефонных номера, и он хочет записать туда еще один. Но он не может понять, не записан ли уже такой номер в телефонной книге. Помогите ему! Два телефонных номера совпадают, если у них равны коды и равны номера. Например, +7(916)0123456 и 89160123456 — это один и тот же номер.
 
Формат ввода
В первой строке входных данных записан номер телефона, который Вася хочет добавить в адресную книгу своего телефона. В следующих трех строках записаны три номера телефонов, которые уже находятся в адресной книге телефона Васи. Гарантируется, что каждая из записей соответствует одному из трех приведенных в условии форматов.
 
Формат вывода
Для каждого телефонного номера в адресной книге выведите YES (заглавными буквами), если он совпадает с тем телефонным номером, который Вася хочет добавить в адресную книгу или NO (заглавными буквами) в противном случае.
 
Пример 1
Ввод    Вывод
8(495)430-23-97
+7-4-9-5-43-023-97
4-3-0-2-3-9-7
8-495-430
YES
YES
NO
Пример 2
Ввод    Вывод
86406361642
83341994118
86406361642
83341994118
NO
YES
NO
Пример 3
Ввод    Вывод
+78047952807
+78047952807
+76147514928
88047952807
YES
NO
YES
*/
