#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    freopen("waitingTime.in", "r", stdin);
    int n, k, Time = 0;
    cin >> n >> k;
    vector<int> needs;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        needs.push_back(x);
        q.push({x, i});
    }
    while (needs[k] > 0) {
        ++Time;
        auto head = q.front();
        q.pop();
        if (head.first - 1 != 0) {
            q.push({head.first - 1, head.second});
        }
        --needs[head.second];
    }
    cout << Time;
}