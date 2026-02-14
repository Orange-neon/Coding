#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMEMENTNOUT AFTETRET
    freopen("madeUp.in", "r", stdin);
    int n, ans = 0;
    cin >> n;
    vector<int> a;
    map<int, vector<int>> bIntToPoses;
    map<int, int> bPosToInt;
    map<int, int> cIntToCount;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            switch (i) {
                case 0:
                    a.push_back(x);
                    break;
                case 1:
                    bIntToPoses[x].push_back(j);
                    bPosToInt[j] = x;
                    break;
                default:
                    ++cIntToCount[x];
            }
        }
    }
    for (int i : a) {
        for (int pos : bIntToPoses[i]) {
            ans += cIntToCount[bPosToInt[pos]];
        }
    }
    cout << ans;
}