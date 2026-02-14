#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int direct = abs(b - a), teling = abs(min(a, b) - min(x, y)) + abs(max(a, b) - max(x, y));
    cout << min(direct, teling);
}