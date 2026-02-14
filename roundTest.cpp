#include<bits/stdc++.h>
using namespace std;
struct treePoint {
    long long start;
    long long end;
    long long amt;
};
vector<treePoint> bank = {
    {45, 49, 5},
    {445, 499, 55},
    {4445, 4999, 555},
    {44445, 49999, 5555},
    {444445, 499999, 55555},
    {4444445, 4999999, 555555},
    {44444445, 49999999, 5555555},
    {444444445, 499999999, 55555555},
    {4444444445, 4999999999, 555555555}
};

int numsLessthan(long long x) {
    long long rtn = 0;
    for (int i = 0; i < bank.size(); ++i) {
        if (x >= bank[i].end) {
            rtn += bank[i].amt;
        } else if (x >= bank[i].start) {
            rtn += x - bank[i].start + 1;
            break;
        }
    }
    return rtn;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMMENT OUT AFTER TESTING
    //freopen("rounding.in", "r", stdin);
    long long t;
    vector<int> ns;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << numsLessthan(n) << '\n';
    }
    //cout << roud(4400);
}