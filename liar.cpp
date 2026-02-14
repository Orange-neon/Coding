#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    //freopen("liar.in", "r", stdin);
    int n, lcount = 0, gcount = 0, liars = 0, Gliars = 0, Lliars = 0;
    cin >> n;
    vector<pair<int, char>> speech;
    for (int i = 0; i < n; ++i) {
        pair<int, char> statement;
        cin >> statement.second >> statement.first;
        speech.push_back(statement);
        if (statement.second == 'L') {
            ++lcount;
        } else {
            ++gcount;
        }
    }
    sort(speech.begin(), speech.end());
    if (lcount > gcount) {
        bool countActivate = 0;
        for (int i = 0; i < n; ++i) {
            if (speech[i].second == 'L') {
                countActivate = 1;
            }
            if (speech[i].second == 'G' && countActivate) {
                ++liars;
            }
        }
    } else if (lcount < gcount) {
        bool countActivate = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (speech[i].second == 'G') {
                countActivate = 1;
            }
            if (speech[i].second == 'L' && countActivate) {
                ++liars;
            }
        }
    } else {
        bool countActivate = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (speech[i].second == 'G') {
                countActivate = 1;
            }
            if (speech[i].second == 'L' && countActivate) {
                ++Lliars;
            }
        }
        countActivate = 0;
        for (int i = 0; i < n; ++i) {
            if (speech[i].second == 'L') {
                countActivate = 1;
            }
            if (speech[i].second == 'G' && countActivate) {
                ++Gliars;
            }
        }
        liars = min(Gliars, Lliars);
    }
    cout << liars;
}