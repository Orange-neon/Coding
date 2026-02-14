#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,n;
    freopen("6.in", "r", stdin);
    vector<pair<int, int>> transfer_routes_end; // {cost, route_index}
    vector<int> bdex;
    vector<pair<int, int>> transfer_routes_start; // {cost, route_index}
    vector<int> adex;
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
            int a;
            cin>>a;
            route[j]=a;
        }
        planeroutes.push_back(route);
    }
    bool afounds = false;
    bool afound = false;
    bool bfound = false;
    for (int q=0; q<n; ++q) {
        afound = false;
        bfound = false;
        afounds = false;
        bool flag = false;
        int aindex;
        for (int i=0; i<planeroutes[q].size(); ++i) {
            if (planeroutes[q][i] == a) {
                afound = true;
                if (i!= planeroutes[q].size() - 1) {
                    afounds = true;
                    aindex = i;
                }
            }
            else if (planeroutes[q][i] == b) {
                if (!flag) {
                    if (!afound) {
                        if (i!=0) {
                            transfer_routes_end.push_back({costs[q], q});
                            bdex.push_back(i);
                        }
                        bfound = false;
                        flag = true;
                    }
                    if (!flag) {
                        bfound = true;
                        break;
                    }
                }
            }
        }
        if (bfound && afound) {
            //validroutes.push_back(planeroutes[q]);
            validcosts.push_back(costs[q]);
        }
        if (afounds && !bfound) {
            transfer_routes_start.push_back({costs[q], q});
            adex.push_back(aindex);
        }
    }
    int mincost = -1;
    if (validcosts.empty()) {
        mincost = -1;
    }
    else {
        mincost = *min_element(validcosts.begin(), validcosts.end());
    }
    for (int route=0; route<transfer_routes_start.size(); ++route) {
        int aindx=adex[route];
        for (int end_route=0; end_route<transfer_routes_end.size(); ++end_route) {
            int bindx=bdex[end_route];
            if (transfer_routes_start[route].second == transfer_routes_end[end_route].second) {
                continue; // skip if the same route
            }
            for (int start_city = aindx; start_city < planeroutes[transfer_routes_start[route].second].size(); ++start_city) {
                if (planeroutes[transfer_routes_start[route].second][start_city] == b) {
                    continue; // skip if the same route
                }
                for (int end_city = 0; end_city < bindx; ++end_city) {
                    if (planeroutes[transfer_routes_end[end_route].second][end_city] == a) {
                        continue; // skip if the same route
                    }
                    int cost = transfer_routes_start[route].first + transfer_routes_end[end_route].first;
                    if (mincost == -1 || cost < mincost) {
                        mincost = cost;
                    }
                }
            }
        }
    }
    cout << mincost;
}