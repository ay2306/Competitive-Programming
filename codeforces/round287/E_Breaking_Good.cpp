#include<bits/stdc++.h>
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define V vector
#define pb emplace_back
#define PII pair<int,int>
#define ll long long
using namespace std;


const long long N = 1e5 + 100;
const long long inf = 1e9;
const long double pi = acos(-1);

struct edge{
    int u,v,r;
    edge(int u = 0, int v = 0, int r = 0): u(u),v(v), r(r){}
};


int n,m;
V<edge> g[N];

void bfs(V<int> &dis, V<int> &cnt, int s){
    V<int> vis(n+1,false);
    queue<int> q;
    q.emplace(s);
    vis[s] = true;
    dis[s] = 0;
    cnt[s] = 0;
    fill(dis.begin(),dis.end(),0);
    while(q.size()){
        int u = q.front();
        // cout << u << " : ";
        q.pop();
        for(auto &i: g[u]){
            int v = u ^ i.u ^ i.v;
            // cout << v << " " << vis[v] << "\n";
            if(!vis[v]){
                vis[v] = true;
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u] + i.r;
                q.emplace(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    V<edge> e;
    int a,b,c;
    while(m--){
        cin >> a >> b >> c;
        g[a].pb(a,b,c);
        g[b].pb(a,b,c);
        e.pb(a,b,c);
    }
    V<int> dis[2],cnt[2];
    dis[0] = V<int> (n+10,0);
    dis[1] = V<int> (n+10,0);
    cnt[0] = V<int> (n+10,0);
    cnt[1] = V<int> (n+10,0);
    bfs(dis[0],cnt[0],1);
    bfs(dis[1],cnt[1],n);
    int cur = 1;
    V<int> par(n+100,-1);
    int st = 0;
    while(cur != n){
        int c = -1;
        int tmp;
        for(auto &i: g[cur]){
            int v = i.u ^ i.v ^ cur;
            if(v == par[cur])continue;
            if(dis[0][v] + dis[1][v] == dis[1][1] && cnt[0][v] + cnt[1][v] + i.r > c){
                tmp = v;
                c = cnt[0][v] + cnt[1][v];
            }
        }
        par[tmp] = cur;
        cur = tmp;
    }
    V<edge> res;
    for(auto &i: e){
        int a = i.u;
        int b = i.v;
        if(par[a] == b || par[b] == a){
            if(i.r == 0){
                i.r = 1;
                res.pb(i);
            }
        }else{
            if(i.r == 1){
                i.r = 0;
                res.pb(i);
            }
        }
    }
    cout << res.size() << "\n";
    for(auto &i: res){
        cout << i.u << " " << i.v << " " << i.r << "\n";
    }
    return 0;
}