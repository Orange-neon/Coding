#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
set<int> fields;
/*
void travelpath(int currfield, int n, int time, vector<vector<int>> paths, int b_or_e, vector<pair<int, int>> cowspeeds, vector<int>& times) {
    if (!paths[currfield].empty()) {
        fields.insert(currfield);
        for (int field : paths[currfield]) {
            if (field > currfield) {
                int ttime=time;
                cout<<field<<" field num"<<'\n';
                fields.insert(field);
                if (b_or_e == 0) {
                    ttime+= cowspeeds[currfield].first;
                }
                else {
                    ttime+= cowspeeds[currfield].second;
                }
                if (field == n) {
                    times.push_back(ttime);
                    cout<<"time pushed back: "<<ttime<<'\n';
                }
                else {
                    travelpath(field, n, ttime, paths, b_or_e, cowspeeds, times);
                }
            }
        }
    }
}
*/
bool compare_pairs(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
    return a.first < b.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("6.in", "r", stdin);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> paths(m, vector<int>(0));
    vector<pair<int, int>> cowspeeds(m);
    vector<vector<pair<int, vector<int>>>> b_temp_times(n, vector<pair<int,vector<int>>>(0));
    vector<vector<pair<int, vector<int>>>> e_temp_times(n, vector<pair<int,vector<int>>>(0));
    vector<pair<int, vector<int>>> sametimes;
    vector<int> valid_fields (n, 0);
    for (int q=0; q<m; ++q) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        paths[a-1].push_back(b-1);
        cowspeeds[a-1]={c,d};
    }
    for (int field = n-2; field >= 0; --field) {
        for (int nextfield : paths[field]) {
            vector<int> ppathvector;
            if (field == n-2) {
                ppathvector.push_back(field);
            }
            ppathvector.push_back(nextfield);
            if (nextfield==n-1) {
                valid_fields[field] = 1; // Mark this field as valid
                b_temp_times[field].push_back({cowspeeds[field].first, ppathvector});
                e_temp_times[field].push_back({cowspeeds[field].second, ppathvector});
            }
            if (valid_fields[nextfield] == 1) {
                valid_fields[field] = 1; // If next field is valid, current field is also valid
                for (pair<int, vector<int>> btime : b_temp_times[nextfield]) {
                    vector<int> pathvector=ppathvector;
                    for (int i : btime.second) {
                        pathvector.push_back(i);
                    }
                    vector<int> uppathvector(pathvector.size()+  btime.second.size());
                    merge(pathvector.begin(), pathvector.end(), btime.second.begin(), btime.second.end(), uppathvector.begin());
                    b_temp_times[field].push_back({btime.first + cowspeeds[field].first, uppathvector});
                }
                for (pair<int, vector<int>> etime : e_temp_times[nextfield]) {
                    vector<int> pathvector=ppathvector;
                    for (int i : etime.second) {
                        pathvector.push_back(i);
                    }
                    vector<int> uppathvector(pathvector.size() + etime.second.size());
                    merge(pathvector.begin(), pathvector.end(), etime.second.begin(), etime.second.end(), uppathvector.begin());
                    e_temp_times[field].push_back({etime.first + cowspeeds[field].second, uppathvector});
                }
            }
        }
    }
    /*
    for (int t : btimes) {
        cout << t << " ";
    }
    cout<< "Btime values"<<'\n';
    for (int t : etimes) {
        cout << t << " ";
    }
    cout<< "Etime values"<<'\n';
    */
    if (b_temp_times[0].empty() || e_temp_times[0].empty()) {
        cout << "IMPOSSIBLE, EMPTY";
        return 0;
    }
    else {
        for (pair<int, vector<int>> btime : b_temp_times[0]) {
            for (pair<int, vector<int>> etime : e_temp_times[0]) {
                if (btime.first == etime.first) {
                   sametimes.push_back(etime);
                   break;
                }
            }
        }
        if (sametimes.empty()) {
            cout << "IMPOSSIBLE, no sametimes";
        }
        else {
            cout << (*min_element(sametimes.begin(), sametimes.end(), compare_pairs)).first<<'\n';
            vector<int> pathtaken= (*min_element(sametimes.begin(), sametimes.end(), compare_pairs)).second;
            for (int i : pathtaken) {
                cout<<i<<' ';
            }
        }
    }

}