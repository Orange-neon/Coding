#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMEMT AUE TATEFST
    //freopen("oddPhotos.in", "r", stdin);
    int n, odds = 0, evens = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp % 2 == 0) {
            ++evens;
        } else {
            ++odds;
        }
    }
    while (evens != odds + 1 && evens != odds) {
        if (odds > evens) {
            odds -= 2;
            evens += 1;
        } else {
            --evens;
        }
    }
    cout << odds + evens;
}
