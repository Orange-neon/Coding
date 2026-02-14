#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTGIN
    //freopen("daisy.in", "r", stdin);
    int n, goodFotos = 0;
    cin >> n;
    vector<int> flowers(n);
    for (int i = 0; i < n; ++i) {
        cin >> flowers[i];
    }
    for (int i = 0; i < n; ++i) {
        set<int> seen;
        int petals = 0;
        for (int j = i; j < n; ++j) {
            seen.insert(flowers[j]);
            petals += flowers[j];
            if (petals % (j - i + 1) == 0) {
                if (seen.count(petals/(j-i+1))) {
                    ++goodFotos;
                    continue;
                }
            }
        }
    }
    cout << goodFotos;
}