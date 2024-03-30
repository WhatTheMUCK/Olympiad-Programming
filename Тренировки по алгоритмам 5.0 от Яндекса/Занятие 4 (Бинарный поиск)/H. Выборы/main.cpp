#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>

using namespace std;

struct info {
    int people, cost, number;
    
    // bool operator<(const info& other) const {
    //     // Сортируем по стоимости, затем по числу людей
    //     if (cost == other.cost) {
    //         return people < other.people;
    //     }
    //     return cost < other.cost;
    // }
    
    // Перегрузка оператора < для сравнения по количеству людей
    bool operator<(const info& other) const {
        return people < other.people;
    }
    
    friend istream& operator>>(istream& is, info& i) {
        is >> i.people >> i.cost;
        i.number = 0; 
        return is;
    }
};


bool checkForLBS(long long m, int value) {
    return m > value;
}

int lBinarySearch(int l, int r, function<bool(long long, int)> check, vector<info>& parties, vector<long long>& peopletoEq){
    int m, position = r;
    while (r - l > 1){
        m = (l + r) / 2;
        if (check(peopletoEq[m] + parties[position].people, parties[m].people)){
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // fin.tie(0);
    // fout.tie(0);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    vector<info> parties(n);
    for (int i = 0; i < n; i++) {
        fin >> parties[i];
        parties[i].number = i + 1;
    }
    sort(parties.rbegin(), parties.rend());
    
    long long sum = 0, cursum;
    vector<long long> peopletoEq(n);
    for (int i = 0; i < n; i++){
        sum += parties[i].people;
        peopletoEq[i] = sum - 1ll * (i + 1ll) * parties[i].people;
    }
    // fout << "\ntotal:\n";
    // for (int i = 0; i < n; i++){
    //     fout << peopletoEq[i] << "\n";
    // }
    
    long long mincost = (long long)1e18, minI = -1, cost;
    long long pos, curPeople, different, whole, rest;
    for (int i = 0; i < n; i++){
        if (parties[i].cost > 0){
            cost = parties[i].cost;
            if (i == 0 && n > 1 && parties[1].people == parties[0].people){
                cost++;
            } else if (i != 0 && n > 1){
                pos = lBinarySearch(0, i, checkForLBS, parties, peopletoEq);
                curPeople = parties[i].people + peopletoEq[pos];
                different = parties[pos].people - curPeople;
                whole = different / ((pos + 1) + 1);
                rest = different % ((pos + 1) + 1);
                curPeople += whole * (pos + 1) + ((rest < (pos + 1)) ? (rest + 1) : (pos + 1));
                cost += curPeople - parties[i].people;
            }
            if (mincost > cost){
                mincost = cost;
                minI = i;
            }
        }
    }
    
    // fout << "\nmincost: " << mincost << " minI: " << minI << "\n";
    // for (int i = 0; i < n; i++){
    //     fout << "i: " << i << " people: " << parties[i].people << "\n";
    // }
    
    auto compareByNumber = [](const info& a, const info& b) {
        return a.number < b.number;
    };
    
    fout << mincost << "\n" << parties[minI].number << "\n";
    if (minI == 0){
        if (n > 1 && parties[0].people == parties[1].people){
            parties[0].people++;
            parties[1].people--;
        }
        
        // Сортировка parties по полю number
        sort(parties.begin(), parties.end(), compareByNumber);
        
        for (int i = 0; i < n; i++){
            fout << parties[i].people << " ";
        }
    } else {
        pos = lBinarySearch(0, minI, checkForLBS, parties, peopletoEq);
        different = parties[pos].people - (parties[minI].people + peopletoEq[pos]);
        whole = different / ((pos + 1) + 1);
        rest = different % ((pos + 1) + 1);
        rest = ((rest < (pos + 1)) ? (rest + 1) : (pos + 1));
        //fout << "\npos: " << pos << " rest: " << rest << " different: " << different <<" whole: " << whole << "\n\n";
        
        for (int i = 0; i <= pos; i++) {
            parties[i].people = parties[pos].people - whole;
        }
        for (int i = 0; i < rest; i++) {
            parties[i].people--;
        }
        parties[minI].people += mincost - parties[minI].cost;
        

        // Сортировка parties по полю number
        sort(parties.begin(), parties.end(), compareByNumber);
        
        for (int i = 0; i < n; i++){
            //fout << "i: " << i + 1 << " ";
            fout << parties[i].people << " ";
        }
    }
}
