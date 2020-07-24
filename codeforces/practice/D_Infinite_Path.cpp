#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
int n;
int col[N],vis[N];
map<pair<int,int>,bool> pos;
map<int,vector<int>> cycle;

bool check(int cycNo,int shift){
    vector<vector<int>> c;
    vector<int> &arr = cycle[cycNo];
    int m = arr.size();
    vector<int> vis(m);
    for(int i = 0; i < m; ++i){
        if(vis[i])continue;
        int j = i;
        vector<int> t;
        while(!vis[j]){
            vis[j] = true;
            t.emplace_back(arr[j]);
            j = (j+shift)%m;
        }
        c.emplace_back(t);
    }
    for(auto &i: c){
        bool v = true;
        for(int j = 1; j < i.size(); ++j)
            v = v && col[i[j]] == col[i[0]];
        if(v)return v;
    }
    return false;
}

void solve(){
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i)cin>>a[i];
    for(int i = 0 ; i < n ; ++i)a[i]--;
    for(int i = 0 ; i < n ; ++i)cin>>col[i];
    fill(vis,vis+n,0);
    pos.clear();
    cycle.clear();
    for(int i = 0; i < n; ++i){
        if(vis[i])continue;
        int j = i;
        vector<int> &t = cycle[i];
        while(!vis[j]){
            vis[j] = true;
            t.emplace_back(j);
            j = a[j];
        }
    }
    int ans = 1;
    while(1){
        bool valid = false;
        for(auto &i: cycle){
            if(valid)break;
            int components = __gcd((int)i.second.size(),ans);
            int min_shift = i.second.size()/components;
            pair<int,int> cc (i.first,components);
            if(pos.count(cc) == 0)pos[cc] = check(i.first,ans);
            valid = valid || pos[cc]; 
        }
        if(valid)break;
        ans++;
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}