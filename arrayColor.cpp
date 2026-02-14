#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //CPMMETNEG IETRG
    //freopen("arrC.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, state = 1;
        cin >> n;
        vector<pair<int, int>> colors1(n, {0,1});
        vector<pair<int, int>> colors2(n, {0,1});
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            colors1[i].first = num;
            colors1[i].second = state;
            colors2[i].first = num;
            colors2[i].second = -1 * state;
            state *= -1;
        }
        sort(colors1.begin(), colors1.end());
        sort(colors2.begin(), colors2.end());
        int prevState1 = 0;
        int prevState2 = 0;
        bool one = true, two = true;
        for (int i = 0; i < n; ++i) {
            if (colors1[i].second != prevState1) {
                prevState1 = colors1[i].second;
            } else {
                one = false;
            }

            if (colors2[i].second != prevState2) {
                prevState2 = colors2[i].second;
            } else {
                two = false;
            }
        }
        if (one || two) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}