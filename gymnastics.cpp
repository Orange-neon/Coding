#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int n, k;
    cin >> k >> n;
    vector<vector<int>> sessions;
    for (int i = 0; i < k; ++i) {
        vector<int> rank;
        for (int j = 0; j < n; ++j) {
            int cow;
            cin >> cow;
            rank.push_back(cow);
        }
        sessions.push_back(rank);
    }
    map<pair<int, int>, int> rankPairs;
    set<pair<int, int>> consistents;
    for (auto practice : sessions) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++rankPairs[{practice[i], practice[j]}];
                if (rankPairs[{practice[i], practice[j]}] == k) {
                    consistents.insert({practice[i], practice[j]});
                }
            }
        }
    }
    cout << consistents.size();
}