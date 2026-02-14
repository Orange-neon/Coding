#include<bits/stdc++.h>
using namespace std;
int maxDistLoc(vector<int> cows, bool sizeOnly) {
    int loc = cows.size() / 2, maxD = 0;
    int strt = -1, end = -1;
    for (int i = 0; i < cows.size(); ++i) {
        if (cows[i] == 0 && strt == -1) {
            strt = i;
        } else if (cows[i] == 1 && i != 0 && cows[i - 1] == 0) {
            end = i - 1;
            if (end - strt + 1> maxD) {
                maxD = end - strt + 1;
                loc = (end + strt) / 2;
            }
            strt = -1;
        }
    }
    if (cows[cows.size() - 1] == 0) {
        end = cows.size() - 1;
        if (end - strt + 1> maxD) {
            maxD = end - strt + 1;
            loc = (end + strt + 1) / 2;
        }
    }
    if (sizeOnly) {
        return maxD;
    }
    return loc;
}

int minDist(vector<int> cows) {
    int minD = INT_MAX;
    int tempD = 0;
    for (int i = 0; i < cows.size(); ++i) {
        if (cows[i] == 0) {
            ++tempD;
        } else if (cows[i] == 1 && i != 0 && cows[i - 1] == 0) {
            minD = min(minD, tempD);
            tempD = 0;
        }
    }
    minD = min(minD, tempD);
    return minD;
}

int main() {
    freopen("test.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> test(n, 0);
    for (int& i : test) {
        cin >> i;
    }
    cout << minDist(test);
}