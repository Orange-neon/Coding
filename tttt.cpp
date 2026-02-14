#include <bits/stdc++.h>
using namespace std;
// need to use winners to store the sets of winners otherwise repeats like in case 10;
// so i need to redo the onet and twot
set<vector<char>> winners;
void addToWinners(set<char> shortTeam) {
    vector<char> toin;
    for (char c : shortTeam) {
        toin.push_back(c);
    }
    winners.insert(toin);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("10.in", "r", stdin);
    int onet = 0, twot = 0;
    vector<vector<char>> game(3, vector<char>(3, ' '));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> game[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        int ox = i, oy = 0;
        set<char> teams;
        teams.insert(game[oy][ox]);
        for (int j = 0; j < 2; ++j) {
            ++oy;
            teams.insert(game[oy][ox]);
        }
        if (teams.size() == 1 || teams.size() == 2) {
            addToWinners(teams);
        };
    }
    for (int i = 0; i < 3; ++i) {
        int ox = 0, oy = i;
        set<char> teams;
        teams.insert(game[oy][ox]);
        for (int j = 0; j < 2; ++j) {
            ++ox;
            teams.insert(game[oy][ox]);
        }
        if (teams.size() == 1 || teams.size() == 2) {
            addToWinners(teams);
        };
    }
    int ox = 0, oy = 0;
    set<char> teams;
    teams.insert(game[oy][ox]);
    for (int j = 0; j < 2; ++j) {
        ++oy;
        ++ox;
        teams.insert(game[oy][ox]);
    }
    if (teams.size() == 1 || teams.size() == 2) {
        addToWinners(teams);
    };
    ox = 2;
    oy = 0;
    teams.clear();
    teams.insert(game[oy][ox]);
    for (int j = 0; j < 2; ++j) {
        ++oy;
        --ox;
        teams.insert(game[oy][ox]);
    }
    if (teams.size() == 1 || teams.size() == 2) {
        addToWinners(teams);
    };
    for (auto vec : winners) {
        if (vec.size() == 2) {
            ++twot;
        } else if (vec.size() == 1) {
            ++onet;
        }
    }
    cout << onet << '\n' << twot;
}