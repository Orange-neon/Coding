#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    freopen("eradicateTheVirus.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> virusStrengths(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> virusStrengths[i];
    }
    queue<int> scan;
    int scanSum = 0, greatScanLen = 0;
    for (int i : virusStrengths) {
        scan.push(i);
        scanSum += i;
        if (scanSum <= k) {
            greatScanLen = max(greatScanLen, int(scan.size()));
        } else {
            scanSum -= scan.front();
            scan.pop();
        }
    }
    cout << greatScanLen;
}