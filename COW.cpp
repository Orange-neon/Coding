#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("5.in", "r", stdin);
    int length_of_string;
    cin>>length_of_string;
    cin.ignore();
    string ancient_string;
    getline(cin, ancient_string);
    vector<int> C_occurs;
    vector<int> O_occurs(length_of_string, 0);
    vector<int> O_occurs_indexes;
    vector<int> W_occurs(length_of_string, 0);
    long long num_COW_words=0;
    bool C_found=false;
    bool O_found=false;
    for (int q=0; q<length_of_string; ++q) {
        if (ancient_string[q]=='C') {
            C_found=true;
            C_occurs.push_back(q);
        }
        if (C_found) {
            if (ancient_string[q]=='O') {
                O_found=true;
                O_occurs[q]=O_occurs[q-1]+1;
                O_occurs_indexes.push_back(q);
            }
            if (q!=length_of_string-1) {
                O_occurs[q+1]=O_occurs[q];
            }
            if (O_found) {
                if (ancient_string[q]=='W') {
                    W_occurs[q]=W_occurs[q-1]+1;
                }
                if (q!=length_of_string-1) {
                    W_occurs[q+1]=W_occurs[q];
                }
            }
        }
    }
    for (int c : C_occurs) {
        int o_num=O_occurs[O_occurs.size()-1]-O_occurs[c];
        for (int o=O_occurs_indexes.size()-o_num; o<O_occurs_indexes.size(); ++o) {
            int oo=O_occurs_indexes[o];
            num_COW_words+=W_occurs[W_occurs.size()-1]-W_occurs[oo];
        }
    }
    cout<<num_COW_words<<'\n';
    cout<<'\n'<<"C_occurs AKA C indexes containes: "<<'\n';
    for (int q : C_occurs) {
        cout<<q<<' ';
    }
    cout<<'\n'<<"O_occurs cumulative sums: "<<'\n';
    for (int w : O_occurs) {
        cout<<w<<' ';
    }
    cout<<'\n'<<"O_occurs_indexes contains: "<<'\n';
    for (int index : O_occurs_indexes) {
        cout<<index<<' ';
    }
    cout<<'\n'<<"W_occures cummulative sums contains: "<<'\n';
    for (int r : W_occurs) {
        cout<<r<<' ';
    }
}