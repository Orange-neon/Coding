#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMET NOUT AFTER TWSING
    //freopen("cannon.in", "r", stdin);
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> line(n);
    int cowPos = s - 1;
    int ans = 0;
    bool noTarget = 1;
    pair<int, int> cowV = {1, 1};
    for (int i = 0; i < n; ++i) {
        cin >> line[i].first >> line[i].second;
        if (line[i].first == 1) {
            noTarget = 0;
        }
    }
    if (noTarget) {
        cout << 0;
        return 0;
    }
    while (cowPos >= 0 && cowPos < n) {
        if (line[cowPos].first == 0) {
            cowV.first += line[cowPos].second;
            cowV.second *= -1;
        } else if (line[cowPos].first == 1) {
            if (cowV.first >= line[cowPos].second) {
                ++ans;
                line[cowPos].first = -1;
            }
        }
        cowPos += cowV.first * cowV.second;
    }
    cout << ans;
}