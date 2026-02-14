#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OU AFTER DEGUBUGG
    //freopen("cowCanes.in", "r", stdin);
    long long n, m;
    cin >> n >> m;
    long long maxCow = 0;
    vector<long long> cows;
    vector<long long> replacedCIdx;
    vector<long long> Ocows;
    for (long long i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        cows.push_back(x);
        if (x > maxCow) {
            maxCow = x;
            Ocows.push_back(x);
            replacedCIdx.push_back(i);
        }
    }
    for (long long i = 0; i < m; ++i) {
        pair<long long, long long> caneH;
        cin >> caneH.second;
        caneH.first = 0;
        for (long long& cowH : Ocows) {
            if (cowH > caneH.second && caneH.second != 0) {
                cowH += caneH.second - caneH.first;
                caneH = {0,0};
                break;
            } else if (cowH > caneH.first && caneH.second != 0) {
                long long beforeH = cowH;
                cowH += cowH - caneH.first;
                caneH = {beforeH, caneH.second};
            }
        }
    }
    long long inc = 0;
    for (long long i : replacedCIdx) {
        cows[i] = Ocows[inc];
        ++inc;
    }
    for (long long cowH : cows) {
        cout << cowH << '\n';
    }
}