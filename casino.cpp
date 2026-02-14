#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("casino.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m, ans = 0;
        cin >> n >> m;
        vector<vector<int>> decks;
        for (int j = 0; j < n; ++j) {
            vector<int> deck(m);
            for (int k = 0; k < m; ++k) {
                int l;
                cin >> l;
                deck[k] = l;
            }
            decks.push_back(deck);
        }
        for (int col = 0; col < m; ++col) {
            vector<int> colNums;
            int colSum = 0, rSum = 0;
            for (int deckN = 0; deckN < n; ++deckN) {
                colNums.push_back(decks[deckN][col]);
                colSum += decks[deckN][col];
            }
            sort(colNums.begin(), colNums.end());
            for (int p = 0; p < n; ++p) {
                rSum += colNums[p];
                ans += (colSum - rSum) * (n - p - 1);
            }
        }
        cout << ans << '\n';
    }
}