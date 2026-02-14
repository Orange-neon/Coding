#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMME TOUT AFTERTE TESIGN
    //freopen("3.in", "r", stdin);
    int n, ans = 0, lastG = 0;
    cin >> n;
    vector<int> start(n, 0);
    vector<int> end(n, 0);
    set<int> bad;
    map<int, int> posInEnd;
    for (int i = 0; i < n; ++i) {
        int cow;
        cin >> cow;
        start[i] = cow;
    }
    for (int i = 0; i < n; ++i) {
        int cow;
        cin >> cow;
        end[i] = cow;
        posInEnd[cow] = i;
    }
    for (int i = 0; i < start.size() - 1; ++i) {
        if (!bad.count(start[i])) {
            lastG = i;
        }
        if (posInEnd[start[lastG]] < posInEnd[start[i + 1]]) {
            continue;
        } else {
            bad.insert(start[i + 1]);
            ++ans;
        }
    }
    cout << ans;
}