#include<bits/stdc++.h>
using namespace std;
int sideL;
void printBoard(int a, int b, int c, int d, int x, int y, int type) {
    cout << sideL << '\n';
    switch (type) {
        case 0:
            for (int j = 0; j < b; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << "A";
                }
                cout << '\n';
            }
            for (int j = 0; j < d; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << "B";
                }
                cout << '\n';
            }
            for (int j = 0; j < y; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << "C";
                }
                cout << '\n';
            }
            break;
        case 1:
            for (int j = 0; j < b; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << "A";
                }
                cout << '\n';
            }
            for (int j = 0; j < c; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    if (i < d) {
                        cout << "B";
                    } else {
                        cout << "C";
                    }
                }
                cout << '\n';
            }
            break;
        case 2:
            for (int j = 0; j < b; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << "B";
                }
                cout << '\n';
            }
            for (int j = 0; j < c; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    if (i < d) {
                        cout << "A";
                    } else {
                        cout << "C";
                    }
                }
                cout << '\n';
            }
            break;
        default:
            for (int j = 0; j < b; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << "C";
                }
                cout << '\n';
            }
            for (int j = 0; j < c; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    if (i < d) {
                        cout << "A";
                    } else {
                        cout << "B";
                    }
                }
                cout << '\n';
            }
            break;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("logos.in", "r", stdin);
    int a1, b1, a2, b2, a3, b3, a, b, m, n, x, y;
    cin >> a >> b >> m >> n >> x >> y;
    a1 = max(a, b);
    b1 = min(a, b);
    a2 = max(m, n);
    b2 = min(m, n);
    a3 = max(x, y);
    b3 = min(x, y);
    int area = a1 * b1 + a2 * b2 + a3 * b3;
    if ((sqrt(area)) * (sqrt(area)) != area) {
        cout << -1;
        return 0;
    }
    sideL = sqrt(area);
    
}