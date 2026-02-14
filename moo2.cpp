#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("moo2.in", "r", stdin);
    long long n, ans = 0;
    cin >> n;
    vector<long long> cowNs(n, 0);
    vector<long long> distinctsAtIndx(n, 0);
    set<long long> tracker;
    for (long long i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        tracker.insert(a);
        cowNs[i] = a;
        distinctsAtIndx[i] = tracker.size();
    }
    map<long long, array<long long, 3>> cowNsTracker;
    for (long long i = n - 1; i >= 0; --i) {
        ++cowNsTracker[cowNs[i]][1];
        if (cowNsTracker[cowNs[i]][1] == 2) {
            cowNsTracker[cowNs[i]][0] = i;
            cowNsTracker[cowNs[i]][2] = 2;
        }
    }
    for (auto cownDetails : cowNsTracker) {
        if ((cownDetails.second)[2] == 2) {
            if ((cownDetails.second)[0] == 0) {
                continue;
            }
            if ((cownDetails.second)[1] == 2) {
                ans += distinctsAtIndx[(cownDetails.second)[0]] - 1;
            } else if (cowNs[(cownDetails.second)[0] - 1] == cowNs[(cownDetails.second)[0]]){
                ans += distinctsAtIndx[(cownDetails.second)[0]] - 1;
            } else {
                ans += distinctsAtIndx[(cownDetails.second)[0]] - 1;
            }
        }
    }
    cout << ans;    
}