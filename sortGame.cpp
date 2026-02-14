#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("sortGame.in", "r", stdin);
    int t;
    cin >> t;
    for (int l = 0; l < t; ++l) {
        int n, zeros = 0, ones = 0, stopPt;
        bool works = false;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            if (c == '0') {
                nums.push_back(0);
                ++zeros;
            } else {
                nums.push_back(1);
            }
        }
        for (int j = 0; j < n; ++j) {
            int i = nums[j];
            if (i == 1) {
                ++ones;
            } else {
                --zeros;
            }
            if (ones == zeros && ones != 0) {
                works = true;
                stopPt = j;
                break;
            }
        }
        if (works) {
            cout << "Alice\n" << 2 * ones << '\n';
            for (int i = 0; i < n; ++i) {
                if (i <= stopPt) {
                    if (nums[i] == 1) {
                        cout << i + 1 << " ";
                    }
                } else {
                    if (nums[i] == 0) {
                        cout << i + 1 << " ";
                    }
                }
            }
            cout << '\n';
        } else {
            cout << "Bob\n";
        }
    }
}