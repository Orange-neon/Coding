#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("juryMarks.in", "r", stdin);
    int k, n, prev = 0;
    cin >> k >> n;
    set<int> marks;
    for (int i = 0; i < k; ++i) {
        int mark;
        cin >> mark;
        marks.insert(prev + mark);
        prev += mark;
    }
    set<int> scores;
    int firstScore;
    vector<int> possibleStarts;
    for (int i = 0; i < n; ++i) {
        int score;
        cin >> score;
        scores.insert(score);
        if (i == 0) {
            firstScore = score;
        }
    }

    for (int mark : marks) {
        possibleStarts.push_back(firstScore - mark);
    }

    int ans = 0;
    for (int canidate : possibleStarts) {
        int scoreS = 0;
        for (int recordMark : marks) {
            if (scores.count(canidate + recordMark)) {
                ++scoreS;
                if (scoreS == n) {
                    ++ans;
                    break;
                }
            }
        }
    }
    cout << ans;
}