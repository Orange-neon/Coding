#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("10.in", "r", stdin);
    int n;
    cin>>n;
    vector<pair<int, int>> cows;
    int groups=1;
    for (int q=0; q<n; q++) {
        int x,v;
        cin>>x>>v;
        cows.push_back({x,v});
    }
    for (int w=n-1; w>=0; w--) {
        if (w!=0) {
            if (cows[w].second>cows[w-1].second) {
                groups+=1;
            }
            else if (cows[w].second==cows[w-1].second && cows[w].first>cows[w-1].first+1) {
                groups+=1;
            }
            else {
                cows[w-1].second=cows[w].second;
                cows[w-1].first=cows[w].first-1;
            }
        }
    }
    cout<<groups;
    return 0;
}