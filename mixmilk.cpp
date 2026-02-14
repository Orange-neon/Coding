#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("2.in", "r", stdin);
    int bucket=0;
    vector<int> milk(3);
    vector<int> capacity(3);
    for (int q=0; q < 3; q++) {
        cin >> capacity[q] >> milk[q];
    }
    for (int w=0; w<100; w++) {
        if (bucket==3) {
            bucket=0;
        }
        if (bucket==2) {
            if (milk[2]+milk[0] <= capacity[0]) {
                milk[0] += milk[2];
                milk[2] = 0;
            }
            else {
                milk[2]-= capacity[0] - milk[0];
                milk[0] = capacity[0];
            }
        }
        else {
            if (milk[bucket]+milk[bucket+1] <= capacity[bucket+1]) {
                milk[bucket+1] += milk[bucket];
                milk[bucket] = 0;
            }
            else {
                milk[bucket] -= capacity[bucket+1] - milk[bucket+1];
                milk[bucket+1] = capacity[bucket+1];
            }
        }
        bucket++;
    }
    for (int q=0; q < 3; q++) {
        cout << milk[q] << '\n';
    }
}