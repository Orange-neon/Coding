#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUTA FTER TEFSGIN
    //freopen("pests.in", "r", stdin);
    int n;
    cin >> n;
    vector<long long> grassH(n);
    for (long long& i : grassH) {
        cin >> i;
    }
    auto grass = grassH;
    long long ans = 0, adds = 0, minuses = 0;
    ans += abs(grass[0]);
    if (grass[0] > 0) {
        minuses += grass[0];
    } else {
        adds += abs(grass[0]);
    }
    grass[0] = 0;
    for (long long i = 1; i < n; ++i) {
        grass[i] += -1 * grassH[i - 1];
        grass[i] += adds - minuses;
        ans += abs(grass[i]);
        int start = grass[i];
        if (start > 0) {
            minuses += start;
        } else {
            adds += abs(start);
        }
        grass[i] = 0;
    }
    cout << ans;
}