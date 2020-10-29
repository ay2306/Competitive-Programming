#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &i: a)cin >> i;
    vector<string> k(m);
    vector<int> o(n);
    for(int i = 0; i < m; ++i){
        int b;
        cin >> b;
        o[b-1] = 1;
        k[i] = a[b-1];
    }
    for(auto &i: k)if(i.size() != k.back().size())return cout << "No\n",0;
    string ans = "";
    for(int i = 0; i < k.back().size(); ++i){
        map<char,int> p;
        for(auto &j: k)p[j[i]]++;
        if(p.size() == 1)ans+=k.back()[i];
        else ans+="?";
    }
    for(int i = 0; i < n; ++i){
        if(o[i])continue;
        if(ans.size() != a[i].size())continue;
        int cnt = 0;
        for(int j = 0; j < ans.size(); ++j)cnt+=(ans[j] == '?' || ans[j] == a[i][j]);
        if(cnt == ans.size())return cout << "No\n",0;
    }
    cout << "Yes\n";
    cout << ans;
    return 0;
}