#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cstdio>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("10.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> pts;
    set<pair<int,int>> pos;
    for (int q = 0; q < n; q++) {
        vector<char> row;
        for (int w = 0; w < m; w++) {
            char c;
            cin >> c;
            row.push_back(c);
        }
        pts.push_back(row);
    }
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            if (y==0) {
                if (pts[y][x] == '.' && pts[y+1][x] == '.' && pts[y+2][x] == '.') {
                    pos.insert(make_pair(y+1, x+1));
                }
            }
            else if (y<n-2) {
                if (pts[y][x] == '.' && pts[y+1][x] == '.' && pts[y+2][x] == '.' && pts[y-1][x] == '#') {
                    pos.insert(make_pair(y+1, x+1));
                }
            }
            if (x==0) {
                if (pts[y][x] == '.' && pts[y][x+1] == '.' && pts[y][x+2] == '.') {
                    pos.insert(make_pair(y+1, x+1));
                }
            }
            else if (x<m-2) {
                if (pts[y][x] == '.' && pts[y][x+1] == '.' && pts[y][x+2] == '.' && pts[y][x-1] == '#') {
                    pos.insert(make_pair(y+1, x+1));
                }
            }
        }
    }
    cout << pos.size() << '\n';
    //for (const auto& p : pos) {
 //       cout << p.first << ' ' << p.second << '\n';
 //   }
    return 0;
}
