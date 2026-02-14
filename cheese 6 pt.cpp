#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TTESTING
    freopen("cheese.in", "r", stdin);
    int n, q, diff;
    cin >> n >> q;
    diff = n - 1;
    set<array<int, 3>> carved;
    int Counter = 0;
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        array<int, 3> toCarve = {a,b,c};
        for (int j = 0; j < 3; ++j) {
            if (toCarve[j] + diff < n) {
                toCarve[j] += diff;
                if (carved.count(toCarve)) {
                    ++Counter;
                    toCarve[j] -= diff;
                } else {
                    toCarve[j] -= diff;
                    carved.insert(toCarve);
                }
            }
            if (toCarve[j] - diff >= 0) {
                toCarve[j] -= diff;
                if (carved.count(toCarve)) {
                    ++Counter;
                    toCarve[j] += diff;
                } else {
                    toCarve[j] += diff;
                    carved.insert(toCarve);
                }
            }
        }
        cout << Counter << '\n';
    }
}