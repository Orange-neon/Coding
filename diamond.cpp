#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k, maxSize = 0;
    cin >> n >> k;
    vector<int> diamondSizes(n);
    set<int> searched;
    for (int i = 0; i < n; ++i) {
        cin >> diamondSizes[i];
    }
    sort(diamondSizes.begin(), diamondSizes.end());
    for (int q = 0; q < n; ++q) {
        if (searched.count(diamondSizes[q]) == 0) {
            searched.insert(diamondSizes[q]);
            int extend = 0;
            vector<int> conta;
            while (diamondSizes[q + extend] - diamondSizes[q] <= k) {
                conta.push_back(diamondSizes[q + extend]);
                ++extend;
                if (q + extend >= n) {
                    break;
                }
            }
            maxSize = max(maxSize, int(conta.size()));
        }
    }
    cout << maxSize;
}