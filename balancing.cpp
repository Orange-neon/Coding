#include<bits/stdc++.h>
using namespace std;
int getM(vector<pair<int, int>> cows, int xB, int yB) {
    int i = 0, ii = 0, iii = 0, iv = 0;
    for (const auto& cowL : cows) {
        int x = cowL.first, y = cowL.second;
        if (x > xB && y > yB) {
            ++i;
        } else if (x > xB && y < yB) {
            ++iv;
        } else if (x < xB && y > yB) {
            ++ii;
        } else if (x < xB && y < yB) {
            ++iii;
        }
    }
    return max(max(i, ii), max(iii, iv));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n, b, ans = INT_MAX;
    cin >> n >> b;
    vector<pair<int, int>> Ocows(n, {-1, -1});
    vector<pair<int, int>> yOx(n, {-1, -1});
    vector<pair<int, int>> xOyO;
    for (auto& pt : Ocows) {
        cin >> pt.second >> pt.first;
    }
    sort(Ocows.begin(), Ocows.end());
    yOx = Ocows;
    int yC = 3;
    yOx[0].first = 1;
    for (int i = 1; i < n; ++i) {
        if (Ocows[i].second != Ocows[i - 1].second) {
            yOx[i].first = yC;
            yC += 2;
        } else {
            yOx[i].first = yOx[i - 1].first;
        }
    }
    for (const auto& yxPt : yOx) {
        xOyO.push_back({yxPt.second, yxPt.first});
    }
    sort(xOyO.begin(), xOyO.end());
    xOyO[0].first = 1;
    int xC = 3;
    for (int i = 1; i < n; ++i) {
        if (Ocows[i].first != Ocows[i - 1].first) {
            xOyO[i].first = xC;
            xC += 2;
        } else {
            xOyO[i].first = xOyO[i - 1].first;
        }
    }
    ans = min(getM(xOyO, 0, 0), ans);
    for (const auto& xpart : xOyO) {
        for (const auto& ypart : xOyO) {
            int xb = xpart.first + 1, yb = ypart.second + 1;
            ans = min(getM(xOyO, xb, yb), ans);
        }
    }
    cout << ans;
}