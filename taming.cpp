#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n, ans = 0, delta = 0;
    cin >> n;
    vector<int> cows(n, 0);
    for (int& i : cows) {
        cin >> i;
    }
    if (cows[0] != 0 && cows[0] != -1) {
        cout << -1;
        return 0;
    }
    bool filling = 0;
    int fulnum = 0;
    for (int i = n - 1; i >= 1; --i) {
        if (cows[i] != -1) {
            if (cows[i - 1] == -1) {
                filling = 1;
                fulnum = cows[i] - 1;
                cows[i - 1] = fulnum;
                if (fulnum == 0) {
                    filling = 0;
                }
            } else {
                if ((cows[i - 1] > cows[i] || cows[i - 1] != cows[i] - 1) && cows[i] != 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    if (cows[0] != 0 && cows[0] != -1) {
        cout << -1;
        return 0;
    }
    cows[0] = 0;
    for (int i : cows) {
        if (i == 0) {
            ++ans;
        } else if (i == -1) {
            ++delta;
        }
    }
    cout << ans << " " << ans + delta;
}