#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("circlecross.in", "r", stdin);
    //UNCOMENT OT AFETER EGUBUGNI
    freopen("circlecross.out", "w", stdout);
    string log;
    cin >> log;
    set<char> tested;
    int count = 0;
    for (int i = 0; i < log.size() - 1; ++i) {
        if (!tested.count(log[i])) {
            set<char> seen;
            seen.insert(log[i]);
            for (int j = i + 1; j < log.size(); ++j) {
                if (!seen.count(log[j]) && log[j] != log[i]) {
                    seen.insert(log[j]);
                    ++count;
                } else if (log[j] == log[i]) {
                    tested.insert(log[i]);
                    break;
                } else if (seen.count(log[j])) {
                    --count;
                    seen.erase(log[j]);
                }
            }
        }
    }
    cout << (count / 2);
}