#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int a, b, c, m = INT_MAX, M = 0;
    vector<int> inp;
    for (int i = 0; i < 3; ++i) {
        int x;
        cin >> x;
        inp.push_back(x);
    }
    sort(inp.begin(), inp.end());
    a = inp[0];
    b = inp[1];
    c = inp[2];
    if (c - b == 1 && b - a == 1) {
        cout << 0 << '\n' << 0;
        return 0;
    }
    if (b - a == 2 || c - b == 2) {
        m = 1;
    } else {
        m = 2;
    }
    M = max(b - a, c - b) - 1;
    cout << m << '\n' << M;
}