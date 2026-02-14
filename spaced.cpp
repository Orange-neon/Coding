#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMME NT OU AFT EJIT EWTGWTGN
    //freopen("spaced.in", "r", stdin);
    int n, xMax = 0, yMax = 0;
    cin >> n;
    vector<vector<int>> vals(n, vector<int>(n, 0));
    for (auto& row : vals) {
        for (int& item : row) {
            cin >> item;
        }
    }
    vector<int> alt;
    int altx = 1;
    for (int i = 0; i < n; ++i) {
        alt.push_back(altx);
        altx *= -1;
    }
    for (auto row : vals) {
        int xSum1 = 0, xSum2 = 0;
        for (int i = 0; i < n; ++i) {
            if (alt[i] == 1) {
                xSum1 += row[i];
            } else {
                xSum2 += row[i];
            }
        }
        xMax += max(xSum1, xSum2);
    }
    for (int col = 0; col < n; ++col) {
        int ySum1 = 0, ySum2 = 0;
        for (int i = 0; i < n; ++i) {
            if (alt[i] == 1) {
                ySum1 += vals[i][col];
            } else {
                ySum2 += vals[i][col];
            }
        }
        yMax += max(ySum1, ySum2);
    }
    cout << max(xMax, yMax);
}