#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("badmilk.in", "r", stdin);
    //freopen("badmilk.out", "w", stdout);
    int n, m, d, s;
    cin >> n >> m >> d >> s;
    vector<vector<pair<int, int>>> records(n);
    vector<pair<int, int>> sicked;
    vector<vector<int>> badmilks(m);
    map<int, set<int>> milkdranks;
    for (int i = 0; i < d; ++i) {
        int p, m, t;
        cin >> p >> m >> t;
        records[p - 1].push_back({t, m});
        milkdranks[m].insert(p);
    }
    for (int j = 0; j < s; ++j) {
        int p, t;
        cin >> p >> t;
        sicked.push_back({p - 1, t});
    }
    for (const auto& pair : sicked) {
        for (auto milk : records[pair.first]) {
            if (milk.first < pair.second) {
                badmilks[pair.first].push_back(milk.second);
            }
        }
    }
    map<int, int> badMilkTrack;
    vector<int> probably;
    for (auto possibiles : badmilks) {
        for (int leche : possibiles) {
            ++badMilkTrack[leche];
            if (badMilkTrack[leche] == s) {
                probably.push_back(leche);
            }
        }
    }
    int ans = 0;
    for (int i : probably) {
        ans = max(ans, int(milkdranks[i].size()));
    }
    cout << ans;
}