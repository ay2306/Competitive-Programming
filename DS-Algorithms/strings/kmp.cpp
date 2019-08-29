#include<bits/stdc++.h>
using namespace std;
string pattern,text;
vector<int> lps;

void computeLPS(){
    int j = 0;
    lps[0] = 0;
    int i = 1;
    while(i < pattern.size()){
        // printf("Working for character %c at i = %d, j = %d, lps[j] = %d\n",pattern[i],i,j,lps[j]);
        if(pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            ++i;
        }else{
            if(j != 0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> kmp(){
    vector<int> ans;
    lps = vector<int> (pattern.size(),0);
    computeLPS();
    int i = 0;
    int j = 0;
    while(i < text.size()){
        if(pattern[j] == text[i]){
            j++;
            i++;
            if(j == pattern.size()){
                ans.push_back(i-j);
                j = lps[j-1];
            }
        }else{
            if(j != 0)j = lps[j-1];
            else i++;
        }
    }
    return ans;
}
int main(){
    cin >> pattern;
    cin >> text;
    kmp();
    vector<int> res = kmp();
    // if(res.size() == 0)cout << "No"
    cout << res.size();
    return 0;
}