#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
    struct edge{
        int u,v,w;
        edge(int u, int v, int w): u(u), v(v), w(w){}
        bool operator<(const edge& rhs)const{
            return w < rhs.w;
        }
    };
    vector<edge> e;
    const int mod = 998244353;
    int n,a,b,c;
    scanf("%lld",&n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%lld",&a);
            if(i < j)e.emplace_back(i,j,a);
        }
    }
    vector<int> p(n+1), sz(n+1,1), edgeSz(n+1,0);
    vector<vector<int>> dp (n+1, {0,1});
    iota(p.begin(),p.end(),0);
    function<int(int)> fp = [&](int x)->int{
        if(p[x] != x)p[x] = fp(p[x]);
        return p[x];
    };
    auto join = [&](int a, int b){
        a = fp(a);
        b = fp(b);
        if(a != b){
            p[a] = b;
            vector<int> ans(sz[a]+sz[b]+1);
            for(int sz1 = 0; sz1 <= sz[a]; ++sz1){
                for(int sz2 = 0; sz2 <= sz[b]; ++sz2){
                    int k = sz1 + sz2;
                    ans[k] += dp[a][sz1] * dp[b][sz2] % mod;
                    if(ans[k] >= mod)ans[k]-=mod;
                }
            }
            dp[b] = ans;
            sz[b] += sz[a];
            edgeSz[b]+=edgeSz[a];
        }
        edgeSz[b]+=1;
        if(sz[b]*(sz[b]-1)/2 == edgeSz[b]){
            dp[b][1] += 1;
            if(dp[b][1] >= mod)dp[b][1] -= mod;
        }
    };
    sort(e.begin(),e.end());
    for(auto &i: e){
        join(i.u,i.v);
    }
    for(int k = 1; k <= n; ++k)printf("%lld ",dp[fp(1)][k]);
    return 0;
}