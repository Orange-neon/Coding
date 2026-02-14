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
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<int> Original;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        switch(c) {
            case '1':
                Original.push_back(1);
                break;
            default:
                Original.push_back(0);
                break;
        }
    }
    vector<int> copy = Original;
    for (int aPlace = 0; aPlace < 3; ++aPlace) {
        for (int bPlace = 0; bPlace < 3; ++bPlace) {
            copy = Original;
            bool bPlaced = 0;
            if (aPlace == 0 && copy[0] == 0) {
                copy[0] = 1;
                if (bPlace == 2 && copy[n - 1] == 0) {
                    copy[n - 1] = 1;
                    bPlaced = 1;
                } else if (bPlace == 1) {
                    int mDLt = maxDistLoc(copy, 0);
                    copy[mDLt] = 1;
                    bPlaced = 1;
                }

                if (bPlaced) {
                    ans = max(ans, minDist(copy));
                }

            } else if (aPlace == 2 && copy[n - 1] == 0) {
                copy[n - 1] = 1;

                if (bPlace == 0 && copy[0] == 0) {
                    copy[0] = 1;
                    bPlaced = 1;
                } else if (bPlace == 1) {
                    int mDLt = maxDistLoc(copy, 0);
                    copy[mDLt] = 1;
                    bPlaced = 1;
                }

                if (bPlaced) {
                    ans = max(ans, minDist(copy));
                }
                
            } else if (aPlace == 1) {
                int mDL = maxDistLoc(copy, 0);
                copy[mDL] = 1;

                if (bPlace == 0 && copy[0] == 0) {
                    copy[0] = 1;
                    bPlaced = 1;
                } else if (bPlace == 2 && copy[n - 1] == 0) {
                    copy[n - 1] = 1;
                    bPlaced = 1;
                } else if (bPlace == 1) {
                    int mDLt = maxDistLoc(copy, 0);
                    copy[mDLt] = 1;
                    bPlaced = 1;
                }

                if (bPlaced) {
                    ans = max(ans, minDist(copy));
                }
                
            } else {
                break;
            }
        }
    }

    /*
    ===================================================
    -------------Code for 00020002000 case-------------
    ===================================================
    */
    int fromForm = (maxDistLoc(Original, 1) + 1) / 3 - 1;
    ans =  max(ans, fromForm);

    cout << ans + 1;
}