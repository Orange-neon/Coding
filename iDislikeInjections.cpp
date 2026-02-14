#include <bits/stdc++.h>
using namespace std;
// REMEMBER TO ADD ONE FOR OUTPUT
queue<int> q;
vector<int> order;
void runBehavior() {
    int inject = q.front();
    order.push_back(inject);
    q.pop();
    int run = q.front();
    q.pop();
    q.push(run);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Comment out after testing
    freopen("iDislikeInjections.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        q.push(i);
    }
    while (q.size() > 2) {
        runBehavior();
    }
    order.push_back(q.front());
    q.pop();
    order.push_back(q.front());
    for (int i : order) {
        cout << i + 1 << " ";
    }
}