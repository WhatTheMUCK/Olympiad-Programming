#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <tuple>

using namespace std;

#define EPS 1e-6

struct Point{
    double x, y;
};

struct figure{
    string type;
    vector<Point> vertexes;
    double h, hfull;
    double V;
};

struct forVertexes{
  int leftIndex, rightIndex;
};

tuple<double, double, double, double> binSearch(Point lStart, Point lEnd, Point rStart, Point rEnd, double V){
    double yl = lStart.y, yr = rEnd.y, ym, xl, xr, a = rStart.x - lStart.x, b, S; // a - нижнее основание трапеции, b - верхнее, S - площадь трапеции
    while (yr - yl > EPS){
        ym = (yl + yr)/2;
        xr = rStart.x + (ym - rStart.y) * (rEnd.x - rStart.x) / (rEnd.y - rStart.y);
        xl = lStart.x + (ym - lStart.y) * (lEnd.x - lStart.x) / (lEnd.y - lStart.y);
        b = xr - xl;
        S = (ym - lStart.y) * (a + b) / 2; // h = (ym - lStart.y) - высота трапеции
        if (V - S < EPS){
            yr = ym;
        } else {
            yl = ym;
        }
    }
    return make_tuple(yl, S, xl, xr); 
}

void printInfoAboutFigures(unordered_map<int, vector<figure>> polygonsOfVertex, vector<Point> vertex){
    for (pair<int, vector<figure>> tempPair : polygonsOfVertex){
        cout << "\nФигуры для вершины " << tempPair.first << " (" << vertex[tempPair.first].x << " ; " << vertex[tempPair.first].y << "):\n";
        for (figure elem : tempPair.second){
            cout << "-------------------------------------------------\n";
            cout << "тип: " << elem.type << "\n";
            cout << "точки: ";
            for (int i = 0 ; i < elem.vertexes.size(); i++){
                cout << "(" << elem.vertexes[i].x << " ; " << elem.vertexes[i].y << ") ";
            }
            cout << "\nвысота: " << elem.h << "\n";
            cout << "высота заполненная водой: " << elem.hfull << "\n";
            cout << "объём: " << elem.V << "\n";
        }
        cout << "-------------------------------------------------\n";
    }
}

int main(){
    int N;
    double H;
    cin >> N >> H;
    vector<Point> vertex(N + 3);
    for (int i = 1; i <= N + 1; i++){
        cin >> vertex[i].x >> vertex[i].y;
    }
    
    double Hmax = -1;
    
    //Объявление граничных точек (стен)
    vertex[0].x = vertex[1].x;              vertex[0].y = (double)1e15;
    vertex[N + 2].x = vertex[N + 1].x;      vertex[N + 2].y = (double)1e15;
    
    //Определение всех "вершин" и "низин"
    vector<int> topIndex = {0}, hollowIndex;
    unordered_map<long long, int> findTop;
    for (int i = 1; i <= N + 1; i++){
        if (vertex[i].y > vertex[i - 1].y && vertex[i].y > vertex[i + 1].y){
            topIndex.push_back(i);
            findTop[vertex[i].y] = i;
        }
        if (vertex[i].y < vertex[i - 1].y && vertex[i].y < vertex[i + 1].y){
            hollowIndex.push_back(i);
        }
    }
    topIndex.push_back(N + 2);
    
    // cout << "Низины:\n";
    // for (int i = 0; i < hollowIndex.size(); i++){
    //     cout << hollowIndex[i] << "\n";
    // }
    
    // cout << "Вершины:\n";
    // for (int i = 0; i < topIndex.size(); i++){
    //     cout << topIndex[i] << "\n";
    // }
    
    //Множество появившихся точек из-за разбиения на фигуры
    unordered_map<int, vector<double>> xNew; // xNew[y] хранит координаты x, новых точек на высоте y (максимум 2 штуки)
    unordered_map<double, int> next; //next[x] хранит индекс следующей вершины (имеющей большую координату по y) для новоиспечённой вершины (x, y)
    
    unordered_map<int, vector<figure>> polygonsOfVertex;
    bool end, zeroFigures;
    int start;
    int l, r;
    figure tempPoly;
    pair<Point, Point> prevVertexes;
    //Определение фигур принадлежащих "низинам"
    for (int i = 0; i < hollowIndex.size(); i++){
        start = hollowIndex[i];
        l = start - 1; 
        r = start + 1;
        end = false;
        zeroFigures = true;
        while(!end){
            tempPoly = {};
            if (vertex[l].y < vertex[r].y){
                // Определение точки на наклонной
                double tempX = vertex[r - 1].x + (vertex[l].y - vertex[r - 1].y) * (vertex[r].x - vertex[r - 1].x) / (vertex[r].y - vertex[r - 1].y);
                //
                if (xNew.find(vertex[l].y) == xNew.end()){
                    xNew[vertex[l].y] = {tempX};
                } else {
                    xNew[vertex[l].y].push_back(tempX);
                }
                
                next[tempX] = r;
                if (zeroFigures){
                    //-------------------------------------------------
                    tempPoly.type = "triangle";
                    //
                    tempPoly.vertexes.push_back(vertex[start]);
                    tempPoly.vertexes.push_back(vertex[l]);
                    tempPoly.vertexes.push_back({tempX, vertex[l].y});
                    //
                    tempPoly.h = vertex[l].y - vertex[start].y;
                    tempPoly.hfull = 0;
                    //
                    tempPoly.V = tempPoly.h * (tempX - vertex[l].x) / 2;
                    //-------------------------------------------------
                    if (polygonsOfVertex.find(start) ==  polygonsOfVertex.end()){
                        polygonsOfVertex[start] = {tempPoly};
                    } else {
                        polygonsOfVertex[start].push_back(tempPoly);
                    }
                    //
                    zeroFigures = false;
                } else {
                    //-------------------------------------------------
                    tempPoly.type = "trapezoid";
                    //
                    tempPoly.vertexes.push_back(prevVertexes.first);
                    tempPoly.vertexes.push_back(prevVertexes.second);
                    tempPoly.vertexes.push_back(vertex[l]);
                    tempPoly.vertexes.push_back({tempX, vertex[l].y});
                    //
                    tempPoly.h = vertex[l].y - prevVertexes.second.y;
                    tempPoly.hfull = 0;
                    //
                    tempPoly.V = tempPoly.h * ((prevVertexes.first.x - prevVertexes.second.x) + (tempX - vertex[l].x)) / 2;
                    //-------------------------------------------------
                    if (polygonsOfVertex.find(start) ==  polygonsOfVertex.end()){
                        polygonsOfVertex[start] = {tempPoly};
                    } else {
                        polygonsOfVertex[start].push_back(tempPoly);
                    }
                }
                prevVertexes = {{tempX, vertex[l].y}, vertex[l]};
                if (findTop.find(vertex[l].y) != findTop.end() || l == 0){
                    end = true;
                }
                l--;
            } else {
                // Определение точки на наклонной
                double tempX = vertex[l + 1].x + (vertex[r].y - vertex[l + 1].y) * (vertex[l].x - vertex[l + 1].x) / (vertex[l].y - vertex[l + 1].y);
                //
                if (xNew.find(vertex[r].y) ==  xNew.end()){
                    xNew[vertex[r].y] = {tempX};
                    //cout << xNew[vertex[r].y][0] << "\n";
                } else {
                    xNew[vertex[r].y].push_back(tempX);
                }
                next[tempX] = l;
                if (zeroFigures){
                    //-------------------------------------------------
                    tempPoly.type = "triangle";
                    //
                    tempPoly.vertexes.push_back(vertex[start]);
                    tempPoly.vertexes.push_back({tempX, vertex[r].y});
                    tempPoly.vertexes.push_back(vertex[r]);
                    //
                    tempPoly.h = vertex[r].y - vertex[start].y;
                    tempPoly.hfull = 0;
                    //
                    tempPoly.V = tempPoly.h * (vertex[r].x - tempX) / 2;
                    //-------------------------------------------------
                    if (polygonsOfVertex.find(start) ==  polygonsOfVertex.end()){
                        polygonsOfVertex[start] = {tempPoly};
                    } else {
                        polygonsOfVertex[start].push_back(tempPoly);
                    }
                    //
                    zeroFigures = false;
                } else {
                    //-------------------------------------------------
                    tempPoly.type = "trapezoid";
                    //
                    tempPoly.vertexes.push_back(prevVertexes.first);
                    tempPoly.vertexes.push_back(prevVertexes.second);
                    tempPoly.vertexes.push_back({tempX, vertex[r].y});
                    tempPoly.vertexes.push_back(vertex[r]);
                    //
                    tempPoly.h = vertex[r].y - prevVertexes.first.y;
                    tempPoly.hfull = 0;
                    //
                    tempPoly.V = tempPoly.h * ((prevVertexes.first.x - prevVertexes.second.x) + (vertex[r].x - tempX)) / 2;
                    //-------------------------------------------------
                    if (polygonsOfVertex.find(start) ==  polygonsOfVertex.end()){
                        polygonsOfVertex[start] = {tempPoly};
                    } else {
                        polygonsOfVertex[start].push_back(tempPoly);
                    }
                }
                prevVertexes = {vertex[r], {tempX, vertex[r].y}};
                if (findTop.find(vertex[r].y) != findTop.end() || r == N + 2){
                    end = true;
                }
                r++;
            }
        }
    }
    
    
    vector<pair<int, int>> topIndexSortY;
    for (int i = 1; i < topIndex.size() - 1; i++){
        topIndexSortY.push_back({vertex[topIndex[i]].y, topIndex[i]});
    }
    sort(topIndexSortY.begin(), topIndexSortY.end());
    
    //Определение фигур принадлежащих "вершинам" (top)
    //кроме самой первой и последней
    for (int i = 0; i < topIndexSortY.size(); i++){
        start = topIndexSortY[i].second;
        //Вершины (top) всегда продлевались влево и вправо из-за низин и предшествующих им вершинам (top)
        // cout << "i: " << i << " start: " << start << " y: " << vertex[start].y;
        // cout << " x1: " << xNew[vertex[start].y][0] << " x2: " << xNew[vertex[start].y][1] << "\n";
        double xl = min(xNew[vertex[start].y][0], xNew[vertex[start].y][1]);
        double xr = max(xNew[vertex[start].y][0], xNew[vertex[start].y][1]);
        prevVertexes = {{xr, vertex[start].y}, {xl, vertex[start].y}};
        l = next[xl];
        r = next[xr];
        end = false;
        while (!end){
            tempPoly = {};
            if (vertex[l].y < vertex[r].y){
                // Определение точки на наклонной
                double tempX = vertex[r - 1].x + (vertex[l].y - vertex[r - 1].y) * (vertex[r].x - vertex[r - 1].x) / (vertex[r].y - vertex[r - 1].y);
                //
                if (xNew.find(vertex[l].y) == xNew.end()){
                    xNew[vertex[l].y] = {tempX};
                } else {
                    xNew[vertex[l].y].push_back(tempX);
                }
                next[tempX] = r;
                
                //Описание фигуры что мы нашли
                //-------------------------------------------------
                tempPoly.type = "trapezoid";
                //
                tempPoly.vertexes.push_back(prevVertexes.first);
                tempPoly.vertexes.push_back(prevVertexes.second);
                tempPoly.vertexes.push_back(vertex[l]);
                tempPoly.vertexes.push_back({tempX, vertex[l].y});
                //
                tempPoly.h = vertex[l].y - prevVertexes.second.y;
                tempPoly.hfull = 0;
                //
                tempPoly.V = tempPoly.h * ((prevVertexes.first.x - prevVertexes.second.x) + (tempX - vertex[l].x)) / 2;
                //-------------------------------------------------
                if (polygonsOfVertex.find(start) ==  polygonsOfVertex.end()){
                    polygonsOfVertex[start] = {tempPoly};
                } else {
                    polygonsOfVertex[start].push_back(tempPoly);
                }
                
                prevVertexes = {{tempX, vertex[l].y}, vertex[l]};
                if (findTop.find(vertex[l].y) != findTop.end() || l == 0){
                    end = true;
                }
                l--;
            } else {
                // Определение точки на наклонной
                double tempX = vertex[l + 1].x + (vertex[r].y - vertex[l + 1].y) * (vertex[l].x - vertex[l + 1].x) / (vertex[l].y - vertex[l + 1].y);
                //
                if (xNew.find(vertex[r].y) == xNew.end()){
                    xNew[vertex[r].y] = {tempX};
                } else {
                    xNew[vertex[r].y].push_back(tempX);
                }
                next[tempX] = l;
                
                //Описание фигуры что мы нашли
                //-------------------------------------------------
                tempPoly.type = "trapezoid";
                //
                tempPoly.vertexes.push_back(prevVertexes.first);
                tempPoly.vertexes.push_back(prevVertexes.second);
                tempPoly.vertexes.push_back({tempX, vertex[r].y});
                tempPoly.vertexes.push_back(vertex[r]);
                //
                tempPoly.h = vertex[r].y - prevVertexes.first.y;
                tempPoly.hfull = 0;
                //
                tempPoly.V = tempPoly.h * ((prevVertexes.first.x - prevVertexes.second.x) + (vertex[r].x - tempX)) / 2;
                //-------------------------------------------------
                if (polygonsOfVertex.find(start) ==  polygonsOfVertex.end()){
                    polygonsOfVertex[start] = {tempPoly};
                } else {
                    polygonsOfVertex[start].push_back(tempPoly);
                }
                
                prevVertexes = {vertex[r], {tempX, vertex[r].y}};
                if (findTop.find(vertex[r].y) != findTop.end() || r == N + 2){
                    end = true;
                }
                r++;
            }
        }
    }
    
    //Информация о фигурах которые получились для каждой из вершин
    //printInfoAboutFigures(polygonsOfVertex, vertex);
    
    //Для каждой низины найдём вершины (top) между которыми они заключены
    unordered_map<int, forVertexes> helperForHollow, helperForTop;
    int ind = 0;
    //Выемки образованные низинами находятся между 2 соседними вершинами
    for (int i = 1; i < topIndex.size(); i++){
        if (vertex[hollowIndex[ind]].x >= vertex[topIndex[i - 1]].x && vertex[hollowIndex[ind]].x <= vertex[topIndex[i]].x){
            helperForHollow[hollowIndex[ind]] = {topIndex[i - 1], topIndex[i]};
            ind++;
        }
    }
    
    //Выемки образованные "вершинами" (top) ("вершина" между двумя другими)
    for (int i = 1; i < topIndex.size() - 1; i++){
        int l = i - 1, r = i + 1;
        while(vertex[topIndex[l]].y < vertex[topIndex[i]].y){
            l--;
        }
        while(vertex[topIndex[r]].y < vertex[topIndex[i]].y){
            r++;
        }
        helperForHollow[topIndex[i]] = {topIndex[l], topIndex[r]};
    }
    
    ind = 1;
    for (int i = 1; i < hollowIndex.size(); i++){
        if (vertex[topIndex[ind]].x > vertex[hollowIndex[i - 1]].x && vertex[topIndex[ind]].x < vertex[hollowIndex[i]].x){
            helperForTop[topIndex[ind]] = {hollowIndex[i - 1], hollowIndex[i]};
            ind++;
        }
    }
    
    // cout << "\nHollow:\n";
    // for (pair<int, forVertexes> elem : helperForHollow){
    //     cout << elem.first << " " << elem.second.leftIndex << " " << elem.second.rightIndex << "\n";
    // }
    
    // cout << "\nTop:\n";
    // for (pair<int, forVertexes> elem : helperForTop){
    //     cout << elem.first << " " << elem.second.leftIndex << " " << elem.second.rightIndex << "\n";
    // }
    //cout << "\nДО:\n";
    //printInfoAboutFigures(polygonsOfVertex, vertex);
    
    double Vprev = 0;
    unordered_map<int, double> Vrest, HeightOfVertex;
    vector<int> needToCheck, newNeedToCheck; //Вершины которые надо проверить и что-то сделать с водой // newNeedToCHeck нужен будет для того чтобы обновлять needToCHeck
    for (int i = 0; i < hollowIndex.size(); i++){
        Vrest[hollowIndex[i]] = (vertex[helperForHollow[hollowIndex[i]].rightIndex].x - vertex[helperForHollow[hollowIndex[i]].leftIndex].x) * H;
        needToCheck.push_back(hollowIndex[i]);
        HeightOfVertex[hollowIndex[i]] = 0;
    }

    // for (pair <int, double> elem : Vrest){
    //     cout << elem.first << " V: " << elem.second << "\n";
    // }
    
    double tempH;
    
    bool reverseTransfusion = true; 
    while (reverseTransfusion){
        reverseTransfusion = false; // Каждый раз будем переливать всё в право, потом влево и при переливании влево будем проверять не нужно ли нам вернуться направо
        //Если нужно вернуться, то надо захватить фигуры вершины разделяющей замкнутые впадины (впадина - либо низина, либо объединение низин с "вершиной" (top))
        
        newNeedToCheck = needToCheck;
        
        //Переливания слева направо без возвратов
        for (int i = 0; i < needToCheck.size(); i++){
            tempH = 0;
            if (Vrest[needToCheck[i]] > EPS){ //Если нечего заливать, то и нечего проверять
                for (int j = 0; j < polygonsOfVertex[needToCheck[i]].size(); j++){
                    double Vtemp = polygonsOfVertex[needToCheck[i]][j].V;
                    if (Vtemp <= EPS){ //Если фигура уже была заполнена, то надо переходить к следующей и искать первую незаполненную фигуру
                        continue;
                    }
                    if (Vrest[needToCheck[i]] - Vtemp >= -EPS){
                        Vrest[needToCheck[i]] -= Vtemp;
                        polygonsOfVertex[needToCheck[i]][j].V = 0;
                        polygonsOfVertex[needToCheck[i]][j].hfull = polygonsOfVertex[needToCheck[i]][j].h;
                        tempH += polygonsOfVertex[needToCheck[i]][j].hfull;
                        HeightOfVertex[needToCheck[i]] = max(HeightOfVertex[needToCheck[i]], tempH);
                        
                    } else {
                        Point lStart, lEnd, rStart, rEnd; //Точки расположены в обходе с правой нижней по правую верхнюю по часовой стрелке
                        if (polygonsOfVertex[needToCheck[i]][j].vertexes.size() == 3){ //Не тронутый треугольник
                            lStart = polygonsOfVertex[needToCheck[i]][j].vertexes[0];
                            rStart = polygonsOfVertex[needToCheck[i]][j].vertexes[0];
                            lEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[1];
                            rEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[2];
                        } else if (polygonsOfVertex[needToCheck[i]][j].vertexes.size() == 4) { // Не тронутая трапеция
                            rStart = polygonsOfVertex[needToCheck[i]][j].vertexes[0];
                            lStart = polygonsOfVertex[needToCheck[i]][j].vertexes[1];
                            lEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[2];
                            rEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[3];
                        } else { //Частично заполненная фигура (либо треугольник, либо трапеция, но в любом случае оставшаяся часть - трапеция с 2 новыми точками)
                            rStart = polygonsOfVertex[needToCheck[i]][j].vertexes[5];
                            lStart = polygonsOfVertex[needToCheck[i]][j].vertexes[4];
                            lEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[2];
                            rEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[3];
                        }
                        // Бинпоиск высоты столба жидкости
                        double ytemp, minusV, xlTemp, xrTemp;
                        tie(ytemp, minusV, xlTemp, xrTemp) = binSearch(lStart, lEnd, rStart, rEnd, Vrest[needToCheck[i]]);
                        if (polygonsOfVertex[needToCheck[i]][j].vertexes.size() > 4){ // Если фигура уже была частично заполнена, то забываем последние 2 точки и запоминаем новые 2
                            polygonsOfVertex[needToCheck[i]][j].vertexes.pop_back();
                            polygonsOfVertex[needToCheck[i]][j].vertexes.pop_back();
                        }
                        polygonsOfVertex[needToCheck[i]][j].vertexes.push_back({xlTemp, ytemp});
                        polygonsOfVertex[needToCheck[i]][j].vertexes.push_back({xrTemp, ytemp});
                        Vrest[needToCheck[i]] = 0;
                        polygonsOfVertex[needToCheck[i]][j].V -= minusV;
                        polygonsOfVertex[needToCheck[i]][j].hfull += ytemp - lStart.y;
                        tempH += polygonsOfVertex[needToCheck[i]][j].hfull;
                        HeightOfVertex[needToCheck[i]] = max(HeightOfVertex[needToCheck[i]], tempH);
                    }    
                }
                
                if (Vrest[needToCheck[i]] > EPS){
                    //Переливание вправо
                    if (vertex[helperForHollow[needToCheck[i]].rightIndex].y < vertex[helperForHollow[needToCheck[i]].leftIndex].y && i < needToCheck.size() - 1){
                        Vrest[needToCheck[i + 1]] += Vrest[needToCheck[i]]; //Отдаём оставшийся объём правой впадине
                        Vrest[needToCheck[i]] = 0;
                    } else {
                        //Оставшийся объём воды останется за низиной которую мы только что рассматривали
                    }
                }
            }
        }
        //
        
        //Переливание справа налево с возвратами
        for (int i = needToCheck.size() - 1; i >= 0; i--){
            tempH = 0;
            if (Vrest[needToCheck[i]] > EPS){ //Если нечего заливать, то и неченого проверять
                for (int j = 0; j < polygonsOfVertex[needToCheck[i]].size(); j++){
                    double Vtemp = polygonsOfVertex[needToCheck[i]][j].V;
                    if (Vtemp <= EPS){ //Если фигура уже была заполнена, то надо переходить к следующей и искать первую незаполненную фигуру
                        continue;
                    }
                    if (Vrest[needToCheck[i]] - Vtemp >= -EPS){
                            Vrest[needToCheck[i]] -= Vtemp;
                            polygonsOfVertex[needToCheck[i]][j].V = 0;
                            polygonsOfVertex[needToCheck[i]][j].hfull = polygonsOfVertex[needToCheck[i]][j].h;
                            tempH += polygonsOfVertex[needToCheck[i]][j].hfull;
                            HeightOfVertex[needToCheck[i]] = max(HeightOfVertex[needToCheck[i]], tempH);
                    } else {
                        Point lStart, lEnd, rStart, rEnd; //Точки расположены в обходе с правой нижней по правую верхнюю по часовой стрелке
                        if (polygonsOfVertex[needToCheck[i]][j].vertexes.size() == 3){ //Не тронутый треугольник (Но в этом кейсе её как будто нет)
                            lStart = polygonsOfVertex[needToCheck[i]][j].vertexes[0];
                            rStart = polygonsOfVertex[needToCheck[i]][j].vertexes[0];
                            lEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[1];
                            rEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[2];
                        } else if (polygonsOfVertex[needToCheck[i]][j].vertexes.size() == 4) { // Не тронутая трапеция
                            rStart = polygonsOfVertex[needToCheck[i]][j].vertexes[0];
                            lStart = polygonsOfVertex[needToCheck[i]][j].vertexes[1];
                            lEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[2];
                            rEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[3];
                        } else { //Частично заполненная фигура (либо треугольник, либо трапеция, но в любом случае оставшаяся часть - трапеция с 2 новыми точками)
                            rStart = polygonsOfVertex[needToCheck[i]][j].vertexes[5];
                            lStart = polygonsOfVertex[needToCheck[i]][j].vertexes[4];
                            lEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[2];
                            rEnd = polygonsOfVertex[needToCheck[i]][j].vertexes[3];
                        }
                        // Бинпоиск высоты столба жидкости
                        double ytemp, minusV, xlTemp, xrTemp;
                        tie(ytemp, minusV, xlTemp, xrTemp) = binSearch(lStart, lEnd, rStart, rEnd, Vrest[needToCheck[i]]);
                        if (polygonsOfVertex[needToCheck[i]][j].vertexes.size() > 4){ // Если фигура уже была частично заполнена, то забываем последние 2 точки и запоминаем новые 2
                            polygonsOfVertex[needToCheck[i]][j].vertexes.pop_back();
                            polygonsOfVertex[needToCheck[i]][j].vertexes.pop_back();
                        }
                        polygonsOfVertex[needToCheck[i]][j].vertexes.push_back({xlTemp, ytemp});
                        polygonsOfVertex[needToCheck[i]][j].vertexes.push_back({xrTemp, ytemp});
                        Vrest[needToCheck[i]] = 0;
                        polygonsOfVertex[needToCheck[i]][j].V -= minusV;
                        polygonsOfVertex[needToCheck[i]][j].hfull += ytemp - lStart.y;
                        tempH += polygonsOfVertex[needToCheck[i]][j].hfull;
                        HeightOfVertex[needToCheck[i]] = max(HeightOfVertex[needToCheck[i]], tempH);
                    }    
                }
            }
            
            if (Vrest[needToCheck[i]] > EPS){
                //Переливание влево
                if (vertex[helperForHollow[needToCheck[i]].leftIndex].y < vertex[helperForHollow[needToCheck[i]].rightIndex].y && i > 0){
                    Vrest[needToCheck[i - 1]] += Vrest[needToCheck[i]]; //Отдаём оставшийся объём левой впадине
                    Vrest[needToCheck[i]] = 0;
                } else if (vertex[helperForHollow[needToCheck[i]].leftIndex].y > vertex[helperForHollow[needToCheck[i]].rightIndex].y || i == 0){
                    //Сливаемся так как при первом проходе вправо все лишние столбики ушли в правые низини и при проходе влево если мы упираемся, то значит нам надо делать откат
                    //И захватывать области вершин (top)
                    reverseTransfusion = true; //Происходит обратное переливание
                    
                    Vrest[helperForHollow[needToCheck[i]].rightIndex] = Vrest[needToCheck[i]];
                    Vrest[needToCheck[i]] = 0;
                    newNeedToCheck[i] = helperForHollow[needToCheck[i]].rightIndex; //Заменили левую впадину на вершину
                    newNeedToCheck.erase(newNeedToCheck.begin() + (i + 1)); //Удалили правую впадину из рассмотрения
                    //Таким образов в newNeedToCheck будут хранить верхние вершины отвечающие за впадины
                    
                    HeightOfVertex[helperForHollow[needToCheck[i]].rightIndex] = max(HeightOfVertex[needToCheck[i]], HeightOfVertex[needToCheck[i + 1]]);
                }
            }
        }
        
        needToCheck = newNeedToCheck;
    }
    
    //cout << "\nПОСЛЕ:\n";
    //printInfoAboutFigures(polygonsOfVertex, vertex);
    
    unordered_map<int, vector<figure>> connectionPolygonsWithHollow;
    Point left, right, tempLeft, tempRight;
    for (int i = 0; i < hollowIndex.size(); i++){
        left = polygonsOfVertex[hollowIndex[i]][0].vertexes[1];
        right = polygonsOfVertex[hollowIndex[i]][0].vertexes[2];
        connectionPolygonsWithHollow[hollowIndex[i]].push_back(polygonsOfVertex[hollowIndex[i]][0]);
        for (int j = 0; j < polygonsOfVertex.size(); j++){
            for (int k = 0; k < polygonsOfVertex[j].size(); k++){
                if (polygonsOfVertex[j][k].type == "trapezoid"){
                    tempRight = polygonsOfVertex[j][k].vertexes[0];
                    tempLeft = polygonsOfVertex[j][k].vertexes[1];
                    if (left.x >= tempLeft.x && right.x <= tempRight.x && left.y <= tempLeft.y){
                        connectionPolygonsWithHollow[hollowIndex[i]].push_back(polygonsOfVertex[j][k]);
                    }
                }
            }
        }
    }
    
    
    for (int i = 0; i < connectionPolygonsWithHollow.size(); i++){
        tempH = 0;
        for (int j = 0; j < connectionPolygonsWithHollow[i].size(); j++){
            tempH += connectionPolygonsWithHollow[i][j].hfull;
        }
        Hmax = max(Hmax, tempH);
    }
    
    //cout << "Ответ:\n";
    cout << setprecision(20) << Hmax << "\n";
    // cout << "\n";
    // for (pair <int, double> elem : Vrest){
    //     cout << elem.first << " V: " << elem.second << "\n";
    // }
    
    // for (pair<int, double> elem : HeightOfVertex){
    //     Hmax = max(Hmax, elem.second);
    // }
    // cout << Hmax;
    
    // cout << "\nПОСЛЕ:\n";
    // printInfoAboutFigures(polygonsOfVertex, vertex);
    
    // for (pair <int, double> elem : Vrest){
    //     cout << elem.first << " V: " << elem.second << "\n";
    // }
}







