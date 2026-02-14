#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> cows(n, 0);
    for (int & i : cows) {
        cin >> i;
    }
    for (int i = n - 1; i > 0; --i) {
        if (cows[i] < cows[i - 1]) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}