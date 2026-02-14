#include<bits/stdc++.h>
using namespace std;
int n, ans = INT_MAX;
int instability(vector<int> heavys, int a, int b) {
    heavys.erase(heavys.begin() + a);
    heavys.erase(heavys.begin() + b - 1);
    int rtn = 0;
    for (int i = 0; i < heavys.size() - 1; i += 2) {
        rtn += heavys[i + 1] - heavys[i];
    }
    return rtn;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("kayak.in", "r", stdin);
    cin >> n;
    vector<int> heavys(2 * n, 0);
    for (int i = 0; i < (2*n); ++i) {
        cin >> heavys[i];
    }
    sort(heavys.begin(), heavys.end());
    for (int i = 0; i < 2*n; ++i) {
        for (int j = i + 1; j < 2*n; ++j) {
            int x = instability(heavys, i, j);
            ans = min(ans, x);
        }
    }
    cout << ans;
}