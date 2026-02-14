#include <bits/stdc++.h>
using namespace std;
int countSames(vector<int>& changed, vector<int>& original) {
    int sames = 0;
    for (int i = 0; i < changed.size(); ++i) {
        if (changed[i] == original[i]) {
            ++sames;
        }
    }
    return sames;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("checkups.in", "r", stdin);
    int n, baseSame;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> ans(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    baseSame = countSames(a, b);
    //ODD GROUPS (1, 2, 3), (1), (3,4,5,6,7)
    for (int mid = 0; mid < n; ++mid) {
        int extend = 0, newS = 0, unS = 0;
        while (mid + extend < n && mid - extend >=0) {
            if (a[mid + extend] == b[mid + extend] && b[mid - extend] != b[mid + extend]) {
                ++unS;
            }
            if (a[mid - extend] == b[mid - extend] && b[mid + extend] != b[mid - extend]) {
                ++unS;
            }
            if (a[mid + extend] != b[mid + extend] && a[mid + extend] == b[mid - extend]) {
                ++newS;
            }
            if (a[mid - extend] != b[mid - extend] && a[mid - extend] == b[mid + extend]) {
                ++newS;
            }
            ++ans[baseSame + newS - unS];
            ++extend;
        }
    }
    //EVEN GROUPS (1, 2), (3,4,5,6)
    for (int mid = 0; mid < n - 1; ++mid) {
        int extend = 1, newS = 0, unS = 0;
        while (mid + extend < n && mid - extend + 1>=0) {
            if (a[mid + extend] == b[mid + extend] && b[mid - extend + 1] != b[mid + extend]) {
                ++unS;
            }
            if (a[mid - extend + 1] == b[mid - extend + 1] && b[mid + extend] != b[mid - extend + 1]) {
                ++unS;
            }
            if (a[mid + extend] != b[mid + extend] && a[mid + extend] == b[mid - extend + 1]) {
                ++newS;
            }
            if (a[mid - extend + 1] != b[mid - extend + 1] && a[mid - extend + 1] == b[mid + extend]) {
                ++newS;
            }
            ++ans[baseSame + newS - unS];
            ++extend;
        }
    }
    for (int i : ans) {
        cout << i << '\n';
    }
}