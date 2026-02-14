#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //commetn ou tafetetetsting
    //freopen("cowyear.in", "r", stdin);
    int n;
    cin >> n;
    map<string, int> ZodiactoYear = {
        {"Ox", 0},
        {"Tiger", 1},
        {"Rabbit", 2},
        {"Dragon", 3},
        {"Snake", 4},
        {"Horse", 5},
        {"Goat", 6},
        {"Monkey", 7},
        {"Rooster", 8},
        {"Dog", 9},
        {"Pig", 10},
        {"Rat", 11}
    };
    map<int, string> YearToZodiac = {
        {0, "Ox"},
        {1, "Tiger"},
        {2, "Rabbit"},
        {3, "Dragon"},
        {4, "Snake"},
        {5, "Horse"},
        {6, "Goat"},
        {7, "Monkey"},
        {8, "Rooster"},
        {9, "Dog"},
        {10, "Pig"},
        {11, "Rat"}
    };
    map<string, string> CowtoZodiac = {{"Bessie", "Ox"}};
    map<string, int> CowtoBessieAge = {{"Bessie", 0}};
    for (int i = 0; i < n; ++i) {
        vector<string> statment;
        int age = 0, doceAdjust = 0;
        for (int j = 0; j < 8; ++j) {
            string word;
            cin >> word;
            statment.push_back(word);
        }
        CowtoZodiac[statment[0]] = statment[4];
        if (statment[3] == "previous") {
            while (true) {
                if (ZodiactoYear[CowtoZodiac[statment[7]]] - age + 12 * doceAdjust < 0) {
                    ++doceAdjust;
                }
                if (YearToZodiac[ZodiactoYear[CowtoZodiac[statment[7]]] - age + 12 * doceAdjust] != statment[4] || age == 0) {
                    ++age;
                } else {
                    break;
                }
            }
            CowtoBessieAge[statment[0]] = CowtoBessieAge[statment[7]]- age;
        } else {
            doceAdjust = 0;
            while (true) {
                if (ZodiactoYear[CowtoZodiac[statment[7]]] + age - 12 * doceAdjust >= 12) {
                    ++doceAdjust;
                }
                if (YearToZodiac[ZodiactoYear[CowtoZodiac[statment[7]]] + age - 12 * doceAdjust] != statment[4] || age == 0) {
                    ++age;
                } else {
                    break;
                }
            }
            CowtoBessieAge[statment[0]] = CowtoBessieAge[statment[7]] + age;
        }
        if (CowtoBessieAge.count("Elsie")) {
            cout << abs(CowtoBessieAge["Elsie"]);
            return 0;
        }
    }
}