#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("christmasTree.in", "r", stdin);
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        double b, h;
        double ans = 0, adjust = 0;
        cin >> n >> b >> h;
        double area = (b * h) / 2.0;
        ans = n * area;
        vector<int> baseHeights(n);
        for (int& height : baseHeights) {
            cin >> height;
        }
        for (int i = 1; i < n; ++i) {
            if (baseHeights[i] - baseHeights[i - 1] < h) {
                double overlapH = baseHeights[i - 1] + h - baseHeights[i];
                adjust += area * (overlapH / h) * (overlapH / h);
            }
        }
        cout << setprecision(20) << ans - adjust << '\n';
     }
}