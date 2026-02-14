#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("2.in", "r", stdin);
    long long n, a, b;
    cin >> n >> a >> b;
    cout<<a<<' '<<b<<'\n';
    long long cownum = b-a+1;
    vector<pair<int, string>> cows(n); //{{1, S}, {4, NS}, {10, S}}
    vector<int> cow_weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].second >> cows[i].first;
        cow_weights[i]=cows[i].first;
    }
    sort(cows.begin(), cows.end());
    sort(cow_weights.begin(), cow_weights.end());
    int aindex = 0, bindex = 0;
    if (a!=cows[n-1].first && b!=cows[n-1].first) {
        auto ait = upper_bound(cow_weights.begin(), cow_weights.end(), a);
        auto bit = lower_bound(cow_weights.begin(), cow_weights.end(), b);
        aindex = ait - cow_weights.begin()-1;
        bindex = bit - cow_weights.begin();
    }
    else if (a == cows[n-1].first) {
        aindex = n - 1;
        bindex = lower_bound(cow_weights.begin(), cow_weights.end(), b) - cow_weights.begin();

    } 
    else {
        bindex = n - 1;
        aindex = upper_bound(cow_weights.begin(), cow_weights.end(), a) - cow_weights.begin()-1;
    }
    if (aindex == -1) aindex = 0;
    if (bindex == -1) bindex = 0;
    if (bindex == n) bindex = n - 1;
    cout<<aindex << " " << bindex << '\n';
    for (int cow=aindex+1; cow<bindex; ++cow) {
        if (cow != aindex+1 && cow != bindex-1) {
            if (cows[cow].second == "NS" && cows[cow-1].second == "S" && cows[cow+1].second == "S") {
                cownum-=cows[cow].first-(cows[cow-1].first+cows[cow].first)/2 + (cows[cow].first+cows[cow+1].first)/2-cows[cow].first;
            }
            else if (cows[cow].second == "NS" && cows[cow-1].second == "S") {
                cownum-=cows[cow].first-(cows[cow-1].first+cows[cow].first)/2;
            }
            else if (cows[cow].second == "NS" && cows[cow-1].second == "NS") {
                cownum-=cows[cow].first-cows[cow-1].first;
            }
        }
        else if (cow == aindex+1) {
            if (cows[cow].second == "NS" && cows[cow-1].second == "S") {
                if (a>= (cows[cow-1].first+cows[cow].first)/2+1) {
                    cownum-=cows[cow].first-a+1;
                }
                else {
                    cownum-=cows[cow].first-(cows[cow-1].first+cows[cow].first)/2;
                }
            }
            else if (cows[cow].second == "NS" && cows[cow-1].second == "NS") {
                if (a<=cows[cow-1].first) {
                    cownum-=cows[cow].first-a+1 + cows[cow].first-cows[cow-1].first;
                }
                else {
                    cownum-=cows[cow].first-a;
                }
            }
            else if (cows[cow].second == "S" && cows[cow-1].second == "NS") {
                if (a<=cows[cow-1].first) {
                    cownum-=cows[cow].first-a+1 + cows[cow].first-cows[cow-1].first;
                }
                else if (a<(cows[cow].first+cows[cow-1].first)/2) {
                    cownum-= (cows[cow].first+cows[cow-1].first)/2-a;
                }
            }
        }
        else if (cow == bindex-1) {
            if (cows[cow].second == "NS" && cows[cow-1].second=="S") {
                cownum-=cows[cow].first-(cows[cow-1].first+cows[cow].first)/2;
            }
            if (cows[cow].second == "NS" && cows[cow+1].second == "S") {
                if (b<= (cows[cow+1].first+cows[cow].first)/2) {
                    cownum-=b-cows[cow].first;
                }
                else {
                    cownum-=(cows[cow+1].first+cows[cow].first)/2-cows[cow].first;
                }
            }
            else if (cows[cow].second == "NS" && cows[cow+1].second == "NS") {
                cownum-=b-cows[cow].first+1;
            }
            else if (cows[cow].second == "S" && cows[cow+1].second == "NS") {
                if (b>=cows[cow+1].first) {
                    cownum-=b-cows[cow+1].first+1+cows[cow+1].first-(cows[cow].first+cows[cow+1].first)/2-1;
                }
                else if (b>(cows[cow].first+cows[cow+1].first)/2) {
                    cownum-= b-(cows[cow+1].first+cows[cow].first)/2;
                }
            }
        }
        if (cow==bindex-1 && cow==aindex+1) {
            if (cows[cow].second == "NS" && cows[cow+1].second == "S") {
                if (b<= (cows[cow+1].first+cows[cow].first)/2) {
                    cownum-=b-cows[cow].first-1;
                }
                else {
                    cownum-=(cows[cow+1].first+cows[cow].first)/2-cows[cow].first-1;
                }
            }
            if (cows[cow].second == "NS" && cows[cow+1].second == "NS") {
                cownum-=b-cows[cow].first+1;
            }
            if (cows[cow].second == "S" && cows[cow+1].second == "NS") {
                if (b>=cows[cow+1].first) {
                    cownum-=b-cows[cow+1].first+1+cows[cow+1].first-(cows[cow].first+cows[cow+1].first)/2-1;
                }
                else if (b>(cows[cow].first+cows[cow+1].first)/2) {
                    cownum-= b-(cows[cow+1].first+cows[cow].first)/2-1;
                }
            }
        }
    }
    cout << '\n'<<cownum;
}
