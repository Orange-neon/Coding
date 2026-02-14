#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<char>> spots;
    vector<vector<char>> plain;
    for (int i = 0; i < n; ++i) {
        vector<char> ithGenes(m, ' ');
        for (int j = 0; j < m; ++j) {
            cin >> ithGenes[j];
        }
        spots.push_back(ithGenes);
    }
    for (int i = 0; i < n; ++i) {
        vector<char> ithGenes(m, ' ');
        for (int j = 0; j < m; ++j) {
            cin >> ithGenes[j];
        }
        plain.push_back(ithGenes);
    }
    for (int pos = 0; pos < m; ++pos) {
        set<char> plainn;
        set<char> spotss;
        for (int spottedC = 0; spottedC < n; ++spottedC) {
            spotss.insert(spots[spottedC][pos]);
        }
        for (int plainC = 0; plainC < n; ++plainC) {
            plainn.insert(plain[plainC][pos]);
        }
        spotss.merge(plainn);
        if (plainn.size() == 0) {
            ++ans;
        }
    }
    cout << ans;
}