#include <bits/stdc++.h>
using namespace std;
void vetFlip(vector<int>& order, int start, int end) {
    while (start <= end) {
        swap(order[start], order[end]);
        ++start;
        --end;
    }
}
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
    int n;
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
    for (int first = 0; first < n; ++first) {
        for (int second = first; second < n; ++second) {
            vector<int> newv = a;
            vetFlip(newv, first, second);
            ++ans[countSames(newv, b)];
        }
    }
    for (int i : ans) {
        cout << i << '\n';
    }
}