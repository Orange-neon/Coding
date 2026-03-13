#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#include <cctype>
using namespace std;
set<string> names;
/**
 * Reads in the list of volunteers from volunteers.in and checks for duplicates.
 * It only prints out a message if there are no duplicates.
 */
int main() {
    freopen("volunteers.in", "r", stdin);
    string line = "";
    bool allClear = 1;
    while(getline(cin, line)) {
        string letterOnlyLine;
        for (char i : line) {
            if (isalpha(i)) {
                letterOnlyLine+= i;
            }
        }
        if (names.count(letterOnlyLine) == 0) {
            names.insert(letterOnlyLine);
        } else {
            cout << "Duplicate detected, " << letterOnlyLine << " ,has conflict.\n";
            allClear = 0;
        }
    }
    if (allClear) {
        cout << "No duplicates detected.";
    }
}
