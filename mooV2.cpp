#include <bits/stdc++.h>
using namespace std;
// remember the one case
bool isValid(string substrin, string item) {
    return ((substrin[0] == item[0] && substrin[1] == item[1] && substrin[2] != '/') || (substrin[0] == item[0] && substrin[2] == item[2] && substrin[1] != '/') || (substrin[1] == item[1] && substrin[2] == item[2] && substrin[0] != '/'));
}
string generateAlpha(string a, int i) {
    int ascii_val = 97 + i;
    string rtn = a;
    rtn[0] = char (ascii_val);
    return rtn;
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
    map<string, pair<int, vector<int>>> countMoosFound;
    set<string> bessieMoos;
    vector<string> lookFormo_s;
    if (f != 1) {
        for (int i = 0; i < n - 2; ++i) {
            if (File[i] != File[i + 1] && File[i + 1] == File[i + 2]) {
                string moo = File.substr(i, 3);
                ++countMoosFound[moo].first;
                countMoosFound[moo].second.push_back(i);
                if (countMoosFound[moo].first == f - 1) {
                    lookFormo_s.push_back(moo);
                } else if (countMoosFound[moo].first == f) {
                    bessieMoos.insert(moo);
                    lookFormo_s.erase(remove(lookFormo_s.begin(), lookFormo_s.end(), moo));
                }
            }
        }
        for (string possibileMoo : lookFormo_s) {
            //replaceing ALL found moo's to ///
            for (int start : countMoosFound[possibileMoo].second) {
                for (int i = 0; i < 3; ++i) {
                    fcopy[start + i] = '/';
                }
            }
            for (int i = 0; i < n - 2; ++i) {
                string testMoo = fcopy.substr(i, 3);
                if (isValid(testMoo, possibileMoo)) {
                    bessieMoos.insert(possibileMoo);
                }
            }
            fcopy = File;
        }
        cout << bessieMoos.size() << '\n';
        for (auto moo : bessieMoos) {
            cout << moo << '\n';
        }
    } else {
        for (int i = 0; i < n - 2; ++i) {
            string testMoo = File.substr(i, 3);
            if (testMoo[1] == testMoo[2]) {
                for (int j = 0; j < 26; ++j) {
                    if (char (j + 97) != testMoo[1]) {
                        bessieMoos.insert(generateAlpha(testMoo, j));
                    }
                }
            } else {
                string endChange = testMoo;
                endChange[2] = endChange[1]; 
                bessieMoos.insert(endChange);
                endChange = testMoo;
                endChange[1] = endChange[2]; 
                bessieMoos.insert(endChange);
            }
        }
        cout << bessieMoos.size() << '\n';
        for (auto moo : bessieMoos) {
            cout << moo << '\n';
        }
    }
}