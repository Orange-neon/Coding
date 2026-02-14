#include <bits/stdc++.h>
using namespace std;
/*
6
2
3
4
5
3
8
*/
vector<int> roomInfo;
int dist = INT_MAX;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int maxCows;
        cin >> maxCows;
        roomInfo.push_back(maxCows);
    }
    for (int strt = 0; strt < n; ++strt) {
        int d = 0;
        /*
        if (strt == 5) {
            cout <<"holy moly guacamoly thuwghuiwwuiwe\n";
        }
        */
        for (int roomId = strt; roomId < strt + n; ++roomId) {
            int roomIdd = roomId % n;
            d += roomInfo[roomIdd] * (roomId - strt);
            /*
            if (strt == 5) {
                cout << "\n look i added " << roomInfo[roomIdd] * (roomId - strt);
                cout <<"\n roomIdd is: " << roomIdd <<" and the value of roomInfo[roomIdd] is " << roomInfo[roomIdd] << "\n Also the value of roomId - strt = " << roomId - strt << "\n\n\n";
            }
            */
        }
        if (dist > d) {
            dist = d;
        }
    }
    cout << dist;
}