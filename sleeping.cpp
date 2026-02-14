#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("sleeping.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, sum = 0;
        cin >> n;
        vector<int> log(n);
        for (int q = 0; q < n; ++q) {
            int a;
            cin >> a;
            log[q] = a;
            sum += a;
        }
        if (sum == 0) {
            cout << 0;
            continue;
        }
        for (int sameNum = 1; sameNum <= sum; ++sameNum) {
            if (sum % sameNum == 0) {
                int progressingSum = 0;
                bool flag = 0;
                for (int& sleepTimes : log) {
                    progressingSum += sleepTimes;
                    if (progressingSum == sameNum) {
                        progressingSum = 0;
                    } else if (progressingSum > sameNum) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    cout << n - (sum / sameNum) << '\n';
                    break;
                }
            }
        }
    }
}