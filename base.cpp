#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    freopen("10.in", "r", stdin);
    int q;
    cin>>q;
    for (int w=0; w<q; ++w) {
        int a,b;
        cin>>a>>b;
        for (int x=11; x<15000; ++x) {
            long long btena;
            int ahundreds = a/100;
            int atens = (a/10) % 10;
            int aones = a % 10;
            btena= ahundreds*(x*x) + atens*(x) + aones;
            double bsolsqrt;   
            double bsol;
            int bhundreds = b/100;
            int btens = (b/10) % 10;
            int bones = b % 10;
            bsolsqrt = sqrt(btens*btens-4*(bhundreds)*(bones-btena));
            if (bsolsqrt == floor(bsolsqrt)) {
                bsol= (-1*(btens) + bsolsqrt)/(2*bhundreds);
                if (bsol == floor(bsol)) {
                    cout<<x<<','<<bsol<<"___";
                    break;
                }
            }
        }
    }
}