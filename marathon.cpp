#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("12.in", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int,int>> pts;
    vector<int> dist;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x>>y;
        pts.push_back({x,y});
    }
    vector<pair<int,int>> ptscopy=pts;
    for (int q=0; q<n; q++) {
        int tempsum=0;
        ptscopy.erase(ptscopy.begin() + q);
        for (int i=0; i<n-1; i++) {
            tempsum += abs(ptscopy[i].first - ptscopy[i+1].first) + abs(ptscopy[i].second - ptscopy[i+1].second);
        }
        dist.push_back(tempsum);
        ptscopy=pts;
    }

    int min_dist = INT_MAX;
    for (int q : dist) {
        if (q < min_dist) {
            min_dist = q;
        }
    }
    cout<<min_dist<<'\n';
    return 0;
}
