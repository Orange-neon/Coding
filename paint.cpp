#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> painted;
    for (int i = a; i < b; ++i) {
        painted.insert(i);
    }
    for (int i = c; i < d; ++i) {
        painted.insert(i);
    }
    cout << painted.size();
}