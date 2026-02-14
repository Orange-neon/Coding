#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 4; ++i) {
        int x, y;
        cin >> x >> y;
        if (i == 0) {
            continue;
        }
        if (i == 1) {
            a += y - x;
        } 
        if (i == 2) {
            a += y - x;
            b += y - x;
        } 
        if (i == 3) {
            a += y - x;
            b += y - x;
            c += y - x;
        }
    }
    cout << a << '\n' << b << '\n' << c;
}