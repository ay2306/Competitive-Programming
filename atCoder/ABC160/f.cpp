#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod = 1e9+7;
const int N = 2e5+7;
int n,a,b;
vector<int> g[N];
ll dp[N],sub[N],ans[N],inv[N],f[N];


ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    ll p = power(a,n/2);
    p*=p;
    p%=mod;
    if(n%2)p*=a;
    p%=mod;
    return p;
}

ll mi(ll a){return power(a,mod-2);}

void dfs(int s = 1, int p = -1){
    dp[s] = 1;
    sub[s] = 0;
    for(auto &i : g[s]){
        if(i == p)continue;
        dfs(i,s);
        sub[s]+=sub[i];
    }
    dp[s] = dp[s]*f[sub[s]]%mod;
    for(auto &i: g[s]){
        if(i == p)continue;
        dp[s] = dp[s]*dp[i]%mod;
        dp[s] = dp[s]*inv[sub[i]]%mod;
    }
    sub[s]++;
}

void dfs2(int s = 1, int p = -1){
    ans[s] = dp[s];
    for(auto &i:g[s]){
        if(i == p)continue;
        dp[s] = dp[s]*mi(dp[i])%mod;
        dp[s] = dp[s]*f[sub[i]]%mod;
        dp[s] = dp[s]*inv[sub[s]-1]%mod;
        dp[s] = dp[s]*f[sub[s]-sub[i]-1]%mod;
        sub[s]-=sub[i];
        dp[i] = dp[i]*dp[s]%mod;
        dp[i] = dp[i]*inv[sub[s]]%mod;
        dp[i] = dp[i]*inv[sub[i]-1]%mod;
        sub[i] += sub[s];
        dp[i] = dp[i]*f[sub[i]-1]%mod;
        dfs2(i,s);
         dp[i] = dp[i]*inv[sub[i]-1]%mod;
        sub[i]-=sub[s];
         dp[i] = dp[i]*f[sub[i]-1]%mod;
         dp[i] = dp[i]*f[sub[s]]%mod;
         dp[i] = dp[i]*mi(dp[s])%mod;
        sub[s] += sub[i];
         dp[s] = dp[s]*inv[sub[s]-sub[i]-1]%mod;
         dp[s] = dp[s]*f[sub[s]-1]%mod;
         dp[s] = dp[s]*inv[sub[i]]%mod;
         dp[s] = dp[s]*dp[i]%mod;
        //  dp[i] = dp[i]*f[sub[i]-sub[s]-1]%mod;
    }
}

int main(){
    inv[0] = 1;
    inv[1] = 1;
    f[0] = 1;
    f[1] = 1;
    for(int i=2; i<N; ++i)inv[i]=mod-mod/i*inv[mod%i]%mod,f[i]=i;
    for(int i=2; i<N; ++i)inv[i]=inv[i-1]*inv[i]%mod,f[i]=f[i]*f[i-1]%mod;
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs();
    // for(int i = 1; i <= n; ++i)printf("FOR i = %d, dp[i] = %lld\n",i,dp[i]);
    // for(int i = 1; i <= n; ++i){
    //     dfs(i,-1);
    //     printf("FOR NODE = %d, dp[i] = %lld\n",i,dp[i]);
    // }
    dfs2();
    for(int i = 1; i <= n; ++i)printf("%lld\n",ans[i]);
    return 0;
}