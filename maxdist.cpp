#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OU AFTER TESTING
    //freopen("maxdist.in", "r", stdin);
    int n;
    cin >> n;
    vector<long long> xs;
    vector<long long> ys;
    vector<long long> dists(0, -1);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            long long a;
            cin >> a;
            if (i == 0) {
                xs.push_back(a);
            } else {
                ys.push_back(a);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            dists.push_back(pow((xs[j]-xs[i]), 2) + pow((ys[j]-ys[i]), 2));
        }
    }
    cout << *max_element(dists.begin(), dists.end());
}