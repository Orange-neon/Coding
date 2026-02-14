#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<vector<char>> field;
int r,c, paths=0;

void findpaths(int x, int y, char prev_state) {
    if (x>=r-1 || y>=c-1) {
        return;
    }
    for (int xc=x+1; xc<r; xc++) {
        for (int yc=y+1; yc<c; yc++) {
            if (field[xc][yc] != prev_state) {
                if (xc == r-1 && yc == c-1) {
                    paths++;
                } else {
                    //cout<<'\n'<<"oo oo ah ah point at (" << xc << "," << yc << ")\n";
                    //cout << "Previous state: " << prev_state << "\n";
                    findpaths(xc, yc, field[xc][yc]);
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("2.in", "r", stdin);
    cin >> r >> c;
    field.resize(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> field[i][j];
        }
    }
    findpaths(0, 0, field[0][0]);
    cout << paths;
    return 0;
}