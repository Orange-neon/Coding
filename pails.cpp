#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TEWSTING
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m, xi = 0, yi = 0, minDist = INT_MAX;
    cin >> x >> y >> m;
    while (x * xi <= m) {
        while (y * yi <= m) {
            int num = x * xi + y * yi;
            if (num <= m) {
                if (m - num == 0) {
                    cout << m;
                    return 0;
                } else {
                    minDist = min(minDist, m - num);
                }
                ++yi;
            } else {
                break;
            }
        }
        ++xi;
        yi = 0;
    }
    cout << m - minDist;
}