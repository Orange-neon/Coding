#include <bits/stdc++.h>
using namespace std;
int minQ(queue<int> q) {
    int mi = q.front();
    while (!q.empty()) {
        mi = min(mi, q.front());
        q.pop();
    }
    return mi;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    freopen("monotonicQueue.in", "r", stdin);
    int n, m, currMin = INT_MAX;
    cin >> n >> m;
    queue<int> q;
    vector<int> vals;
    vector<int> mins;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        vals.push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        q.push(vals[i]);
    }
    currMin = minQ(q);
    while (currMin != q.front()) {
        q.pop();
    }
    mins.push_back(currMin);
    for (int i = m; i < n; ++i) {
        if (vals[i] <= currMin) {
            while (!q.empty()) {
                q.pop();
            }
            q.push(vals[i]);
            currMin = vals[i];
        } else if (currMin == q.front() && q.size() == m) {
            q.push(vals[i]);
            q.pop();
            currMin = minQ(q);
            while (currMin != q.front()) {
                q.pop();
            }
        } else if (currMin == q.front()){
            q.push(vals[i]);
        }
        mins.push_back(currMin);
    }
    for (int i = 0; i < mins.size() - 1; ++i) {
        cout << mins[i] << " ";
    }
    cout << mins[mins.size() - 1];
}