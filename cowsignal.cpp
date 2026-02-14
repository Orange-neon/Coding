#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("2.in", "r", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<char>> text(m, vector<char>(n,'.'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> text[i][j];
        }
    }
    vector<vector<char>> ans(m*k, vector<char>(n*k, '.'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    ans[i*k + x][j*k + y] = text[i][j];
                }
            }
        }
    }
    for (int i = 0; i < m*k; i++) {
        for (int j = 0; j < n*k; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}