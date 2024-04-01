#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<int, int> findShortestSegment(int N, int K, const vector<int>& trees) {
    unordered_map<int, int> count;
    int distinct = 0;
    int minLength = N + 1;
    pair<int, int> segment = {-1, -1};

    int left = 0;
    for (int right = 0; right < N; ++right) {
        if (++count[trees[right]] == 1) distinct++;

        while (distinct == K) {
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                segment = {left + 1, right + 1}; // Плюс 1 для соответствия условию задачи
            }
            if (--count[trees[left]] == 0) distinct--;
            left++;
        }
    }

    return segment;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> trees(N);
    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
    }

    pair<int, int> segment = findShortestSegment(N, K, trees);
    cout << segment.first << " " << segment.second << "\n";
}
