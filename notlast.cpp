#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("notlast.in", "r", stdin);
    //freopen("notlast.out", "w", stdout);
    int n, min = INT_MAX;
    cin >> n;
    map<string, int> cowtoAmt = {
        {"Bessie", 0},
        {"Elsie", 0},
        {"Daisy", 0},
        {"Gertie", 0},
        {"Annabelle", 0},
        {"Maggie", 0},
        {"Henrietta", 0}
    };
    vector<pair<int, string>> amtToCow;
    vector<pair<int, string>> toRemove;
    for (int i = 0; i < n; ++i) {
        string s;
        int a;
        cin >> s >> a;
        cowtoAmt[s] += a;
    }
    for (const auto& cows : cowtoAmt) {
        if (cows.second < min) {
            min = cows.second;
        }
    }
    for (const auto& pair : cowtoAmt) {
        amtToCow.push_back({pair.second, pair.first});
        if (pair.second == min) {
            toRemove.push_back({pair.second, pair.first});
        }
    }
    for (const auto& removeMin : toRemove) {
        amtToCow.erase(remove(amtToCow.begin(), amtToCow.end(), removeMin), amtToCow.end());
    }
    if (amtToCow.empty()) {
        cout << "Tie\n";
        return 0;
    }
    min = INT_MAX;
    int countmin = 0;
    string ans;
    for (const auto& cows : amtToCow) {
        if (cows.first < min) {
            min = cows.first;
        }
    }
    for (const auto& cow : amtToCow) {
        if (cow.first == min) {
            if (countmin != 0) {
                cout << "Tie\n";
                return 0;
            }
            ++countmin;
            ans = cow.second;
        }
    }
    cout << ans << '\n';
}