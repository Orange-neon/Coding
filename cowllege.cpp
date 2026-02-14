#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("cowllege.in", "r", stdin);
    //other sol works with accounting for REPATS
    ll n, maxMoney = 0, cost = 0;
    cin >> n;
    vector<ll> cows(n);
    for (ll i = 0; i < n; ++i) {
        ll time;
        cin >> time;
        cows[i] = time;
    }
    sort(cows.begin(), cows.end());
    ll subtract = 0;
    for (ll i = 0; i < n; ++i) {
        ll testM = 0, ext = 0;
        while (cows[i] == cows[i + ext]) {
            ++ext;
        }
        testM = cows[i] * (n - subtract);
        if (maxMoney < testM) {
            maxMoney = testM;
            cost = cows[i];
        }
        i += ext - 1;
        subtract += ext;
    }
    cout << maxMoney << " " << cost;
}