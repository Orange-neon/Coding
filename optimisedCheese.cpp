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
    map<pair<int, int>, int> xnn;
    map<pair<int, int>, int> nyn;
    map<pair<int, int>, int> nnz;
    int Counter = 0;
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        array<int, 3> toCarve = {a,b,c};
        if (xnn[{toCarve[1], toCarve[2]}] == n - 1) {
            ++Counter;
        }
        if (nyn[{toCarve[0], toCarve[2]}] == n - 1) {
            ++Counter;
        }
        if (nnz[{toCarve[0], toCarve[1]}] == n - 1) {
            ++Counter;
        }
        ++xnn[{toCarve[1], toCarve[2]}];
        ++nyn[{toCarve[0], toCarve[2]}];
        ++nnz[{toCarve[0], toCarve[1]}];
        cout << Counter << '\n';
    }
}