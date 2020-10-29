#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;

const int N = 2e5+10;

vector<int> g[N];
int dp[N][20], lev[N], cnt[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a,b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    function<int(int,int)> dfs = [&](int s, int p)->int{
        lev[s] = ~p ? lev[p] + 1 : 0;
        dp[s][0] = ~p ? p : 0;
        int mx = s;
        for(int i: g[s]){
            if(i == p)continue;
            int res = dfs(i,s);
            if(lev[mx] < lev[res])mx = res;
            cnt[s]++;
        }
        return mx;
    };
    function<int(int,int)> LCA = [&](int a, int b)->int{
        if(lev[a] > lev[b])swap(a,b);
        int diff = lev[b] - lev[a];
        for(int i = 0; i < 20; ++i)if(diff>>i&1)b = dp[b][i];
        if(a == b)return a;
        for(int i = 19; ~i; --i){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        return dp[a][0];
    };
    function<int(int,int)> dist = [&](int a, int b)->int{
        return lev[a] + lev[b] - 2*lev[LCA(a,b)];
    };
    int p1 = dfs(1,-1);
    memset(cnt,0,sizeof(cnt));
    int p2 = dfs(p1,-1);
    int cur = p2;
    vector<int> arr;
    set<int> dia;
    while(cur){
        dia.emplace(cur);
        cur = dp[cur][0];
    }
    for(int j = 1; j < 20; ++j)
        for(int i = 1; i <= n; ++i)
            dp[i][j] = dp[dp[i][j-1]][j-1];
    for(int i = 1; i <= n; ++i){
        if(dia.count(i))continue;
        if(!cnt[i])arr.emplace_back(i);
    }
    long long sum = 0;
    // cout << p1 << " " << p2 << "\n";
    vector<pair<int,int>> ans;
    while(arr.size()){
        int u = arr.back();
        arr.pop_back();
        int v = dist(u,p1) > dist(u,p2) ? p1 : p2;
        sum += dist(u,v);
        ans.emplace_back(u,v);
        int parent = dp[u][0];
        cnt[parent]--;
        if(!cnt[parent])arr.emplace_back(parent);
    }
    while(p1 != p2){
        sum += dist(p1,p2);
        ans.emplace_back(p2,p1);
        p2 = dp[p2][0];
    }
    cout << sum << "\n";
    for(auto i: ans){
        cout << i.first << " " << i.second << " " << i.first << "\n";
    }
    return 0;
}