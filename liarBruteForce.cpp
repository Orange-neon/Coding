#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    //freopen("7.in", "r", stdin);
    int n, liars = 0;
    cin >> n;
    vector<pair<int, char>> speech;
    vector<pair<int, char>> conditions;
    for (int i = 0; i < n; ++i) {
        pair<int, char> statement;
        cin >> statement.second >> statement.first;
        conditions.push_back(statement);
    }
    sort(conditions.begin(), conditions.end());
    int reducedIndex = 0;
    speech = conditions;
    speech[0].first = reducedIndex;
    for (int i = 1; i < n; ++i) {
        auto say = conditions[i];
        if (conditions[i].first == conditions[i - 1].first) {
            speech[i].first = speech[i - 1].first;
        } else {
            ++reducedIndex;
            speech[i].first = reducedIndex;
        }
    }
    vector<int> liarCount;
    for (int i = 0; i < n; ++i) {
        int liar = 0;
        for (int l = 0; l < i; ++l) {
            if (speech[l].second == 'L') {
                ++liar;
            }
        }
        for (int r = i + 1; r < n; ++r) {
            if (speech[r].second == 'G') {
                ++liar;
            }
        }
        liarCount.push_back(liar);
    }
    cout << *min_element(liarCount.begin(), liarCount.end());
}