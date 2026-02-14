#include<bits/stdc++.h>
using namespace std;
int ifValidthenArea(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int valid = -1, right;
    if (a.first == b.first && a.second == c.second) {
        valid = 1;
        right = 0;
    } else if (a.first == c.first && a.second == b.second) {
        valid = 1;
        right = 0;
    } else if (b.first == c.first && b.second == a.second) {
        valid = 1;
        right = 1;
    } else if (b.first == a.first && b.second == c.second) {
        valid = 1;
        right = 1;
    } else if (c.first == a.first && c.second == b.second) {
        valid = 1;
        right = 2;
    } else if (c.first == b.first && c.second == a.second) {
        valid = 1;
        right = 2;
    }
    if (valid == -1) {
        return valid;
    }
    if (right == 0) {
        return (abs(a.first - b.first) + abs(a.second - b.second)) * (abs(a.first - c.first) + abs(a.second - c.second));
    } else if (right == 1) {
        return (abs(b.first - c.first) + abs(b.second - c.second)) * (abs(b.first - a.first) + abs(b.second - a.second));
    } else {
        return (abs(c.first - b.first) + abs(c.second - b.second)) * (abs(c.first - a.first) + abs(c.second - a.second));
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    for (int a = 0; a < n - 2; ++ a) {
        for (int b = a + 1; b < n - 1; ++ b) {
            for (int c = b + 1; c < n; ++c) {
                if (ifValidthenArea(points[a], points[b], points[c]) != -1) {
                    maxArea = max(maxArea, ifValidthenArea(points[a], points[b], points[c]));
                }
            }
        }
    }
    cout << maxArea;
}