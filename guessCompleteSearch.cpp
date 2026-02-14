#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<set<string>> facts(n);
    for (int i = 0; i < n; ++i) {
        string temp;
        int k;
        cin >> temp >> k;
        for (int j = 0; j < k; ++j) {
            string fact;
            cin >> fact;
            facts[i].insert(fact);
        }
    }
    for (int a = 0; a < n - 1; ++a) {
        for (int b = a + 1; b < n; ++b) {
            int before = facts[a].size() + facts[b].size();
            set<string> one = facts[a], two = facts[b];
            one.merge(two);
            ans = max(ans, before - int (one.size()) + 1);
        } 
    }
    cout << ans;
}