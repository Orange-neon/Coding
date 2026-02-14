#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("1.in", "r", stdin);
    string article;
    getline(cin, article);
    string censor;
    getline(cin, censor);
    int censor_size=censor.size();
    int article_index=0;
    while (article_index<article.size() || article_index<0) {
        cout<<'\n'<<"Big while loop running with article index: "<< article_index<<'\n';
        if (article_index<0) {
            article_index=0;
        }
        if (article[article_index]==censor[0]) {
            cout<<'\n'<<"Possible Censored Word Detected"<<'\n';
            bool is_censored_word=true;
            int target_string_index=article_index+1;
            int censor_string_index=1;
            while (target_string_index<article_index+censor_size) {
                cout<<'\n'<<"_____________________________________________First Inside While Loop running with target_string_index: "<<target_string_index<<'\n';
                while (censor_string_index<censor_size) {
                    if (article[target_string_index]!=censor[censor_string_index]) {
                        cout<<'\n'<<"False alarm with real article character: "<<article[article_index]<<" and expected character: "<< censor[censor_string_index]<<'\n';
                        is_censored_word=false;
                        break;
                    }
                    ++censor_string_index;
                    ++target_string_index;
                }
                if (!is_censored_word) {
                    cout<<'\n'<<"Not a Censored Word_____________________________________"<<'\n';
                    break;
                }
                else {
                    cout<<'\n'<<"!!!!!!!!!!!!!!!!!!   CENSORED WORD DETECTED !!!!!!!!!!!!!!!!!!!!!!!"<<'\n';
                    cout<<'\n'<<"Before erasure: ";
                    for (char article_char : article) {
                        cout<<article_char;
                    }
                    cout<<'\n'<<"After Erasure: ";
                    article.erase(article_index, censor_size);
                    for (char article_char : article) {
                        cout<<article_char;
                    }
                    article_index=article_index-censor_size-1;
                    break;
                }
            }
        }
        ++article_index;
    }
    cout<<'\n'<<"Final Result: ";
    for (char article_char : article) {
        cout<<article_char;
    }
}