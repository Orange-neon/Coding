#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> apples;
long long divide(int appleI, long long a, long long b) {
    if (appleI == n) {
        return abs(a - b);
    }
    a += apples[appleI];
    auto one = divide(appleI + 1, a, b);
    a -= apples[appleI];
    b += apples[appleI];
    auto two = divide(appleI + 1, a, b);
    return min(one, two);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("apple.in", "r", stdin);
    cin >> n;
    apples.resize(n, 0);
    for (auto &h : apples) {
        cin >> h;
    }
    long long at = 0, bt = 0, it = 0;
    cout << divide(it, at, bt);
}