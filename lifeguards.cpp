#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n, beginCovered = 0, ans = 0;
    cin >> n;
    vector<int> poolOpen(1000, 0);
    vector<pair<int, int>> shifts(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        shifts[i] = {a - 1, b - 1};
        for (int j = a - 1; j < b - 1; ++j) {
            ++poolOpen[j];
        }
    }
    for (int i : poolOpen) {
        if (i != 0) {
            ++beginCovered;
        }
    }
    for (auto shift : shifts) {
        int newEmpty = 0;
        for (int j = shift.first; j < shift.second; ++j) {
            if (poolOpen[j] == 1) {
                ++newEmpty;
            }
        }
        ans = max(ans, beginCovered - newEmpty);
    }
    cout << ans;
}