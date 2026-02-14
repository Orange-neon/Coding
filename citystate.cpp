#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    map<pair<string, string>, int> store;
    set<pair<string, string>> seen;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        store[{a.substr(0, 2), b.substr(0, 2)}]++;
    }

    for (const auto& cityState : store) {
        if (seen.count(make_pair(cityState.first.second, cityState.first.first))) {
            ans += store[make_pair(cityState.first.second, cityState.first.first)] * store[make_pair(cityState.first.first, cityState.first.second)];
        }
        seen.insert(make_pair(cityState.first.first, cityState.first.second));
    }
    cout << ans;
}