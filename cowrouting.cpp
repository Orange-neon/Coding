#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,n;
    freopen("12.in", "r", stdin);
    vector<vector<int>> planeroutes;
    vector<int> costs;
    //vector<vector<int>> validroutes;
    vector<int> validcosts;
    cin >> a >> b >> n;
    for (int i=0; i<n; ++i) {
        int cost, cities;
        cin >> cost >> cities;
        costs.push_back(cost);
        vector<int> route(cities);
        for (int j=0; j<cities; ++j) {
            cin >> route[j];
        }
        planeroutes.push_back(route);
    }
    for (int q=0; q<n; ++q) {
        bool afound = false;
        bool bfound = false;
        for (int i=0; i<planeroutes[q].size(); ++i) {
            if (planeroutes[q][i] == a) {
                afound = true;
            }
            else if (planeroutes[q][i] == b) {
                if (!afound) {
                    bfound = false;
                    break;
                }
                bfound = true;
                break;
            }
        }
        if (bfound && afound) {
            //validroutes.push_back(planeroutes[q]);
            validcosts.push_back(costs[q]);
        }
    }
    if (validcosts.empty()) {
        cout << -1;
    }
    else {
        int mincost = *min_element(validcosts.begin(), validcosts.end());
        cout << mincost;
    }
}