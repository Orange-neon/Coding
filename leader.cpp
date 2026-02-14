#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    //COMMENT OUTA FTE TREITn
    //freopen("leader.in", "r", stdin);
    int n, ans = 0;
    char Original;
    int otherLeaderI = INT_MAX;
    bool switchBack = false;
    cin >> n;
    vector<int> cows(n, 0);
    vector<int> range(n, 0);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (i == 0) {
            Original = c;
        } else if (c == Original && otherLeaderI != INT_MAX) {
            switchBack = true;
        } else {
            if (c != Original) {
                otherLeaderI = min(otherLeaderI, i);
            }
        }
        if (c == 'G') {
            cows[i] = 1;
        } else {
            cows[i] = 0;
        }
    }
    for (int& i : range) {
        cin >> i;
        --i;
    }
    if (switchBack) {
        for (int i = 0; i < otherLeaderI; ++i) {
            if (range[i] >= otherLeaderI) {
                ++ans;
            }
        }
        cout << ans;
    } else {
        for (int i = 0; i < otherLeaderI; ++i) {
            if (i == 0) {
                if (range[i] >= otherLeaderI - 1) {
                    ++ans;
                }
                continue;
            }
            if (range[i] >= otherLeaderI) {
                ++ans;
            }
        }
        cout << ans;
    }
}