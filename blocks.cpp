#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> Total(26, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> word1(26,0);
        vector<int> word2(26,0);
        string a, b;
        cin >> a >> b;
        for (char c : a) {
            ++word1[c-'a'];
        }
        for (char c : b) {
            ++word2[c-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            Total[i] += max(word1[i], word2[i]);
        }
    }
    for (int num : Total) {
        cout << num << '\n';
    }
}