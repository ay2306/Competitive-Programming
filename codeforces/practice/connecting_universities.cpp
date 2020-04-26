//https://codeforces.com/problemset/problem/700/B
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> g[N];
int uni[N],n,a,b,k;
long long ans;
int dfs(int s = 1, int p = 0){
    #ifdef LOCAL
    printf("node = %d, parent = %d\n",s,p);
    #endif
    int sub = uni[s];
    for(int &i: g[s]){
        if(i == p)continue;
        sub+=dfs(i,s);
    }
    if(p)ans+=min(sub,2*k-sub);
    return sub;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= 2*k; ++i){
        scanf("%d",&a);
        uni[a] = 1;
    }
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs();
    return printf("%lld\n",ans),0;
}
