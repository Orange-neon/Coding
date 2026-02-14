#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);
    int n, b;
    cin >> n >> b;
    vector<pair<int, int>> yPoints(n);
    vector<pair<int, int>> xPoints(n);
    vector<pair<int, int>> xSortPoints(n);
    vector<pair<int, int>> ySortPoints(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        xPoints[i] = {x, y};
        yPoints[i] = {y, x};
    }
    sort(xPoints.begin(), xPoints.end());
    sort(yPoints.begin(), yPoints.end());
    xSortPoints[0].first = 0;
    xSortPoints[0].second = xPoints[0].second;
    for (int i = 1; i < n; ++i) {
        if (xPoints[i].first == xPoints[i - 1].first) {
            xSortPoints[i].first = xSortPoints[i - 1].first;
        } else {
            xSortPoints[i].first = xSortPoints[i - 1].first + 1;
        }
        xSortPoints[i].second = xPoints[i].second;
    }
    for (int i = 0; i < n; ++i) {
        ySortPoints[i].first = xSortPoints[i].second;
        ySortPoints[i].second = xSortPoints[i].first;
    }
    sort(ySortPoints.begin(), ySortPoints.end());
    ySortPoints[0].first = 0;
    for (int i = 1; i < n; ++i) {
        if (yPoints[i].first == yPoints[i - 1].first) {
            ySortPoints[i].first = ySortPoints[i - 1].first;
        } else {
            ySortPoints[i].first = ySortPoints[i - 1].first + 1;
        }
    }
    //________SOLUTION UNDER SIMPLIFICATION BEFORE______________________________
    /*
    int minXdiff = INT_MAX, xVal, minYdiff = INT_MAX, yVal;
    for (int i = 0; i < ySortPoints.size(); ++i) {
        int j = 0;
        int count = 0;
        while (ySortPoints[j].first <= i) {
            ++j;
            ++count;
        }
        if (abs(n/2.0 - count) < minYdiff) {
            minYdiff = abs(n/2.0 - count);
            yVal = i;
        }
    }
        */
    for (int i = 0; i < n; ++i) {
        xSortPoints[i].first = ySortPoints[i].second;
        xSortPoints[i].second = ySortPoints[i].first;
    }
    sort(xSortPoints.begin(), xSortPoints.end());
    /*
    cout << "POINTS GOTTEN: AFTER SIMPLFICATION: \n";
    for (const auto& paoint : xSortPoints) {
        cout << paoint.first << ", " << paoint.second << '\n';
    }
    cout <<"\n\n ___ \n\n";
    for (int i = 0; i < xSortPoints.size(); ++i) {
        int j = 0;
        int count = 0;
        while (xSortPoints[j].first <= i) {
            ++j;
            ++count;
        }
        if (abs(n/2.0 - count) < minXdiff) {
            minXdiff = abs(n/2.0 - count);
            xVal = i;
        }
    }
        */
    int ans = INT_MAX;
    for (int xVal = 0; xVal < xSortPoints.size(); ++xVal) {
        for (int yVal = 0; yVal < ySortPoints.size(); ++yVal) {
            int i = 0, ii = 0, iii = 0, iv = 0;
            for (const auto& pair : xSortPoints) {
                if (pair.first > xVal && pair.second > yVal) {
                    ++i;
                } else if (pair.first > xVal && pair.second <= yVal) {
                    ++iv;
                } else if (pair.first <= xVal && pair.second <= yVal) {
                    ++iii;
                } else {
                    ++ii;
                }
            }
            ans = min(ans, max(max(i, ii), max(iii, iv)));
        }
    }
    cout << ans;
}