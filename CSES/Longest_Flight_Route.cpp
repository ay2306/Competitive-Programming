#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,m,a,b;
vector<int> g[N];
int in[N],dis[N],p[N];
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        in[b]++;
        g[a].emplace_back(b);
    }
    if(in[1])return printf("IMPOSSIBLE\n"),0;
    queue<int> q;
    for(int i = 2; i <= n; ++i){
        if(in[i])continue;
        q.emplace(i);
    }
    while(q.size()){
        for(int v : g[q.front()])
            if(in[v]-- == 1)q.emplace(v);
        q.pop();
    }
    memset(dis,-1,sizeof(dis));
    q.emplace(1);
    dis[1] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            in[v]--;
            if(in[v] == 0){
                q.emplace(v);
                dis[v] = dis[u] + 1;
                p[v] = u;
            }
        }
    }
    if(dis[n] == -1)return printf("IMPOSSIBLE\n"), 0;
    vector<int> ans;
    while(n){
        ans.emplace_back(n);
        n = p[n];
    }
    reverse(ans.begin(),ans.end());   
    printf("%d\n",(int)ans.size());
    for(int i : ans)printf("%d ",i);
    return 0;
}