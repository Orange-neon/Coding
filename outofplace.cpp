#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n, bessie = 0, ans = 0;
    cin >> n;
    vector<int> cows;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        cows.push_back(h);
    }
    vector<int> cowSort = cows;
    sort(cowSort.begin(), cowSort.end());
    for (int i = 0; i < n; ++i) {
        int temp = cows[i];
        auto cowsIt = find(cowSort.begin(), cowSort.end(), temp);
        cowSort.erase(cowsIt);
        cows.erase(cows.begin() + i);
        if (cows == cowSort) {
            bessie = i;
        }
        cows.insert(cows.begin() + i, temp);
        cowSort.insert(cowsIt, temp);
    }
    if (bessie - 1 >= 0 && cows[bessie] < cows[bessie - 1]) {
        for (int i = bessie; i >= 1; --i) {
            if (cows[bessie] >= cows[i - 1]) {
                break;
            } else {
                if (cows[i] == cows[i - 1]) {
                    continue;
                } else {
                    ++ans;
                }
            }
        }
        cout << ans;
    } else if (bessie + 1 < n && cows[bessie] > cows[bessie + 1]) {
        for (int i = bessie; i < n - 1; ++i) {
            if (cows[bessie] <= cows[i + 1]) {
                break;
            } else {
                if (cows[i] == cows[i + 1]) {
                    continue;
                } else {
                    ++ans;
                }
            }
        }
        cout << ans;
    }
}