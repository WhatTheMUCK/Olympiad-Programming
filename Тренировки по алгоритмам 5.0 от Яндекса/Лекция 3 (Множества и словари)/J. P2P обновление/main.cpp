#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <time.h> 

using namespace std;

struct info{
    int update, from;
};

bool operator== (const info& l, const info& r){
    return (l.update == r.update) && (l.from == r.from);
}

bool operator< (const info& l, const info& r) {
    if (l.update != r.update) 
        return l.update < r.update;
    return l.from < r.from;
}

namespace std{
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second) * 63;
        }
    };
    
    template <> struct hash<info> {
        inline size_t operator()(const info &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.update) ^ int_hasher(v.from) * 63;
        }
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double seconds1, seconds2, answer1 = 0, answer2 = 0;
    int n, k, breaker = 10, size, counter = 1, remaining, minAmountUpd, queryNumUpd, queryNumComputer, valuable;
    info accomplishment;
    cin >> n >> k;
    remaining = n * k - k; //Обновления отсутствуют у всех крому 1 компа
    vector<int> AmountComputersWithUpdate(k, 1);
    vector<int> AmountUpdatesOnComputer(n, 0);
    unordered_map<int, unordered_set<int>> updates;
    unordered_map<int, unordered_set<int>> ComputersWithUpdate;
    unordered_map<int, unordered_set<int>> remainingUpdates;
    unordered_map<int, unordered_set<info>> requests;
    unordered_map<int, unordered_map<int, int>> VIP;
    vector<pair<info, int>> requestsAccomplishment;
    unordered_map<int, int> timeslots;
    for (int i = 0; i < k; i++){
        updates[0].insert(i);
        ComputersWithUpdate[i].insert(0);
    }
    AmountUpdatesOnComputer[0] = k;
    for (int i = 1; i < n; i++){
        updates[i] = {};
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            VIP[i][j] = 0;
        }
    }
    remainingUpdates[0] = {};
    for (int i = 1; i < n; i++){
        for (int j = 0; j < k; j++){
            remainingUpdates[i].insert(j);
        }
    }
    while (remaining > 0){
        clock_t start1 = clock();
        requests = {};
        //Формирование запросов
        for (int i = 1; i < n; i++){
            if (updates[i].size() == k){
                continue;
            }
            minAmountUpd = n + 1;
            queryNumUpd = k + 1;
            //Нахождение номера обновления которое будут запрашивать
            for (int elem : remainingUpdates[i]){
                if (AmountComputersWithUpdate[elem] < minAmountUpd){
                    minAmountUpd = AmountComputersWithUpdate[elem];
                    queryNumUpd = elem;
                } else if (AmountComputersWithUpdate[elem] == minAmountUpd && elem < queryNumUpd){
                    queryNumUpd = elem;
                }
            }
            minAmountUpd = k + 1;
            queryNumComputer = n + 1;
            //Нахождение номера компьютера к которому будут обращаться
            // cout << "queryNumUpd: " << queryNumUpd << "\n";
            // for (int elem : ComputersWithUpdate[queryNumUpd]){
            //     cout << elem << " ";
            // }
            // cout << "\n";
            for (int elem : ComputersWithUpdate[queryNumUpd]){
                if (AmountUpdatesOnComputer[elem] < minAmountUpd){
                    minAmountUpd = AmountUpdatesOnComputer[elem] ;
                    queryNumComputer = elem;
                }
                else if (AmountUpdatesOnComputer[elem] == minAmountUpd && elem < queryNumComputer){
                    queryNumComputer = elem;
                }
            }
            //Создание запроса
            requests[queryNumComputer].insert({queryNumUpd, i});
        }
        clock_t end1 = clock();
        // cout << "\nЗАПРОСЫ:\n";
        // for (pair<int, unordered_set<info>> elem : requests){
        //     cout << "Кому: " << elem.first << ":\n";
        //     for (info inner : elem.second){
        //         cout << "Обновление: " << inner.update << " От кого: " << inner.from << "\n"; 
        //     }
        // }
        clock_t start2 = clock();
        requestsAccomplishment = {};
        //Выбор какой запрос удовлетворить для каждого устройства
        for (int i = 0; i < n; i++){
            valuable = -1;
            minAmountUpd = k + 1;
            accomplishment = {0, n + 1};
            for (info elem : requests[i]){
                if (VIP[i][elem.from] > valuable){
                    valuable = VIP[i][elem.from];
                    minAmountUpd = AmountUpdatesOnComputer[elem.from];
                    accomplishment = elem;
                } else if (VIP[i][elem.from] == valuable){
                    if (AmountUpdatesOnComputer[elem.from] < minAmountUpd){
                        minAmountUpd = AmountUpdatesOnComputer[elem.from];
                        accomplishment = elem;
                    } else if (AmountUpdatesOnComputer[elem.from] == minAmountUpd && elem.from < accomplishment.from){
                        accomplishment = elem;
                    }
                }
            }
            if (accomplishment.from < n + 1)
                requestsAccomplishment.push_back({accomplishment, i}); // {Запрос, Кто его выполнил}
        }
        clock_t end2 = clock();
        seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
        seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
        answer1 += seconds1;
        answer2 += seconds2;
        // cout << "\nВЫПОЛНЕННЫЕ ЗАПРОСЫ:\n";
        // for (pair<info, int> elem : requestsAccomplishment){
        //     cout << "Кому: " << elem.second << " Обновление: " << elem.first.update << "  Кого: " << elem.first.from << "\n";
        // }
        for (pair<info, int> elem : requestsAccomplishment){
            VIP[elem.first.from][elem.second]++;
            updates[elem.first.from].insert(elem.first.update);
            AmountComputersWithUpdate[elem.first.update]++;
            AmountUpdatesOnComputer[elem.first.from]++;
            ComputersWithUpdate[elem.first.update].insert(elem.first.from);
            remainingUpdates[elem.first.from].erase(elem.first.update);
            remaining--;
        }
        // cout << "\nОСТАЛОСЬ СКАЧАТЬ ОБНОВЛЕНИЙ ВСЕГО: " << remaining << "\n";
        // cout << "\nСКАЧАННЫЕ ОБНОВЛЕНИЯ:\n";
        // for (pair<int, unordered_set<int>> elem : updates){
        //     cout << "Кто: " << elem.first << "\nЧто скачано: ";
        //     for (int inner : elem.second){
        //         cout << inner << " ";
        //     }
        //     cout << "\n";
        // }
        for (int i = 1; i < n; i++){
            if (updates[i].size() == k && timeslots.find(i) == timeslots.end()){
                timeslots[i] = counter;
            }
        }
        counter++;
        //breaker--;
    }
    //cout << "\nКоличество ответов: " << timeslots.size() << "\n";
    for (int i = 1; i < n; i++){
        cout << timeslots[i] << " ";
    }
    // printf("1) The time: %f seconds\n", answer1);
    // printf("2) The time: %f seconds\n", answer2);
}
    

