#include <bits/stdc++.h>
using namespace std;
vector<string> maxMapkey(map<string, int>& numFacts) {
    int maxVal = 0;
    vector<string> maxes;
    for(const auto& pair : numFacts) {
        if (pair.second > maxVal) {
            maxVal = pair.second;
        }
    }
    for(const auto& pair : numFacts) {
        if (pair.second == maxVal) {
            maxes.push_back(pair.first);
        }
    }
    return maxes;
}
vector<vector<string>> shrink(vector<vector<string>>& bank, string& mustcontain) {
    vector<vector<string>> rtn;
    for (const auto& animal : bank) {
        bool valid = 0;
        for (string say : animal) {
            if (say == mustcontain) {
                valid = 1;
                break;
            }
        }
        if (valid) {
            rtn.push_back(animal);
        }
    }
    return rtn;
}
int maxYes(vector<vector<string>>& bank, map<string, int>& bankNums, int yeses) {
    if (bank.size() == 1) {
        return yeses;
    }
    auto keys = maxMapkey(bankNums);
    int maxTrue = 0;
    for (auto i : keys) {
        auto newBank = shrink(bank, i);
        int precious = bankNums[i];
        bankNums[i] = 0;
        maxTrue = max(maxTrue, (maxYes(newBank, bankNums, yeses + 1)));
        bankNums[i] = precious;
    }
    return maxTrue;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("guess.in", "r", stdin);
    //freopen("guess.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<vector<string>> facts(n);
    vector<bool> posAnimals(n, true);
    map<string, int> factNums;
    int possibles = n;
    for (int i = 0; i < n; ++i) {
        string temp;
        int k;
        cin >> temp >> k;
        for (int j = 0; j < k; ++j) {
            string fact;
            cin >> fact;
            facts[i].push_back(fact);
            ++factNums[fact];
        }
    }
    cout << maxYes(facts, factNums, 0);
}