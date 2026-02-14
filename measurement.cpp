#include<bits/stdc++.h>
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, changesNeeded = 0;
    cin >> n;
    set<pair<int, pair<int, int>>> tracker;
    for (int i = 0; i < n; ++i) {
        int t, amt, idd;
        string name;
        cin >> t >> name >> amt;
        if (name[0] == 'B') {
            idd = 0;
        } else if (name[0] == 'E') {
            idd = 1;
        } else {
            idd = 2;
        }
        tracker.insert({t, {idd, amt}});
    }
    vector<vector<int>> runningTracker(1001, vector<int>(3, 0));
    for (auto item : tracker) {
        runningTracker[item.first][item.second.first] = runningTracker[item.first - 1][item.second.first] + item.second.second;
        for (int i = item.first + 1; i < 1001; ++i) {
            runningTracker[i][item.second.first] = runningTracker[i - 1][item.second.first];
        }
    }
    vector<int> pastmaxes = {1, 1, 1};
    for (int i = 0; i < 1001; ++i) {
        vector<int> maxes(3, 0);
        int maxe = *(max_element(runningTracker[i].begin(), runningTracker[i].end()));
        for (int j = 0; j < 3; ++j) {
            if (runningTracker[i][j] == maxe) {
                maxes[j] = 1;
            }
        }
        if (maxes != pastmaxes) {
            ++changesNeeded;
            pastmaxes = maxes;
        }
    }
    cout << changesNeeded;
}