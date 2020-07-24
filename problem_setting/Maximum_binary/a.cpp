#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

string add(string a, string b){
    reverse(all(a));
    reverse(all(b));
    string ans = "";
    int c = 0;
    while(a.size() < b.size())a+="0";
    while(a.size() > b.size())b+="0";
    for(int i = 0; i < a.size(); ++i){
        int s = a[i] - '0' + b[i] - '0' + c;
        ans += char(s%2 + '0');
        c = s/2;
    }
    if(c)ans+="1";
    reverse(all(ans));
    return ans;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<string> other,candidate;
    while(n--){
        string a;
        cin >> a;
        if(a[0] == '0')candidate.emplace_back(a);
        else other.emplace_back(a);
    }
    sort(candidate.begin(),candidate.end(),[](const string &a, const string &b)->bool{
        for(int i = 0; i < a.size(); ++i){
            if(a[i] != b[i])return a[i]=='0';
        } 
        return true;
    });
    while(candidate.size() > k){
        other.emplace_back(candidate.back());
        candidate.pop_back();
    }
    string ans = "0";
    for(auto &i: candidate){
        for(auto &j: i){
            if(j == '1')j = '0';
            else j = '1';
        }
        ans = add(ans,i);
    }
    for(auto &i: other){
        ans = add(ans,i);
    }
    cout << ans;
    return 0;   
}