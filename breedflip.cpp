#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'G') {
            a.push_back(1);
        } else {
            a.push_back(-1);
        }
    }
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'G') {
            b.push_back(1);
        } else {
            b.push_back(-1);
        }
    }
    int i = 0;
    while (i < n) {
        int ext = 0;
        bool used = 0;
        while (a[i + ext] * -1 == b[i + ext]) {
            b[i + ext] *= -1;
            ++ext;
            used = 1;
        }
        if (used) {
            ++ans;
            i += ext;
        } else {
            ++i;
        }
    }
    cout << ans;
}