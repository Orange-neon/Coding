#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("10.in", "r", stdin);
    int x,y;
    cin>>x>>y;
    int walk=1, dist=1;
    y-=x;
    x=0;
    if (x<y) {
        while(x<y) {
            x=walk;
            if (walk!=1) {
                dist+=abs(walk)+abs(walk/-2);
            }
            walk*=-2;
        }
        dist-=x-y;
        cout<<dist;
    }
    else if (x>y) {
        while(x>y) {
            x=walk;
            if (walk!=1) {
                dist+=abs(walk)+abs(walk/-2);
            }
            walk*=-2;
        }
        dist-=y-x;
        cout<<dist;
    }
    else {
        cout<<0;
        return 0;
    }
}