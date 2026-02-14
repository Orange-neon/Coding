#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("hoof.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rules(n, vector<int>(n, 0));
    map<pair<int, int>, int> ElsieMoves;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            char c;
            cin >> c;
            switch (c) {
                case 'W':
                    rules[i][j] = 1;
                    break;
                case 'L':
                    rules[i][j] = -1;
                    break;
                default:
                    rules[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            rules[j][i] = rules[i][j] * -1;
        }
    }
    for (int i = 0; i < m; ++i) {
        int ans = 0;
        set<int> winMoveStarters;
        pair<int, int> move;
        cin >> move.first >> move.second;
        if (move.first < move.second) {
            swap(move.first, move.second);
        }
        --move.first;
        --move.second;
        if (ElsieMoves.count(move)) {
            cout << ElsieMoves[move] << '\n';
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (rules[j][move.first] == rules[j][move.second] && rules[j][move.first] == 1) {
                winMoveStarters.insert(j);
            }
        }
        int x = winMoveStarters.size();
        ans = x * (2 * n - 1)  - x * (x - 1);
        ElsieMoves[move] = ans;
        cout << ans << '\n';
    }

}