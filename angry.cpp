#include<bits/stdc++.h>
using namespace std;
struct Bale {
    int loc;
    bool blasted;
    int blastR;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n, ans = 0;;
    cin >> n;
    vector<int> hay(n);
    for (int& bale : hay) {
        cin >> bale;
    }
    sort(hay.begin(), hay.end());
    vector<Bale> bales;
    for (int i : hay) {
        bales.push_back({i, 0, 0});
    }
    auto Save = bales;
    for (int i = 0; i < n; ++i) {
        bales = Save;
        int test = 1, t = 1, explodeCycle = 0;
        bales[i].blasted = 1;
        bales[i].blastR = t;
        for (int j = i; j < n - 1; ++j) {
            if (bales[j].blasted && !(bales[j + 1].blasted)) {
                if (bales[j].loc + bales[j].blastR >= bales[j + 1].loc) {
                    int tS = t, ext = 1;
                    ++t;
                    for (int k = 1; k <= tS; ++k) {
                        if (j + ext < n && bales[j].loc + k >= bales[j + ext].loc) {
                            ++test;
                            bales[j + ext].blasted = 1;
                            bales[j + ext].blastR = t;
                            ++ext;   
                        }
                    }
                } else {
                    break;
                }
            }
        }
        t = 1;
        for (int j = i; j > 0; --j) {
            if (bales[j].blasted && !(bales[j - 1].blasted)) {
                if (bales[j].loc - bales[j].blastR <= bales[j - 1].loc) {
                    int tS = t, ext = 1;
                    ++t;
                    for (int k = 1; k <= tS; ++k) {
                        if (j - ext >= 0 && bales[j].loc - k <= bales[j - ext].loc) {
                            ++test;
                            bales[j - ext].blasted = 1;
                            bales[j - ext].blastR = t;
                            ++ext;
                        }
                    }
                } else {
                    break;
                }
            }
        }   
        ans = max(ans, test);
    }
    cout << ans;
}