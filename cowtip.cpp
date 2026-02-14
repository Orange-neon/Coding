#include<bits/stdc++.h>
using namespace std;
bool clear(vector<vector<int>> c) {
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < c.size(); ++j) {
            if (c[i][j] == -1) {
                return 0;
            }
        }
    }
    return 1;
}
pair<int, int> target(vector<vector<int>> c) {
    for (int y = c.size() - 1; y >= 0; --y) {
        int o = y;
        for (int x = c.size() - 1; x >= 0; --x) {
            if (y < c.size()) {
                if (c[y][x] == -1) {
                    return {x, y};
                }
                ++y;
            } else {
                break;
            }
        }
        y = o;
    }
    for (int x = c.size() - 2; x >= 0; --x) {
        int o = x;
        for (int y = 0; y < c.size(); ++y) {
            if (x < c.size()) {
                if (c[y][x] == -1) {
                    return {x, y};
                }
                --x;
            } else {
                break;
            }
        }
        x = o;
    }
    return {-1, -1};
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> cows;
    //input
    for (int i = 0; i < n; ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '0') {
                row.push_back(1);
            } else {
                row.push_back(-1);
            }
        }
        cows.push_back(row);
    }
    while (!clear(cows)) {
        pair<int, int> latestPt = target(cows);
        for (int y = latestPt.second; y >= 0; --y) {
            for (int x = latestPt.first; x >= 0; --x) {
                cows[y][x] *= -1;
            }
        }
        ++ans;
    }
    cout << ans;
}