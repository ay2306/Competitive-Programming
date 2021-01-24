#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> g[N],gr[N];
int vis[N],in[N],inr[N],dp[N],ans[N],dpR[N];

int main(){
    int n,m,cnt=0,A=0;
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        gr[b].emplace_back(a);
        in[b]++;
        inr[a]++;
    }
    fill(dp,dp+N,INT_MAX);
    fill(dpR,dpR+N,INT_MAX);
    queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(in[i] == 0)q.push(i);
    while(q.size()){
        int u = q.front();
        q.pop();
        in[u]--,cnt++;
        dp[u] = min(dp[u],u);
        for(int i : g[u]){
            dp[i] = min(dp[u],dp[i]);
            if(--in[i] == 0)
                q.push(i);
        }
    }
    if(cnt < n)return printf("-1"),0;
    for(int i = 1; i <= n; ++i)
        if(inr[i] == 0)q.push(i);
    while(q.size()){
        int u = q.front();
        q.pop();
        inr[u]--;
        dpR[u] = min(dpR[u],u);
        ans[u] = (dpR[u] < u || dp[u] < u ? 'E' : 'A');
        A+=(ans[u] == 'A');
        for(int i : gr[u]){
            dpR[i] = min(dpR[u],dpR[i]);
            if(--inr[i] == 0)
                q.push(i);
        }
    }
    printf("%d\n",A,cnt);
    for(int i = 1; i <= n; ++i)printf("%c",char(ans[i]));
    return 0;
}