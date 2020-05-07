// Tutorial : https://codeforces.com/blog/entry/337
#include<bits/stdc++.h>
using namespace std;

const int N = 1<<20;

int m,a,b,n;
long long dp[N][20],ans;
set<int> g[20];

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        a--,b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    for(int mask = 1; mask < (1 << n); ++mask){
        for(int j = 0; j < n; ++j){
            if(!((mask >> j)&1))continue;
            if(__builtin_popcount(mask) == 1)dp[mask][j] = 1;
            else{
                int first = __builtin_ffs(mask)-1;
                if(first == j)continue;
                for(const int &i: g[j]){
                    dp[mask][j]+=dp[mask^(1<<j)][i];
                }
                if(__builtin_popcount(mask) > 2 && g[j].count(first))ans+=dp[mask][j];
            }
        }
    }
    return printf("%lld",ans>>1),0;
}