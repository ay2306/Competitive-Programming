#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
map<int,int> cnt[N];
int ans[N],sub[N],col[N];
int n,a,b;

int subSize(int s, int p = -1){
    sub[s] = 1;
    for(int i: g[s])if(i!=p)sub[s]+=subSize(i,s);
    return sub[s];
}

int dsu(int s, int p = -1){
    int big = -1, mx = -1;
    for(int i : g[s])
        if(i != p && sub[i] > mx)big = i,mx = sub[i];
    mx = -1;
    for(int i: g[s])
        if(i != p && i != big)dsu(i,s);
    if(~big){
        mx = dsu(big,s);
        ans[s] = ans[big];
        swap(cnt[s],cnt[big]);
    }
    for(int i: g[s]){
        for(auto j: cnt[i]){
            cnt[s][j.first]+=j.second;
            if(cnt[s][j.first] == mx)ans[s]+=j.first;
            else if(cnt[s][j.first] > mx)mx = cnt[s][j.first],ans[s] = j.first;
        }
    }
    cnt[s][col[s]]++;
    if(cnt[s][col[s]] == mx)ans[s]+=col[s];
    else if(cnt[s][col[s]] > mx)mx = cnt[s][col[s]],ans[s] = col[s];
    return mx;
}

signed main(){
    scanf("%lld",&n);
    for(int i = 1; i <= n; ++i)scanf("%lld",col+i);
    for(int i = 1; i < n; ++i){
        scanf("%lld%lld",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    subSize(1);
    dsu(1);
    for(int i = 1; i <= n; ++i)printf("%lld ",ans[i]);
    return 0;
}