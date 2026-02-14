#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    array<int, 100> slimit;
    array<int, 100> bessie;
    int st=0,end=0;
    for (int q=0; q<n; ++q) {
        int len, limit;
        cin>>len>>limit;
        st=end;
        end+=len;
        for (int w=st; w<end; ++w) {
            slimit[w]=limit;
        }
    }
    int bst=0,bend=0;
    for (int q=0; q<m; ++q) {
        int len, limit;
        cin>>len>>limit;
        bst=bend;
        bend+=len;
        for (int w=bst; w<bend; ++w) {
            bessie[w]=limit;
        }
    }
    int largest=0;
    bool f=0;
    for (int i=0; i<100; ++i) {
        if (bessie[i]-slimit[i]==50 && !f) {
            cout<<'\n'<<"HEREERERERR  "<<i<<'\n';
            f=1;
        }
        if (bessie[i]-slimit[i]>largest) {
            largest=bessie[i]-slimit[i];
        }
    }
    cout<<"ans: "<<largest<<'\n'<<"SLIMITS: "<<'\n';
    for (int x:slimit) {
        cout<<x<<' ';
    }
    cout<<'\n'<<"Bessie times: "<<'\n';
    for (int y : bessie) {
        cout<<y<<' ';
    }
}