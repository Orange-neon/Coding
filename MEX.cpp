    #include<bits/stdc++.h>
    using namespace std;
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        //COMMENT OUTA FDTER TESTING
        //freopen("MEX.in", "r", stdin);
        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
            int n, k;
            cin >> n >> k;
            set<int> seen;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                seen.insert(x);
            }
            int up = 0;
            while (seen.count(up) && up < k - 1) {
                ++up;
            }
            cout << up << '\n';
        }
    }