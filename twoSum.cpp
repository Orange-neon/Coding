#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // COMMENT OUT AFTER TESTING
    freopen("twoSum.in", "r", stdin);
    int n, x;
    cin >> n >> x;
    map<int, int> read;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (read.count(x - a) == 1) {
            cout << i + 1 << " " << read[x - a] + 1;
            return 0;
        } else {
            read[a] = i;
        }
    }
    cout << "IMPOSSIBLE";
}