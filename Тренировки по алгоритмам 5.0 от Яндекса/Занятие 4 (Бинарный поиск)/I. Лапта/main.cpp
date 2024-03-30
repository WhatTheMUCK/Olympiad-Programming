#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>

using namespace std;

const double EPS = 1e-4;
const double MAX_ANS = (double)1e3;

struct Player {
    int x, y, v;
    
    bool operator < (const Player& other) const {
        if (x != other.x)
            return x < other.x;
        else 
            return y < other.y;
    }
};

struct Point {
    double x, y;
};

pair<Point, Point> circlesIntersection(double x1, double y1, double r1, double x2, double y2, double r2, double p){
    double alpha = atan2(y2 - y1, x2 - x1); 
    double a, b, h, xh, yh;
    // a + b = p
    // h - перпендикуляр опущенный из точек пересечений на отрезок соединящий (x1, y1) и (x2, y2)
    // a = sqrt((xh - x1)^2 + (yh - y1)^2)
    // b = sqrt((xh - x2)^2 + (yh - y2)^2)
    b = (r2 * r2 - r1* r1 + p * p)/(2 * p);
    a = p - b;
    h = sqrt(r1 * r1 - a * a);
    xh = x1 + a * cos(alpha);
    yh = y1 + a * sin(alpha);
    double xans1, yans1;
    xans1 = xh + (y2 - y1)/p * h;
    yans1 = yh - (x2 - x1)/p * h;
    double xans2, yans2;
    xans2 = xh - (y2 - y1)/p * h;
    yans2 = yh + (x2 - x1)/p * h;
    return {{xans1, yans1}, {xans2, yans2}};
}

bool pointExist(Point intersection, const vector<Player>& players, int D, double timing){
    if (D - sqrt(intersection.x * intersection.x + intersection.y * intersection.y) >= -EPS && intersection.y >= -EPS){
        for (int i = 0; i < players.size(); i++){
            double diffx = (players[i].x - intersection.x);
            double diffy = (players[i].y - intersection.y);
            double timingSquare = (timing * timing);
            double speedSquare = (players[i].v * players[i].v);
            double distanceSquare = diffx * diffx + diffy * diffy;
            double comparisonSquare = timingSquare * speedSquare;
            //if (((players[i].x - intersection.x) * (players[i].x - intersection.x) + (players[i].y - intersection.y) * (players[i].y - intersection.y)) < (timing * timing) * (players[i].v * players[i].v)){
            if (timing - sqrt(distanceSquare)/players[i].v > EPS){    
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

bool Trytime(double timing, const vector<Player>& players, int D, Point& ans) {
    Point intersection1, intersection2;
    double x1, x2, y1, y2, r1, r2, p;
    for (int i = 0; i < players.size(); i++){
        x1 = players[i].x;
        y1 = players[i].y;
        r1 = players[i].v * timing;
        for (int j = i + 1; j < players.size(); j++){
            x2 = players[j].x;
            y2 = players[j].y;
            r2 = players[j].v * timing;
            p = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            if ((r1 + r2) - p >= EPS && p - (max(r1, r2) - min(r1, r2)) >= EPS){
                tie(intersection1, intersection2) = circlesIntersection(x1, y1, r1, x2, y2, r2, p);
                if (pointExist(intersection1, players, D, timing)){
                    ans = intersection1;
                    return true;
                } 
                if (pointExist(intersection2, players, D, timing)){
                    ans = intersection2;
                    return true;
                }
            }
        }
        x2 = 0;
        y2 = 0;
        r2 = D;
        if (x1 > x2 || (x1 == x2 && y1 > y2)){
            tie(x1, x2) = make_tuple(x2, x1);
            tie(y1, y2) = make_tuple(y2, y1);
            tie(r1, r2) = make_tuple(r2, r1);
        }
        p = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        if ((r1 + r2) - p >= EPS && p - (max(r1, r2) - min(r1, r2)) >= EPS){
            tie(intersection1, intersection2) = circlesIntersection(x1, y1, r1, x2, y2, r2, p);
            if (pointExist(intersection1, players, D, timing)){
                ans = intersection1;
                return true;
            } 
            if (pointExist(intersection2, players, D, timing)){
                ans = intersection2;
                return true;
            }
        }
    }
    if (pointExist({0, (double)D}, players, D, timing)){
        ans = {0, (double)D};
        return true;
    }
    return false;
    // ... Реализация функции Trytime
    // Возвращает true, если существует подходящая точка и помещает координаты в ans
    // Возвращает false, если такой точки нет
}

int main() {
    int D, N;
    cin >> D >> N;
    
    vector<Player> players(N);
    for (int i = 0; i < N; ++i) {
        cin >> players[i].x >> players[i].y >> players[i].v;
    }
    sort(players.begin(), players.end());
    // for (int i = 0; i < N; i++){
    //     cout << players[i].x << " " << players[i].y << " " << players[i].v << "\n";
    // }
    double l = 0, r = MAX_ANS, m;
    Point ans;
    
    while (r - l > 2 * EPS) {
        m = (l + r) / 2;
        if (Trytime(m, players, D, ans)) {
            l = m;
        } else {
            r = m;
        }
    }
    
    if (Trytime(l, players, D, ans)) {
        cout.precision(6);
        cout << fixed << m << " " << ans.x << " " << ans.y << endl;
    } else {
        // Обработка случая, когда нет подходящей точки
    }
    
    return 0;
}
