#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    vector<int> a,b;
    int i, n = s.size();
    for(i = 0; i < n; ++i){
        if(s[i] == '.')break;
        a.emplace_back(s[i]-'0');
    }
    if(i+1 < n){
        i++;
        while(i < n){
            b.emplace_back(s[i++]-'0');
        }
    }
    vector<int> mant;
    reverse(a.begin(),a.end());
    while(a.size() && !a.back())a.pop_back();
    while(b.size() && !b.back())b.pop_back();
    reverse(a.begin(),a.end());
    if(b.size() == 0 && a.size() == 0)return void(cout << "0\n");
    int cnt = 0;
    if(a.size() == 0){
        cnt = -1;
        reverse(b.begin(),b.end());
        while(b.size() && !b.back())b.pop_back(),cnt--;
        cout << b.back();
        b.pop_back();
        reverse(b.begin(),b.end());
        while(b.size() && !b.back())b.pop_back(),cnt--;
        if(b.size()){
            cout << ".";
            for(auto i: b)cout << i;
        }
        cout << "E" << cnt;
        return;
    }
    for(auto i: a){
        if(cnt == 0)cout << i;
        else mant.emplace_back(i);
        cnt++;
    }
    for(auto i: b){
        if(cnt == 0)cout << i;
        else mant.emplace_back(i);
        cnt++;
    }
    while(mant.size() && !mant.back())mant.pop_back();
    if(mant.size()){
        cout << ".";
        for(int i: mant)cout << i;
    }
    if(a.size() != 1)cout << "E" << (int)a.size()-1;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}