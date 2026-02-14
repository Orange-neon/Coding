#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENTOUT AFTER TESTGIN
    //freopen("majority.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> hays(n);
        for (int j = 0; j < n; ++j) {
            cin >> hays[j];
        }
        set<int> ans;
        for (int ones = 0; ones < n - 1; ++ones) {
            if (hays[ones] == hays[ones + 1]) {
                ans.insert(hays[ones]);
            }
        }
        for (int twos = 0; twos < n - 2; ++twos) {
            if (hays[twos] == hays[twos + 2]) {
                ans.insert(hays[twos]);
            }
        }
        if (!ans.empty()) {
            int count = 1;
            for (int hay : ans) {
                if (count == ans.size()) {
                    break;
                }
                cout << hay << " ";
                ++count;
            }
            cout << *ans.rbegin() << '\n';
        } else {
            cout << -1 << '\n';
        }
        
    }
}