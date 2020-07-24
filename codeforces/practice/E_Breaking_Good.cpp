#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<pair<int,int>> g[N];
vector<pair<int,pair<int,int>>> e;
int n,m,b,a,c;

void bfs(int source, vector<int> &dis, vector<int> &cnt){
    dis[source] = 0;
    queue<int> q;
    q.emplace(source);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto& [v,r]: g[u]){
            if(~dis[v])continue;
            dis[v] = dis[u] + 1;
            cnt[v] = cnt[u] + r;
            q.emplace(v);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d",&a,&b,&c);
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
        e.emplace_back(make_pair(c,make_pair(a,b)));
    }
    vector<int> dis[2], cnt[2];
    for(int i = 0; i < 2; ++i)dis[i] = vector<int> (n+1,-1);
    for(int i = 0; i < 2; ++i)cnt[i] = vector<int> (n+1,0);
    bfs(1,dis[0],cnt[0]);
    bfs(n,dis[1],cnt[1]);
    vector<int> parent(n+1,-1);
    int u = 1;
    for(int distance = dis[1][1]-1; distance >= 0; --distance){
        int tmp, c = -1;
        for(auto& [v,r]: g[u]){
            if(parent[u] == v)continue;
            if(dis[1][v] == distance && cnt[0][v] + cnt[1][v] > c)c = cnt[0][v] + cnt[1][v], tmp = v;
        }
        parent[tmp] = u;
        u = tmp;
    }
    vector<pair<pair<int,int>,int>> ans;
    for(auto& [r,ed]: e){
        if(parent[ed.first] == ed.second || parent[ed.second] == ed.first){
            if(!r)ans.emplace_back(ed,1);
        }else if(r)ans.emplace_back(ed,0);
    }
    printf("%d\n",ans.size());
    for(auto &i: ans)printf("%d %d %d\n",i.first.first,i.first.second,i.second);
    return 0;
}