#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  map<string, int> records;
  records["Annabelle"]=0;
  records["Bessie"]=0;
  records["Daisy"]=0;
  records["Elsie"]=0;
  records["Gertie"]=0;
  records["Henrietta"]=0;
  records["Maggie"]=0;
  int n;
  cin>>n;
  for (int q=0; q<n; q++) {
    string s;
    int m;
    cin>>s>>m;
    records[s]+=m;
  }
  string loweststring;
  int min=records["Annabelle"];
  int max=records["Annabelle"];
  for (auto& amount : records) {
    if (amount.first!="Annabelle") {
      if (amount.second<min) {
        min=amount.second;
        loweststring=amount.first;
      }
      if (amount.second>max) {
          max=amount.second;
      }
    }
  }
  records.erase(loweststring);
  vector<string> toremove;
  for (auto& amount:records) {
      if (amount.second==min) {
          toremove.push_back(amount.first);
      }
  }
  for (string x:toremove) {
      records.erase(x);
  }
  if (records.empty()) {
    cout<<"Tie"<<'\n';
    return 0;
  }
  for (auto& amount : records) {
    //if (amount.first!="Annabelle") {
      if (amount.second<max) {
        max=amount.second;
      }
   // }
  }
  int counter=0;
  string oldminr;
  for (auto& amount : records) {
    if (amount.second==max) {
      counter+=1;
      oldminr=amount.first;
    }
    if (counter==2) {
      cout<<"Tie"<<'\n';
      return 0;
    }
  }
  cout<<oldminr<<'\n';
}
