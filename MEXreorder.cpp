#include<bits/stdc++.h>
using namespace std;
int MEX(vector<int> v) {
    int countUp = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0) {
            if (v[i] != 0) {
                return 0;
            }
            ++countUp;
        } else {
            if (v[i] == v[i - 1]) {
                continue;
            } else if (v[i] != countUp) {
                return countUp;
            } else {
                ++countUp;
            }
        }
    }
    return countUp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OU FETOE
    //freopen("test.in", "r", stdin);
    int t;
    cin >> t;
    for (int l = 0; l < t; ++l) {
        int n;
        bool flag = 0;
        cin >> n;
        vector<int> nums(n, 0);
        for (int& j : nums) {
            cin >> j;
        }
        sort(nums.begin(), nums.end());
        vector<int> strt;
        vector<int> end = nums;
        for (int i = 0; i < n - 1; ++i) {
            strt.push_back(nums[i]);
            end.erase(end.begin());
            int a, b;
            if (end[0] != 0) {
                b = 0;
            } else {
                b = MEX(end);
            }
            a = MEX(strt);
            if (a == b) {
                cout << "NO\n";
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << "YES\n";
        }
    }
}