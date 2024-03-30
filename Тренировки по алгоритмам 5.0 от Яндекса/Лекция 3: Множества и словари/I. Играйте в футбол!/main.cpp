#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <fstream>

using namespace std;

//ofstream cout("cout1");

namespace std{
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second) * 63;
        }
    };
}

struct info {
    int total, matches, opens;
    
    info() : total(0), matches(0), opens(0) {}  // Конструктор по умолчанию

    info(int t, int m, int o) : total(t), matches(m), opens(o) {}

    info& operator+=(const info& other) {
        total += other.total;
        matches += other.matches;
        opens += other.opens;
        return *this;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const info& info) {
        os << info.total << " " << info.matches << " " << info.opens;
        return os;
    }
};

void PrintComandPlayersInfo(unordered_map<string, unordered_map<string, info>> ComandPlayersInfo){
    // unordered_map<string, unordered_map<string, info>> ComandPlayersInfo;
    cout << "\nComandPlayersInfo:\n";
    for (pair<string, unordered_map<string, info>> comand : ComandPlayersInfo){
        cout << comand.first << ":\n";
        for (pair<string, info> player : comand.second){
            cout << player.first << ": " << player.second << "\n";
        }
    }
}

void PrintComandsInfo(unordered_map<string, info> ComandsInfo){
    // unordered_map<string, info> ComandsInfo;
    cout << "\nComandsInfo:\n";
    for (pair<string, info> comand : ComandsInfo){
        cout << comand.first << " " << comand.second << "\n";
    }
}

void PrintConnectionPlayerTeam(unordered_map<string, string> ConnectionPlayerTeam){
    // unordered_map<string, string> ConnectionPlayerTeam;
    cout << "\nConnectionPlayerTeam:\n";
    for (pair<string, string> connection : ConnectionPlayerTeam){
        cout << connection.first << " - " << connection.second << "\n";
    }
}

string QuoteRemover(string in){
    string help = "";
    for (int i = 0; i < in.size(); i++){
        in[i] == '"' ? help = help : help += in[i];
    }
    return help;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // fstream cin("input");
    // fstream cin1("answer");
    string in, helper, comand1, comand2, comand, name, tempName;
    vector<string> helpMinutes;
    int goals, goals1, goals2, minute, minimumTime;
    unordered_map<string, unordered_map<string, info>> ComandPlayersInfo;
    unordered_map<string, string> ConnectionPlayerTeam;
    unordered_map<string, info> ComandsInfo;
    unordered_map<string, vector<int>> TimeGoals;
    while (getline(cin, in)){
        //"<Название 1-й команды>" - "<Название 2-й команды>" <Счет 1-й команды>:<Счет 2-й команды>
        //"abc" - "abcd" 12:3
        helper = in;
        if (in[0] == '"'){
            vector<int> separators;
            for (int i = 1; i < in.size(); i++){
                if (in[i] == '"' || in[i] == ':'){
                    separators.push_back(i);
                }
            }
            comand1 = in.substr(0, separators[0] + 1);
            comand2 = in.substr(separators[1], separators[2] - separators[1] + 1);
            goals1 = stoi(in.substr(separators[2] + 2, separators[3] - (separators[2] + 2)));
            goals2 = stoi(in.substr(separators[3] + 1, in.size() - (separators[3] + 1)));
            //cout << comand1 << " " << comand2 << " " << goals1 << " " << goals2;
            ComandsInfo.find(comand1) == ComandsInfo.end() ? ComandsInfo[comand1] = info(goals1, 1, 0) : ComandsInfo[comand1] += info(goals1, 1, 0);
            ComandsInfo.find(comand2) == ComandsInfo.end() ? ComandsInfo[comand2] = info(goals2, 1, 0) : ComandsInfo[comand2] += info(goals2, 1, 0);
            
            ComandPlayersInfo.find(comand1) == ComandPlayersInfo.end() ? ComandPlayersInfo[comand1] = {} : ComandPlayersInfo[comand1] = ComandPlayersInfo[comand1];
            ComandPlayersInfo.find(comand2) == ComandPlayersInfo.end() ? ComandPlayersInfo[comand2] = {} : ComandPlayersInfo[comand2] = ComandPlayersInfo[comand2];
            
            minimumTime = 91;
            tempName = "";
            helpMinutes = {};
            for (int i = 0; i < goals1 + goals2; i++){
                getline(cin, in);
                helpMinutes.push_back(in);
                int j;
                for (j = in.size() - 1; j > 0 && in[j] != ' '; j--);
                    name = in.substr(0, j);
                    minute = stoi(in.substr(j + 1, in.size() - (j + 1)));
                    //cout << name << " " << minute << "\n";
                    if (minimumTime > minute){
                        minimumTime = minute;
                        tempName = name;
                    }
                    if (i < goals1){
                        //Матчи хранятся не у игроков, а у команд, у игроков это лишняя информация!!!
                        ComandPlayersInfo[comand1].find(name) == ComandPlayersInfo[comand1].end() ? ComandPlayersInfo[comand1][name] = {1, 0, 0} : ComandPlayersInfo[comand1][name] += info(1, 0, 0);
                        
                        ConnectionPlayerTeam.find(name) == ConnectionPlayerTeam.end() ? ConnectionPlayerTeam[name] = comand1 : ConnectionPlayerTeam[name] = ConnectionPlayerTeam[name];
                        
                    } else {
                        ComandPlayersInfo[comand2].find(name) == ComandPlayersInfo[comand2].end() ? ComandPlayersInfo[comand2][name] = {1, 0, 0} : ComandPlayersInfo[comand2][name] += info(1, 0, 0);
                        
                        ConnectionPlayerTeam.find(name) == ConnectionPlayerTeam.end() ? ConnectionPlayerTeam[name] = comand2 : ConnectionPlayerTeam[name] = ConnectionPlayerTeam[name];
                    }
                    
                    if (TimeGoals.find(name) == TimeGoals.end()) {
                        TimeGoals[name] = vector<int>(90, 0);
                        TimeGoals[name][minute - 1]++;
                    } else {
                        TimeGoals[name][minute - 1]++;
                    }
                }
                if (goals1 + goals2){
                    ComandsInfo[ConnectionPlayerTeam[tempName]] += info(0, 0, 1);
                    ComandPlayersInfo[ConnectionPlayerTeam[tempName]][tempName] += info(0, 0, 1);
                }
                // name = '"' + string("V YxXkKv p dR Do XG ltrEIyhLeu") + '"';
                // if (comand1 == name || comand2 == name){
                //     cout << helper << "\n";
                //     for (int i = 0; i < helpMinutes.size(); i++){
                //         cout << helpMinutes[i] << "\n";
                //     }
                //     cout << "\nUPDATE:\n";
                //     cout << "ComandPlayersInfo:\n";
                //     for (pair<string, info> player : ComandPlayersInfo[name]){
                //         cout << player.first << " " << player.second << "\n"; 
                //     }
                //     cout << "\nComandsInfo:\n" << ComandsInfo[name] << "\n\n";
                //     // PrintComandPlayersInfo(ComandPlayersInfo);
                //     PrintConnectionPlayerTeam(ConnectionPlayerTeam);
                //     cout << "\n";
                //     // PrintComandsInfo(ComandsInfo);
                // }
        } 
        else {
            //cout << in << "\n";
            // Total goals for <Название команды>
            // — количество голов, забитое данной командой за все матчи.
            if (in.substr(0, string("Total goals for").size()) == "Total goals for"){
                comand = in.substr(string("Total goals for").size() + 1, in.size() - (string("Total goals for").size() + 1));
                //cout << "Total1: ";
                if (ComandsInfo.find(comand) != ComandsInfo.end()){
                    cout << ComandsInfo[comand].total << "\n";
                } else {
                    cout << "0\n";
                }
            }
            // Mean goals per game for <Название команды>
            // — среднее количество голов, забиваемое данной командой за один матч. Гарантирутся, что к моменту подачи такого запроса команда уже сыграла хотя бы один матч.
            if (in.substr(0, string("Mean goals per game for").size()) == "Mean goals per game for"){
                comand = in.substr(string("Mean goals per game for").size() + 1, in.size() - (string("Mean goals per game for").size() + 1));
                //cout << "Mean1: ";
                cout << (double)ComandsInfo[comand].total / ComandsInfo[comand].matches << "\n";
            }
            // Total goals by <Имя игрока>
            // — количество голов, забитое данным игроком за все матчи.
            if (in.substr(0, string("Total goals by").size()) == "Total goals by"){
                name = in.substr(string("Total goals by").size() + 1, in.size() - (string("Total goals by").size() + 1));
                //cout << "Total2: ";
                if (ConnectionPlayerTeam.find(name) != ConnectionPlayerTeam.end()){
                    cout << ComandPlayersInfo[ConnectionPlayerTeam[name]][name].total << "\n";
                } else {
                    cout << "0\n";
                }
            }
            // Mean goals per game by <Имя игрока>
            // — среднее количество голов, забиваемое данным игроком за один матч его команды. Гарантирутся, что к моменту подачи такого запроса игрок уже забил хотя бы один гол.
            if (in.substr(0, string("Mean goals per game by").size()) == "Mean goals per game by"){
                name = in.substr(string("Mean goals per game by").size() + 1, in.size() - (string("Mean goals per game by").size() + 1));
                //cout << "Mean2: ";
                //cout << "Mean: " << name << " " << ComandPlayersInfo[ConnectionPlayerTeam[name]][name] << " ";
                cout << (double)ComandPlayersInfo[ConnectionPlayerTeam[name]][name].total / ComandsInfo[ConnectionPlayerTeam[name]].matches << "\n";
            }
            // Goals on minute <Минута> by <Имя игрока>
            // — количество голов, забитых данным игроком ровно на указанной минуте матча.
            if (in.substr(0, string("Goals on minute").size()) == "Goals on minute"){
                minute = stoi(in.substr(string("Goals on minute").size() + 1, in.size() - (string("Goals on minute").size() + 1)));
                name = in.substr(string(string("Goals on minute ") + to_string(minute) + string(" by")).size() + 1, in.size() - (string(string("Goals on minute ") + to_string(minute) + string(" by")).size() + 1));
                //cout << "Minute1: ";
                if (TimeGoals.find(name) != TimeGoals.end()){
                    cout << TimeGoals[name][minute - 1] << "\n";
                } else {
                    cout << "0\n";
                }
            }
            // Goals on first <T> minutes by <Имя игрока>
            // — количество голов, забитых данным игроком на минутах с первой по T-ю включительно.
            if (in.substr(0, string("Goals on first").size()) == "Goals on first"){
                minute = stoi(in.substr(string("Goals on first").size() + 1, in.size() - (string("Goals on first").size() + 1)));
                name = in.substr(string(string("Goals on first ") + to_string(minute) + string(" minutes by")).size() + 1, in.size() - (string(string("Goals on first ") + to_string(minute) + string(" minutes by")).size() + 1));
                goals = 0;
                if (TimeGoals.find(name) != TimeGoals.end()){
                    for (int i = 0; i < minute; i++){
                        goals += TimeGoals[name][i];
                    }
                }
                //cout << "Minute2: ";
                cout << goals << "\n";
            }
            // Goals on last <T> minutes by <Имя игрока>
            // — количество голов, забитых данным игроком на минутах с (91 - T)-й по 90-ю включительно.
            if (in.substr(0, string("Goals on last").size()) == "Goals on last"){
                minute = stoi(in.substr(string("Goals on last").size() + 1, in.size() - (string("Goals on last").size() + 1)));
                name = in.substr(string(string("Goals on last ") + to_string(minute) + string(" minutes by")).size() + 1, in.size() - (string(string("Goals on last ") + to_string(minute) + string(" minutes by")).size() + 1));
                goals = 0;
                if (TimeGoals.find(name) != TimeGoals.end()){
                    for (int i = 90 - minute; i < 90; i++){
                        goals += TimeGoals[name][i];
                    }
                }
                //cout << "Minute3: ";
                cout << goals << "\n";
            }
            // Score opens by <Название команды>
            // — сколько раз данная команда открывала счет в матче.
            // Score opens by <Имя игрока>
            // — сколько раз данный игрок открывал счет в матче.
            if (in.substr(0, string("Score opens by").size()) == "Score opens by"){
                comand = in.substr(string("Score opens by").size() + 1, in.size() - (string("Score opens by").size() + 1));
                //cout << "Opens: ";
                if (comand[0] == '"'){
                    if (ComandsInfo.find(comand) != ComandsInfo.end())
                        cout << ComandsInfo[comand].opens << "\n";
                    else
                        cout << "0\n";
                } else {
                    if (ConnectionPlayerTeam.find(comand) != ConnectionPlayerTeam.end())
                        cout << ComandPlayersInfo[ConnectionPlayerTeam[comand]][comand].opens << "\n";
                    else
                        cout << "0\n";
                }
            }
            // getline(cin1, in);
            // cout << in << "\n";
        }
    }
    // PrintComandPlayersInfo(ComandPlayersInfo);
    // PrintConnectionPlayerTeam(ConnectionPlayerTeam);
    // PrintComandsInfo(ComandsInfo);
    // unordered_map<string, vector<int>> TimeGoals;
    // cout << "\nTimeGoals[A]:\n";
    // for (int i = 0; i < 90; i++){
    //     cout << i << ": " << TimeGoals[string("A")][i] << "\n";
    // }
}

