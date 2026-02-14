#include <bits/stdc++.h>
using namespace std;
struct CowInfo {
    char direction;
    int ID;
    pair<int, int> coord;
    bool stopped;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //COMENT OAT AFET ERISNDOEIBGT
    freopen("3.in", "r", stdin);
    vector<CowInfo> ncows;
    vector<CowInfo> ecows;
    vector<pair<char, pair<int, int>>> initialPos;
    map<pair<int, int>, vector<pair<int, int>>> collisions;
    map<int, int> trueTimes;
    int cown;
    cin >> cown;
    for (int i = 0; i < cown; ++i) {
        CowInfo animal;
        cin >> animal.direction >> animal.coord.first >> animal.coord.second;
        animal.stopped = 0;
        initialPos.push_back({animal.direction, animal.coord});
        if (animal.direction == 'N') {
            animal.ID = ncows.size();
            ncows.push_back(animal);
        } else {
            animal.ID = ecows.size();
            ecows.push_back(animal);
        }
    }
    for (CowInfo cow: ncows) {
        for (CowInfo cow2 : ecows) {
            if (cow.coord.first >= cow2.coord.first) {
                if (cow.coord.second <= cow2.coord.second) {
                    pair<int, int> hitPt = {cow.coord.first, cow2.coord.second};
                    collisions[{max(abs(hitPt.first - cow2.coord.first), abs(hitPt.second - cow.coord.second)), 1}].push_back({cow.ID, cow2.ID});
                    trueTimes[max(abs(hitPt.first - cow2.coord.first), abs(hitPt.second - cow.coord.second))] = max(abs(hitPt.first - cow2.coord.first), abs(hitPt.second - cow.coord.second));
                }
            }
        }
    }
    for (auto ncow : ncows) {
        for (auto ncow2 : ncows) {
            if (ncow.ID != ncow2.ID) {
                if (ncow.coord.first == ncow2.coord.first) {
                    collisions[{abs(ncow.coord.second - ncow2.coord.second), 0}].push_back({ncow.ID, ncow2.ID});
                    trueTimes[abs(ncow.coord.second - ncow2.coord.second)] = abs(ncow.coord.second - ncow2.coord.second);
                }
            }
        }
    }
    for (auto ecow : ecows) {
        for (auto ecow2 : ecows) {
            if (ecow.ID != ecow2.ID) {
                if (ecow.coord.second == ecow2.coord.second) {
                    collisions[{abs(ecow.coord.first - ecow2.coord.first), 2}].push_back({ecow.ID, ecow2.ID});
                    trueTimes[abs(ecow.coord.second - ecow2.coord.second)] = abs(ecow.coord.second - ecow2.coord.second);
                }
            }
        }
    }
    for (const auto& pair : collisions) {
        for (auto& ncow : ncows) {
            if (!ncow.stopped) {
                ncow.coord.second += trueTimes[pair.first.first];
            }
        }
        for (auto& ecow : ecows) {
            if (!ecow.stopped) {
                ecow.coord.first += trueTimes[pair.first.first];
            }
        }
        for (auto crashPoint : pair.second) {
            if (pair.first.second == 1) {
                if (ncows[crashPoint.first].stopped == 0 && ecows[crashPoint.second].stopped == 0) {
                    if (ncows[crashPoint.first].coord == ecows[crashPoint.second].coord) {
                        continue;
                    } else if (ncows[crashPoint.first].coord.second == ecows[crashPoint.second].coord.second && ncows[crashPoint.first].coord.first < ecows[crashPoint.second].coord.first) {
                        ncows[crashPoint.first].stopped = 1;
                    } else if (ncows[crashPoint.first].coord.first == ecows[crashPoint.second].coord.first && ncows[crashPoint.first].coord.second > ecows[crashPoint.second].coord.second) {
                        ecows[crashPoint.second].stopped = 1;
                    }
                }
            } else if (pair.first.second == 0) {
                if (ncows[crashPoint.first].coord < ncows[crashPoint.second].coord) {
                    ncows[crashPoint.first].stopped = 1;
                } else if (ncows[crashPoint.first].coord > ncows[crashPoint.second].coord) {
                    ncows[crashPoint.second].stopped = 1;
                }
            } else {
                if (ecows[crashPoint.first].coord < ecows[crashPoint.second].coord) {
                    ecows[crashPoint.first].stopped = 1;
                } else if (ecows[crashPoint.first].coord > ecows[crashPoint.second].coord) {
                    ecows[crashPoint.second].stopped = 1;
                }
            }
        }
        auto trueTime = trueTimes;
        for (auto& time : trueTime) {
            time.second -= trueTimes[pair.first.first];
        }
        trueTimes = trueTime;
    }
    int nIdx = 0, eIdx = 0;
    for (auto startingCow : initialPos) {
        if (startingCow.first == 'N') {
            if (!ncows[nIdx].stopped) {
                cout << "Infinity\n";
                ++nIdx;
            } else {
                cout << ncows[nIdx].coord.second - startingCow.second.second << '\n';
                ++nIdx;
            }
        } else {
            if (!ecows[eIdx].stopped) {
                cout << "Infinity\n";
                ++eIdx;
            } else {
                cout << ecows[eIdx].coord.first - startingCow.second.first << '\n';
                ++eIdx;
            }
        }
    }
}