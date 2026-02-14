#include <bits/stdc++.h>
using namespace std;
string maxMapkey(map<string, int>& numFacts) {
    int maxVal = 0;
    string maxKey;
    for(const auto& pair : numFacts) {
        if (pair.second > maxVal) {
            maxVal = pair.second;
            maxKey = pair.first;
        }
    }
    return maxKey;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<vector<string>> facts(n);
    vector<bool> posAnimals(n, true);
    int possibles = n;
    map<string, int> numFacts;
    for (int i = 0; i < n; ++i) {
        string temp;
        int k;
        cin >> temp >> k;
        for (int j = 0; j < k; ++j) {
            string fact;
            cin >> fact;
            ++numFacts[fact];
            facts[i].push_back(fact);
        }
    }
    while (possibles != 1 && ans <= n) {
        string need = maxMapkey(numFacts);
        numFacts[need] = 0;
        for (int i = 0; i < facts.size(); ++i) {
            if (posAnimals[i]) {
                auto animal = facts[i];
                bool containsMaxkey = 0;
                vector<string> animalFeatures;
                for (auto feature : animal) {
                    animalFeatures.push_back(feature);
                    if (feature == need) {
                        containsMaxkey = 1;
                        break;
                    }
                }
                if (!containsMaxkey) {
                    posAnimals[i] = 0;
                    --possibles;
                    for (auto feature : animalFeatures) {
                        --numFacts[feature];
                    }
                }
            }
        }
        ++ans;
    }
    cout << ans;
}