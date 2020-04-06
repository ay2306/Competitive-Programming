//https://codeforces.com/contest/1187/problem/E
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5+10;

vector<int> g[N];
int parent[N];
int sub[N];
ll subrooted[N];
ll dp[N],ans;
int a,b,n;

void dfs(int s = 1, int p = 1){
    sub[s] = 1;
    dp[s] = 0;
    parent[s] = p;
    for(auto &i: g[s]){
        if(i == p)continue;
        dfs(i,s);
        sub[s]+=sub[i];
        dp[s]+=dp[i];
    }
    dp[s]+=sub[s];
}

void dfs1(int s = 1, int p = 1){
    ans = max(dp[s],ans);
    for(auto &i: g[s]){
        if(i == p)continue;
         dp[s] -=sub[i];        
         dp[s] -= dp[i];
        sub[s] -=sub[i];
    
         dp[i] +=sub[s];        
         dp[i] += dp[s];
        sub[i] +=sub[s];
        
        dfs1(i,s);

         dp[i] -=sub[s];        
         dp[i] -= dp[s];
        sub[i] -=sub[s];

         dp[s] +=sub[i];        
         dp[s] += dp[i];
        sub[s] +=sub[i];
    }
}

int main(){
    ans = 0;
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs();
    dfs1();
    cout << ans ;
    return 0;
}