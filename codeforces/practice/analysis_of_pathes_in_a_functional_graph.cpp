//https://codeforces.com/gym/277321/problem/E
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;
const int LN = 40;

ll sum[N][LN], mx[N][LN], k, b, dp[N][LN];
vector<pair<ll,int>> g[N];
int n, a , vis[N], f[N];

void dfs(int s){
    if(vis[s])return;
    vis[s] = true;
    for(auto &i : g[s]){
        dp[i.second][0] = s;
        mx[i.second][0] = i.first;
        sum[i.second][0] = i.first;
        dfs(i.second);
    }
}

int main(){
    scanf("%d%lld",&n,&k);
    for(int i = 0; i < n; ++i){
        scanf("%d",f+i);
    }
    for(int i = 0; i < n; ++i){
        scanf("%lld",&b);
        g[f[i]].emplace_back(b,i);
    }
    for(int i = 0; i < n; ++i)dfs(i);
    for(int j = 1; j < LN; ++j){
        for(int i = 0; i < n; ++i){
            dp[i][j] = dp[dp[i][j-1]][j-1];
            sum[i][j] = sum[dp[i][j-1]][j-1]+sum[i][j-1];
            mx[i][j] = min(mx[dp[i][j-1]][j-1],mx[i][j-1]);
        }
    }
    for(int i = 0; i < n; ++i){
        ll sm = 0, m = LLONG_MAX;
        int j = i;
        for(int bit = 0; bit < LN; ++bit){
            if((k>>bit)&1){
                sm = sm+sum[j][bit];
                m = min(m,mx[j][bit]);
                j = dp[j][bit];
            }
        }
        printf("%lld %lld\n",sm,m);
    }
    return 0;
}