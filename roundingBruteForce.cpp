#include<bits/stdc++.h>
using namespace std;
int roud(int num) {
    string numStr = to_string(num);
    int siz = numStr.size();
    bool fron = 0;
    while (numStr.find('4') != numStr.npos) {
        if (numStr.find('4') == 0) {
            fron = 1;
        }
        if (numStr.find('4') != numStr.size() - 1 && (fron) && numStr[numStr.find('4') + 1] >= 53) {
            return num;
        } else if (numStr[numStr.find('4') + 1] < 52) {
            return -1;
        } else {
            numStr[numStr.find('4')] = '3';
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    //freopen("rounding.in", "r", stdin);
    int t;
    set<int> failed;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        for (int num = 2; num <= n; ++num) {
            if (roud(num) != -1) {
                failed.insert(num);
            }
        }
        cout << failed.size() << '\n';
        failed.clear();
    }
    
    //cout << roud(4400);
}