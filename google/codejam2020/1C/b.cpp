#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
void solve(int tc){
    int u,x;
    cin >> u;
    set<char> used,res[10],appear;
    for(int i = 0; i < maxn; ++i){
        string s;
        cin >> x >> s;
        if(x >= 0 && s <= 9){
            for(char &j: s)res[x].insert(j);
        }
        for(char &j: s)appear.insert(j);
    }
    string ans = "";
    for(int i = 1; i <= 9; ++i){
        vector<char> to_del;
        for(auto &j: res[i]){
            if(used.count(j))to_del.emplace_back(j);
        }
        for(auto &j: to_del){
            res[i].erase(j);
        }
        ans += *res[i].begin();
        used.insert(*res[i].begin());
    }
    for(auto &i: appear){
       if(!used.count(i)){
         ans = i+ans;
         break;
       }
    }
    cout << "Case #" << tc << ": " << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    for(int i = 1;i <= t; ++i)solve(i);
    return 0;
}