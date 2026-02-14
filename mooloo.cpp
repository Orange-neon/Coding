#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("mooloo.in", "r", stdin);
    ll n, k, cost = 0;
    cin >> n >> k;
    vector<ll> times(n, 0);
    for (auto& time : times) {
        cin >> time;
    }
    ll i = 0;
    ll streak = 1;
    while (i < n - 1) {
        if (times[i + 1] - times[i] > k) {
            cost += streak + k;
            ++i;
            streak = 1;
        } else {
            streak += times[i + 1] - times[i];
            ++i;
        }
    }
    cost += streak + k;
    cout << cost;
}