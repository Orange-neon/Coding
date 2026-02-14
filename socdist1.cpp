#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n, largestGap = 0, gap = 0, gapStopI = 0;
    int first1 = INT_MAX, last1 = 0;
    pair<int, int> gapsLs;
    cin >> n;
    vector<int> barn;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '0') {
            ++gap;
            barn.push_back(0);
        } else {
            first1 = min(first1, i);
            last1 = max(last1, i);
            if (largestGap < gap) {
                gapStopI = i;
                largestGap = gap;
            }
            gap = 0;
            barn.push_back(1);
        }
    }
    int firstG = first1, lastG = n - last1 - 1, endG;
    if (firstG >= lastG) {
        endG = firstG;
        firstG = -1;
    } else {
        endG = lastG;
        lastG = -1;
    }
    gapsLs.first = max((largestGap + 1)/ 2, endG);
    if (gapsLs.first == endG) {
        if (firstG == -1) {
            barn[0] = 1;
        } else {
            barn[n - 1] = 1;
        }
    } else {
        barn[gapStopI - (largestGap + 1)/ 2] = 1;
    }
    int largestGapS = largestGap; 
    largestGap = 0;
    gap = 0;
    gapStopI = 0;
    for (int i = 0; i < n; ++i) {
        if (barn[i] == 0) {
            ++gap;
        } else {
            if (largestGap < gap) {
                gapStopI = i;
                largestGap = gap;
            }
            gap = 0;
        }
    }
    gapsLs.second = max((largestGap + 1)/ 2, max(firstG, lastG));
    cout << max(min(gapsLs.first, gapsLs.second), ((largestGapS + 1) / 3));
}