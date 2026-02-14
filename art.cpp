#include<bits/stdc++.h>
using namespace std;
struct Block {
    pair<int, int> heightPts;
    pair<int, int> widthPts;
    int color = -1;
};
int n, nColors = 0, nRect = 0;
vector<vector<int>> canvas(n, vector<int>(n, 0));
vector<Block> blocks(9, {{INT_MAX, -1}, {INT_MAX, -1}});

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    cin >> n;
    canvas.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            int color = c - '0';
            canvas[i][j] = color - 1;
            if (color != 0) {
                if (blocks[color - 1].heightPts.first > i) {
                    blocks[color - 1].heightPts.first = i;
                }
                if (blocks[color - 1].heightPts.second < i) {
                    blocks[color - 1].heightPts.second = i;
                }
                if (blocks[color - 1].widthPts.first > j) {
                    blocks[color - 1].widthPts.first = j;
                }
                if (blocks[color - 1].widthPts.second < j) {
                    blocks[color - 1].widthPts.second = j;
                }
                blocks[color - 1].color = color - 1;
            }
        }
    }
    for (Block& block : blocks) {
        if (block.heightPts.second != -1) {
            for (int y = block.heightPts.first; y <= block.heightPts.second; ++y) {
                for (int x = block.widthPts.first; x <= block.widthPts.second; ++x) {
                    if (canvas[y][x] != block.color) {
                        blocks[canvas[y][x]].color = -1;
                    }
                }
            }
        }
    }
    for (Block& block : blocks) {
        if (block.color != -1) {
            ++nRect;
        }
    }
    cout << nRect;
}