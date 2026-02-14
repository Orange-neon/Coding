#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUTA FTER TEFSGIN
    freopen("pests.in", "r", stdin);
    int n;
    cin >> n;
    vector<long long> grass(n);
    for (long long& i : grass) {
        cin >> i;
    }
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
        if (grass[i] != 0) {
            ans += abs(grass[i]);
            int start = grass[i], oldDiff = -1, newDiff = -1;
            long long effect = 1;
            bool series = 1;
            for (long long j = i; j < n; ++j) {
                if (series) {
                    if (oldDiff != -1) {
                        newDiff = grass[j] - grass[j - 1];
                        if (newDiff != oldDiff) {
                            series = 0;
                        }
                    } else if (j == i + 1) {
                        oldDiff = grass[j] - grass[j - 1];
                    }
                }
                grass[j] += -1 * start * effect;
                ++effect;
            }
            if (series && oldDiff != -1 && newDiff != -1) {
                ans -= abs(start);
                ++ans;
                break;
            }
        }
    }
    cout << ans;
}