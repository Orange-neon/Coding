#include <bits/stdc++.h>
using namespace std;
int n, u;
vector<vector<int>> canvas(n, vector<int>(n, 0));
//Both work
pair<int, int> xReflect(int x, int y) {
    return {int(((n-1.0)/2.0 - x) + (n-1.0)/2.0), y};
}
pair<int, int> yReflect(int x, int y) {
    return {x, int(((n-1.0)/2.0 - y) + (n-1.0)/2.0)};
}
int test(int x, int y) {
    int rtn = 0;
    rtn += canvas[y][x];
    rtn += canvas[xReflect(x, y).second][xReflect(x, y).first];
    rtn += canvas[yReflect(x, y).second][yReflect(x, y).first];
    rtn += canvas[xReflect(yReflect(x, y).first, yReflect(x, y).second).second][xReflect(yReflect(x, y).first, yReflect(x, y).second).first];
    return rtn;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int neededChanges = 0;
    //COMMENT OUTJ AFTRET TETSGNI
    //freopen("reflection.in", "r", stdin);
    cin >> n >> u;
    canvas.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '#') {
                canvas[i][j] = 1;
            } else {
                canvas[i][j] = 0;
            }
        }
    }
    for (int i = 0; i <= (n - 1)/2; ++i) {
        for (int j = 0; j <= (n-1)/2; ++j) {
            if (test(j, i) == 3) {
                neededChanges += 1;
            } else {
                neededChanges += test(j, i) % 4;
            }
        }
    }
    cout << neededChanges << '\n';
    for (int i = 0; i < u; ++i) {
        int nx, ny;
        cin >> ny >> nx;
        --nx;
        --ny;
        if (test(nx, ny) == 3) {
            neededChanges -= 1;
        } else {
            neededChanges -= test(nx, ny) % 4;
        }
        canvas[ny][nx] = (canvas[ny][nx] + 1) % 2;
        if (test(nx, ny) == 3) {
            neededChanges += 1;
        } else {
            neededChanges += test(nx, ny) % 4;
        }
        cout << neededChanges << '\n';
    }
}