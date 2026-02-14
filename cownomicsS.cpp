#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<char>> spotty(n, vector<char>(m, ' '));
    vector<vector<char>> plain(n, vector<char>(m, ' '));
    //INPUT
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> spotty[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> plain[i][j];
        }
    }
    for (int a = 0; a < m - 2; ++a) {
        for (int b = a + 1; b < m - 1; ++b) {
            for (int c = b + 1; c < m; ++c) {
                set<pair<char, pair<char, char>>> spots;
                set<pair<char, pair<char, char>>> plains;
                pair<char, pair<char, char>> sCows;
                pair<char, pair<char, char>> pCows;
                for (int i = 0; i < n; ++i) {
                    sCows.first = spotty[i][a];
                    sCows.second.first = spotty[i][b];
                    sCows.second.second = spotty[i][c];
                    pCows.first = plain[i][a];
                    pCows.second.first = plain[i][b];
                    pCows.second.second = plain[i][c];
                    spots.insert(sCows);
                    plains.insert(pCows);
                }
                spots.merge(plains);
                if (plains.empty()) {
                    ++ans;
                }
            }
        }
    }
    cout << ans;
}