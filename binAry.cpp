#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENTOUT AFTER TSTGIN
    //freopen("binAry.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, strt, end;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (i == 0) {
                strt = x;
            } else if (i == n - 1) {
                end = x;
            }
        }
        if (strt == end && strt == 0) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}