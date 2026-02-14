#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int lower = 0, higher = 1000001;
    while (lower + 1 < higher) {
        cout << (lower + higher) / 2 << endl;
        string response;
        cin >> response;
        if (response == ">=") {
            lower = (lower + higher) / 2;
        } else {
            higher = (lower + higher) / 2;
        }
    }
    cout << "! " << (lower + higher) / 2;
}