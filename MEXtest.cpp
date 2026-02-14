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
    freopen("test.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << MEX(v);
}