#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
int n;
pair<int, int> forwardRange = {-1, -1};
pair<int, int> reverseRange = {-1, -1};
struct SegId {
    string type;
    int lowBound;
    int upBound;
};
vector<SegId> highway;

pair<int, int> narrow_operation(pair<int, int> previous, pair<int, int> now) {
    pair<int, int> rtn;
    rtn.first=max({previous.first, now.first});
    if (previous.second == -1) {
        rtn.second = now.second;
        return rtn;
    }
    rtn.second = min({previous.second, now.second});
    return rtn;
}

pair<int, int> oning_operation(pair<int, int> onVal, pair<int, int> curr) {
    pair<int, int> rtn;
    if (curr.first == -1 || curr.second == -1) {
        return curr;
    }
    rtn.first = onVal.first + curr.first;
    rtn.second = onVal.second + curr.second;
    return rtn;
}

pair<int, int> offing_operation(pair<int, int> offVal, pair<int, int> curr) {
    pair<int,int> rtn;
    if (curr.first == -1 || curr.second == -1) {
        return curr;
    }
    rtn.first = max({0, curr.first - offVal.second});
    rtn.second = max({0, curr.second - offVal.first});
    return rtn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string id;
        int lo,hi;
        cin >> id >> lo >> hi;
        highway.push_back({id,lo,hi});
        if (id == "none") {
            forwardRange = narrow_operation(forwardRange, {lo, hi});
        } else if (id == "on") {
            forwardRange = oning_operation({lo, hi}, forwardRange);
        } else {
            forwardRange = offing_operation({lo, hi}, forwardRange);
        }
    }
    for (int i = n-1; i >=0; --i) {
        auto segM = highway[i];
        auto lo = segM.lowBound;
        auto hi = segM.upBound;
        auto id = segM.type;
        if (id == "none") {
            reverseRange = narrow_operation(reverseRange, {lo, hi});
        } else if (id == "off") {
            reverseRange = oning_operation({lo, hi}, reverseRange);
        } else {
            reverseRange = offing_operation({lo, hi}, reverseRange);
        }
    }
    cout << reverseRange.first <<" " << reverseRange.second << '\n' << forwardRange.first <<" "<<forwardRange.second;
}