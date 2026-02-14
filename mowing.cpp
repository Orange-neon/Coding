#include<bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TEWSTING
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    vector<vector<int>> field(3000, vector<int>(3000, 0));
    vector<int> times;
    int n;
    cin >> n;
    int x = 1500, y = 1500;
    field[y][x] = 1;
    for (int i = 0; i < n; ++i) {
        char d;
        int amt;
        cin >> d >> amt;
        int directIndex;
        if (d == 'N') {
            directIndex = 0;
        } else if (d == 'S') {
            directIndex = 1;
        } else if (d == 'W') {
            directIndex = 2;
        } else if (d == 'E') {
            directIndex = 3;
        }
        for (int j = 0; j < amt; ++j) {
            int nx = x + dx[directIndex], ny = y + dy[directIndex];
            if (field[ny][nx] != 0) {
                times.push_back(field[y][x] + 1 - field[ny][nx]);
            }
            field[ny][nx] = field[y][x] + 1;
            x += dx[directIndex];
            y += dy[directIndex];
        }
    }
    if (times.empty()) {
        cout << -1;
    } else {
        cout << *(min_element(times.begin(), times.end()));
    }
}