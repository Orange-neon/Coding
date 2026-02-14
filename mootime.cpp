#include <bits/stdc++.h>
using namespace std;
// remember the one case
bool isValid(string substrin, string item) {
    return ((substrin[0] == item[0] && substrin[1] == item[1] && substrin[2] != '/') || (substrin[0] == item[0] && substrin[2] == item[2] && substrin[1] != '/') || (substrin[1] == item[1] && substrin[2] == item[2] && substrin[0] != '/'));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    //freopen("mootime.in", "r", stdin);
    int n, f;
    string File, fcopy;
    cin >> n >> f;
    cin >> File;
    fcopy = File;
    map<string, int> moosFound;
    set<pair<string, int>> realMoos;
    map<string, int> possMooFounds;
    set<string> newMoos;
    
    for (int i = 0; i < n - 2; ++i) {
        if (File[i] != File[i + 1] && File[i + 1] == File[i + 2]) {
            string moo = File.substr(i, 3);
            ++moosFound[moo];
            realMoos.insert({moo, i});
            if (moosFound[moo] >= f) {
                newMoos.insert(moo);
            }
        }
    }
    for (auto item : realMoos) {
        fcopy = File;
        //replacing the found "moo" to a ///
        for (int i = 0; i < 3; ++i) {
            fcopy[item.second + i] = '/';
        }
        for (int i = 0; i < n - 2; ++i) {
            string section = fcopy.substr(i, 3);
            if (isValid(section, item.first)) {
                ++possMooFounds[section];
                if (possMooFounds[section] >= f - 1) {
                    newMoos.insert(item.first);
                    break;
                }
            }
        }
    }
    /*
    for (auto a : possMooFounds) {
        cout << a.first << '\n';
    }
    cout <<"okay\n";
    */
    cout << newMoos.size() << '\n';
    for (auto moo: newMoos) {
        cout << moo << '\n';
    }
}