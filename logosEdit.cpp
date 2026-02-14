#include<bits/stdc++.h>
using namespace std;
int sideL;
struct Logo {
    int x;
    int y;
    char Company;
};

void printBoard(Logo a, Logo b, Logo c, int type) {
    cout << sideL << '\n';
    switch (type) {
        case 0:
            for (int j = 0; j < a.y; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << a.Company;
                }
                cout << '\n';
            }
            for (int j = 0; j < b.y; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << b.Company;
                }
                cout << '\n';
            }
            for (int j = 0; j < c.y; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << c.Company;
                }
                cout << '\n';
            }
            break;
        default:
            for (int j = 0; j < a.y; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    cout << a.Company;
                }
                cout << '\n';
            }
            for (int j = 0; j < b.x; ++j) {
                for (int i = 0; i < sideL; ++i) {
                    if (i < b.y) {
                        cout << b.Company;
                    } else {
                        cout << c.Company;
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
    //freopen("logos.in", "r", stdin);
    int area;
    Logo a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    a.Company = 'A';
    b.Company = 'B';
    c.Company = 'C';
    if (a.x < a.y) {
        swap(a.x, a.y);
    }
    if (b.x < b.y) {
        swap(b.x, b.y);
    }
    if (c.x < c.y) {
        swap(c.x, c.y);
    }
    if (a.x < b.x) {
        swap(a, b);
    }
    if (a.x < c.x) {
        swap (a, c);
    }
    area = a.x * a.y + b.x * b.y + c.x * c.y;
    if ((sqrt(area)) * (sqrt(area)) != area) {
        cout << -1;
        return 0;
    }
    sideL = sqrt(area);
    if (a.x != sideL) {
        cout << -1;
        return 0;
    }
    if (a.x == b.x && b.x == c.x  && c.x == sideL) {
        if (a.y + b.y + c.y == sideL) {
            printBoard(a, b, c, 0);
        } else {
            cout << -1;
        }
        return 0;
    }
    int yRem = sideL - a.y;
    if (b.y == yRem) {
        swap(b.x, b.y);
    }
    if (c.y == yRem) {
        swap(c.x, c.y);
    }
    if (a.x = b.y + c.y && b.x == c.x && b.x + a.y == sideL) {
        printBoard(a, b, c, 1);
        return 0;
    }
    cout << -1;
}