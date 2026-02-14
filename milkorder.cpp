#include <bits/stdc++.h>
using namespace std;
int getFirstSpace(vector<int> line, int strt) {
    for (int i = strt; i < line.size(); ++i) {
        if (line[i] == -1) {
            return i;
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> cowsOrder;
    vector<int> numberL(n, -1);
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        cowsOrder.push_back({c, -1});
    }
    for (int i = 0; i < k; ++i) {
        int cow, place;
        cin >> cow >> place;
        if (cow == 1) {
            cout << place;
            return 0;
        }
        numberL[place - 1] = cow;
        if (find(cowsOrder.begin(), cowsOrder.end(), make_pair(cow, -1)) != cowsOrder.end()) {
            cowsOrder[distance(cowsOrder.begin(), find(cowsOrder.begin(), cowsOrder.end(), make_pair(cow, -1)))].second = --place;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (numberL[i] == -1) {
            numberL[i] = 1;
            if (find(cowsOrder.begin(), cowsOrder.end(), make_pair(1, -1)) != cowsOrder.end()) {
                cowsOrder[distance(cowsOrder.begin(), find(cowsOrder.begin(), cowsOrder.end(), make_pair(1, -1)))].second = i;
            }
            bool works = 1;
            int pos = 0;
            //check 
            auto numberLc = numberL;
            for (const auto& cowLoc : cowsOrder) {
                if (cowLoc.second == -1 && getFirstSpace(numberLc, pos) >= pos) {
                    pos = getFirstSpace(numberLc, pos);
                    numberLc[pos] = cowLoc.first; // ??????
                } else if (cowLoc.second != -1) {
                    if (pos > cowLoc.second) {
                        works = 0;
                        break;
                    }
                    pos = cowLoc.second;
                    numberLc[pos] = 0;
                }
            }
            if (works) {
                cout << i + 1;
                return 0;
            }
            numberL[i] = -1;
            if (find(cowsOrder.begin(), cowsOrder.end(), make_pair(1, i)) != cowsOrder.end()) {
                cowsOrder[distance(cowsOrder.begin(), find(cowsOrder.begin(), cowsOrder.end(), make_pair(1, i)))].second = -1;
            }
        }
    }
}