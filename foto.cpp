#include<bits/stdc++.h>
using namespace std;
vector<int> Save;
pair<int, int> switchAC(vector<int> cows) {
    int oC = 0, eC = 0, last = 0;
    for (int i = 0; i < cows.size(); ++i) {
        if (cows[i] == 1) {
            if (i % 2 == 1) {
                ++eC;
            } else {
                ++oC;
                last = i;
            }
        }
    }
    if (eC == cows.size() / 2) {
        return {-2, 0};
    }
    if (oC > eC) {
        return {last, 0};
    } else if (oC < eC && cows != Save) {
        return {-2, 0};
    } else {
        return {-1, last};
    }
}
void swap(int end, vector<int> & cows) {
    for (int i = 0; i < end / 2 + 1; ++i) {
        swap(cows[i], cows[end - i]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMEMNT OTA RFET DETESTING
    //freopen("foto.in", "r", stdin);
    int n, ct = 0, firstGs = 0, goodGs = 0;
    cin >> n;
    vector<int> cows(n, 0);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'G') {
            cows[i] = 1;
            ++firstGs;
            if (i % 2 == 1) {
                ++goodGs;
            }
        }
    }
    if (goodGs == firstGs) {
        cout << 0;
        return 0;
    }
    for (int i = n - 2; i >= 0 ; i -= 2) {
        if (cows[i] == cows[i + 1]) {
            continue;
        } else if (cows[i] == 0) {
            if (ct % 2 == 0) {
                continue;
            }
            ++ct;
        } else if (cows[i] == 1) {
            if (ct % 2 == 1) {
                continue;
            }
            ++ct;
        }
    }
    cout << ct;
}