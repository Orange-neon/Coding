#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crossroad.in", "r", stdin);
    //COMEMNTOU IN AFETE REBFFUHGO
    freopen("crossroad.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    map<int, int> cowsLog = {};
    for (int i = 0; i < n; ++i) {
        int ID, loc;
        cin >> ID >> loc;
        if (!cowsLog.count(ID)) {
            cowsLog[ID] = loc;
        } else if (cowsLog[ID] != loc) {
            ++ans;
            cowsLog[ID] = loc;
        }
    }
    cout << ans;
}