#include <bits/stdc++.h>
using namespace std;
// remember the one case
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFDTER TESTING
    //freopen("mootime.in", "r", stdin);
    int n, f;
    string File;
    cin >> n >> f;
    cin >> File;
    map<string, int> moosFound;
    set<string> realMoos;
    
    for (int i = 0; i <= n - 3; ++i) {
        if (File[i] != File[i + 1] && File[i + 1] == File[i + 2]) {
            string moo = File.substr(i, 3);
            ++moosFound[moo];
            if (moosFound[moo] >= f) {
                realMoos.insert(moo);
            }
        }
    }
    cout << realMoos.size() << '\n';
    for (auto i : realMoos) {
        cout << i << '\n';
    }
}