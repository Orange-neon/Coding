#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> buckets_for_cow;
    map<int, int> ending_times;
    int n;
    cin >> n;
    int last_time = 0;
    for (int i = 0; i < n; ++i) {
        int s, t, b;
        cin >> s >> t >> b;
        buckets_for_cow[s] = b;
        ending_times[t] = b;
        if (t > last_time) {
            last_time = t;
        }
    }
    int total_buckets_needed = 0, avaliableBuckets = 0;
    for (int time = 1; time <= last_time; ++time) {
        if (buckets_for_cow.count(time)==1) {
            avaliableBuckets-=buckets_for_cow[time];
            if (avaliableBuckets<0) {
                total_buckets_needed+=abs(avaliableBuckets);
                avaliableBuckets=0;
            }
            //cout << avaliableBuckets << "alr i started and i have this many buckets left\n";
        } else if (ending_times.count(time) == 1) {
            avaliableBuckets+=ending_times[time];
            //cout << avaliableBuckets << "alr i ended and i have this many buckets left\n";
        }
    }
    cout << total_buckets_needed;
}