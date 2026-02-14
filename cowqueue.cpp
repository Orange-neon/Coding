#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowqueue.in", "r", stdin);
    //COMMEITNE IN AFOETE BEGEu
    freopen("cowqueue.out", "w", stdout);
    int n, time = 0;
    cin >> n;
    vector<pair<int, int>> cows;
    for (int i = 0; i < n; ++i) {
        int start, intero;
        cin >> start >> intero;
        cows.push_back({start, intero});
    }
    sort(cows.begin(), cows.end());
    for (const auto& cow : cows) {
        time = max(time, cow.first);
        time += cow.second;
    }
    cout << time;
}