#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("10.in", "r", stdin);
    int n;
    cin>>n;
    vector<int> scores(3, 0);
    vector<int> shells={1,2,3};
    for (int q=0; q<n; ++q) {
        int swap1, swap2, guess;
        cin>>swap1>>swap2>>guess;
        swap(shells[swap1-1], shells[swap2-1]);
        /*
        if (guess == shells[0]) {
            scores[0]++;
        } else if (guess == shells[1]) {
            scores[1]++;
        } else if (guess == shells[2]) {
            scores[2]++;
        }
            */
        scores[shells[guess-1]-1]++;
    }
    cout<<*max_element(scores.begin(), scores.end())<<endl;
}