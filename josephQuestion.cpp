#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    freopen("josephQuestion.in", "r", stdin);
    int n, x;
    cin >> n >> x;
    vector<int> ppl;
    vector<int> outPUT;
    int countIndex = 0;
    for (int i = 0; i < n; ++i) {
        ppl.push_back(i);
    }
    while (!ppl.empty()) {
        countIndex = (countIndex + x - 1) % ppl.size();
        outPUT.push_back(ppl[countIndex]);
        ppl.erase(ppl.begin() + countIndex);
    }
    for (int i : outPUT) {
        cout << i + 1 << " ";
    }
}