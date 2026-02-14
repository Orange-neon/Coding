#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("1.in", "r", stdin);
    int n;
    cin>>n;
    vector<int> shuff(n);
    vector<int> cowids(n);
    for (int i=0; i<n; ++i) {
        cin>>shuff[i];
    }
    for (int j=0; j<n; ++j) {
        cin>>cowids[j];
    }
    for (int k=0; k<3; ++k) {
        vector<int> temp(n);
        for (int q=0; q<n; ++q) {
            temp[q]=cowids[shuff[q]-1];
        }
        cowids=temp;
    }
    for (int q : cowids) {
        cout<<q<<'\n';
    }
}