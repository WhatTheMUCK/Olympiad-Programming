#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <sstream>
 
using namespace std;

typedef struct {
    string type;
    int width, height, dx, dy;
} image;

typedef struct {
    int start, end, height;
} info;

void pictureInformation(image picture){
    cout << "Информация о пикче: [type: " << picture.type << " width: " << picture.width << " height: " << picture.height << " dx: " << picture.dx << " dy: " << picture.dy << "]\n";
}

void updateLine(int& height, vector<info>& spoilage, pair<int, int>& currentPosition, int h){
    vector<info> newSpoilage;
    for (info elem : spoilage){
        elem.height -= height;
        if (elem.height > 0)
            newSpoilage.push_back(elem);
    }
    spoilage = newSpoilage;
    currentPosition = {0, currentPosition.second + height};
    height = h;
}

void updateParagraph(int& height, vector<info>& spoilage, pair<int, int>& currentPosition, int h){
    int maxHeight = 0;
    for (info elem : spoilage){
        if (elem.height > maxHeight){
            maxHeight = elem.height;
        }
    }
    maxHeight = max(maxHeight, height);
    spoilage = {};
    currentPosition = {0, currentPosition.second + maxHeight};
    height = h;
}

int findNewPositionToInsert(int& height, vector<info>& spoilage, pair<int, int>& currentPosition, int w, int h, int c, bool first, int& widthObject){
    bool insert = false, checked;
    int currentX = currentPosition.first;
    while (insert != true){
        checked = true;
        for (info elem : spoilage){
            if (!(currentX + widthObject <= elem.start || currentX >= elem.end)){
                checked = false;
                if (!first){
                    widthObject -= c;
                    first = true;
                }
                currentX = elem.end;
            }
        }
        if (currentX + widthObject > w){
            updateLine(height, spoilage, currentPosition, h);
            if (!first){
                widthObject -= c;
                first = true;
            }
            currentX = 0;
        } else if (checked) {
            insert = true;
            if (!first){
                widthObject -= c;
                currentX += c;
                first = true;
            }
        }
    }
    return currentX;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string in, type;
    int w, h, c, dx, dy;
    getline(cin, in);
    stringstream firstString(in);
    firstString >> w >> h >> c;
    // w - ширина страницы в пикселях
    // h - исходная высота строки
    // c - ширина каждого символа
    // Слово — это последовательность символов, состоящая из букв латинского алфавита, цифр, и знаков препинания: ".", ",", ":", ";", "!", "?", "-", "'".
    // Слово всегда "прижимается" к верхней границе строки.
    
    // Необходимо найти координаты x,y левого верхнего угла для каждого рисунка
    
    // Рисукон описывается: (image [image parameters])
    
    // Примеры всех вариантов описания рисунка:
    // (image layout=embedded width=12 height=5): 
    // embedded(в тексте) если рисунок не первый, то перед ним ставится пробел(c пикселей), если высота рисунка больше высоты текущей строки, то высота строки увеличивается до высоты рисунка
    
    // (image layout=surrounded width=25 height=58):
    // Находится фрагмент в котором рисунок помещается по ширине, пробел перед ним не ставится, верхний край совпадает с верхней гранью строки, а сам рисунок продолжается вниз и разбивает строки ниже на фрагменты, если пересекает
    
    // (image layout=floating dx=18 dy=-15 width=25 height=20)
    // Рисунок размещается поверх текста и других рисунков и никак с ними не взаимодействует
    // В этом случае у рисунка есть два дополнительных параметра: "dx" и "dy" — целые числа, задающие смещение в пикселях верхнего левого угла рисунка вправо и вниз, соответственно, 
    // относительно позиции, где находится верхний правый угол предыдущего слова или рисунка (или самой левой верхней точки первой строки абзаца, если рисунок — первый элемент абзаца).
    
    // Абзацы разделены пустой строкой
    // Строка, состоящая только из пробелов, считается пустой.
    image picture, empty;
    empty.type = ""; empty.width = 0; empty.height = 0; empty.dx = 0; empty.dy = 0;
    int notSpaces, currentHeight = 0, height = h, widthObject, newX;
    vector<info> spoilage;
    string temp, helper, pattern1 = "layout=", pattern2 = "width=", pattern3 = "height=", pattern4 = "dx=", pattern5 = "dy=";
    bool readImage = false, first = true;
    pair<int, int> currentPosition = {0, 0}, lastElem;
    while (getline(cin, in)){
        notSpaces = 0;
        for (int i = 0; i < in.size() && notSpaces == 0; i++){
            if (in[i] != ' ')
                notSpaces++;
        }
        stringstream input(in);
        if (notSpaces == 0){
            //Обновление абзаца
            updateParagraph(height, spoilage, currentPosition, h);
            lastElem = currentPosition;
            first = true;
            //cout << "\nНОВЫЙ АБЗАЦ\n";
        } else {
            // Обработка картинок и их влияния на документ
            while (input >> temp){
                if (temp[0] == '('){
                    readImage = true;
                    picture = empty;
                }
                    
                if (readImage == true){
                    // Считывание информации о картинке
                    if (temp.substr(0, pattern1.size()) == pattern1){
                        if (temp[temp.size() - 1] == ')')
                            helper = temp.substr(pattern1.size(), temp.size() - pattern1.size() - 1);
                        else
                            helper = temp.substr(pattern1.size(), temp.size() - pattern1.size());
                        picture.type = helper;
                    }
                    if (temp.substr(0, pattern2.size()) == pattern2){
                        if (temp[temp.size() - 1] == ')')
                            helper = temp.substr(pattern2.size(), temp.size() - pattern2.size() - 1);
                        else
                            helper = temp.substr(pattern2.size(), temp.size() - pattern2.size());
                        picture.width = stoi(helper);
                    }
                    if (temp.substr(0, pattern3.size()) == pattern3){
                        if (temp[temp.size() - 1] == ')')
                            helper = temp.substr(pattern3.size(), temp.size() - pattern3.size() - 1);
                        else
                            helper = temp.substr(pattern3.size(), temp.size() - pattern3.size());
                        picture.height = stoi(helper);
                    }
                    if (temp.substr(0, pattern4.size()) == pattern4){
                        if (temp[temp.size() - 1] == ')')
                            helper = temp.substr(pattern4.size(), temp.size() - pattern4.size() - 1);
                        else
                            helper = temp.substr(pattern4.size(), temp.size() - pattern4.size());
                        picture.dx = stoi(helper);
                    }
                    if (temp.substr(0, pattern5.size()) == pattern5){
                        if (temp[temp.size() - 1] == ')')
                            helper = temp.substr(pattern5.size(), temp.size() - pattern5.size() - 1);
                        else
                            helper = temp.substr(pattern5.size(), temp.size() - pattern5.size());
                        picture.dy = stoi(helper);
                    }
                    if (temp[temp.size() - 1] == ')'){
                        readImage = false;
                        if (picture.type == "floating"){
                            lastElem = {max(0, min(w - picture.width, lastElem.first + picture.dx)) + picture.width, lastElem.second + picture.dy};
                            cout << lastElem.first - picture.width << " " << lastElem.second << "\n";
                        }
                        if (picture.type == "embedded"){
                            if (first)
                                widthObject = picture.width;
                            else
                                widthObject = picture.width + c;
                            newX = findNewPositionToInsert(height, spoilage, currentPosition, w, h, c, first, widthObject);
                            cout << newX << " " << currentPosition.second << "\n";
                            currentPosition.first = newX + widthObject;
                            height = max(height, picture.height);
                            lastElem = currentPosition;
                            first = false;
                        }
                        if (picture.type == "surrounded"){
                            widthObject = picture.width;
                            first = true;
                            newX = findNewPositionToInsert(height, spoilage, currentPosition, w, h, c, first, widthObject);
                            cout << newX << " " << currentPosition.second << "\n";
                            currentPosition.first = newX + widthObject;
                            lastElem = currentPosition;
                            spoilage.push_back({newX, newX + picture.width, picture.height});
                        }
                        //pictureInformation(picture);
                        //cout << "Информация о пикче: [type: " << picture.type << " width: " << picture.width << " height: " << picture.height << " dx: " << picture.dx << " dy: " << picture.dy << "]\n";
                    }
                } else {
                    // Обработка текста
                    if (first)
                        widthObject = temp.size() * c;
                    else
                        widthObject = (temp.size() + 1) * c;
                    newX = findNewPositionToInsert(height, spoilage, currentPosition, w, h, c, first, widthObject);
                    //cout << newX << " " << currentPosition.second << "\n";
                    currentPosition.first = newX + widthObject;
                    lastElem = currentPosition;
                    first = false;
                    //cout << temp << "\n";
                }
            }
        }
    }
    
    
}
