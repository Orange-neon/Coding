#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;
    string lane;
    cin >> lane;
    for (int len = 1; len < n; ++len) {
        set<string> letters;
        bool works = 1;
        for (int strt = 0; strt < n - len + 1; ++strt) {
            string subLet = lane.substr(strt, len);
            if (letters.count(subLet)) {
                works = 0;
                break;
            } else {
                letters.insert(subLet);
            }
        }
        if (works) {
            cout << len;
            return 0;
        }
    }
}