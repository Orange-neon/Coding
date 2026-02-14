#include <bits/stdc++.h>
// 11/16 cases TLE
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TTESTING
    //freopen("cheese.in", "r", stdin);
    int n, q, diff;
    cin >> n >> q;
    diff = n - 1;
    set<array<int, 3>> carved;
    int Counter = 0;
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        array<int, 3> toCarve = {a,b,c};
        array<int, 3> orginial = toCarve;
        for (int j = 0; j < 3; ++j) {
            int dig = 0;
            while (dig < diff) {
                
                ++toCarve[j];
                if (!carved.count(toCarve)) {
                    break;
                }
                ++dig;
            }
            int abc = dig;
            toCarve = orginial;
            dig = 0;
            while (dig < diff) {
                
                --toCarve[j];
                if (!carved.count(toCarve)) {
                    break;
                }
                ++dig;
            }
            int zyx = dig;
            if (abc + zyx == diff) {
                ++Counter;
            }
            toCarve = orginial;
        }
        carved.insert(toCarve);
        cout << Counter << '\n';
    }
}