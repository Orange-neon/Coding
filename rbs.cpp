#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("rbs.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, zeroC = 0;
        bool zeroF = false, flag = false;
        cin >> n;
        vector<int> code;
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            if (c == '(') {
                code.push_back(1);
            } else {
                code.push_back(0);
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (code[i] == 0) {
                zeroF = true;
                ++zeroC;
            }

            if (zeroF && code[i] == 1 && code[i + 1] == 1) {
                cout << n - 2*zeroC << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << -1 << '\n';
        }
    }
}