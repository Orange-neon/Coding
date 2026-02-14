#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Comment out after testing
    freopen("war.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m ,k;
        cin >> n >> m >> k;
        int x = (m + 1) / 3, rem = (m + 1) % 3;
        int leftEx = min(x, k - 1);
        int rightEx = min(x, n - k);
        cout << min((leftEx + rightEx + 1  + rem / 2), n) << '\n';
    }
}