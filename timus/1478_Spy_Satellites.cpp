#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(int n){
    struct edge{
        int u,v,w;
        edge(int u, int v, int w): u(u), v(v), w(w){}
        bool operator<(const edge rhs)const{
            return w < rhs.w;
        }
    };
    vector<edge> e;
    {
        int a,b;
        vector<pair<int,int>> points;
        for(int i = 0; i < n; ++i){
            scanf("%lld%lld",&a,&b);
            points.emplace_back(a,b);
        }
        auto dist = [](pair<int,int> a, pair<int,int> b)->int{
            return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
        };
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                e.emplace_back(i,j,dist(points[i],points[j]));
            }
        }
    }
    sort(e.begin(),e.end());
    vector<int> p(n),ans(n+1,0),sz(n+1,1),edgeSz(n,0);
    int components = n;
    function<int(int)> fp = [&](int x)->int{
        if(p[x] != x)p[x] = fp(p[x]);
        return p[x];
    };
    auto join = [&](int a, int b){
        a = fp(a);
        b = fp(b);
        if(a != b){
            p[a] = b;
            components--;
            sz[b] += sz[a];
            edgeSz[b] += edgeSz[a];
        }
        edgeSz[b]++;
    };
    iota(p.begin(),p.end(),0);
    ans[n] = 1;
    // for(auto i: e)printf("u = %d, v = %d, w = %d\n",i.u,i.v,i.w);
    for(int i = 0; i < e.size(); ++i){
        join(e[i].u,e[i].v);
        if(i+1 == e.size() || e[i].w != e[i+1].w){
            int cnt = 0;
            for(int j = 0; j < n; ++j){
                int k = fp(j);
                cnt += (sz[k]*(sz[k]-1)/2 != edgeSz[k]);
            }
            if(cnt == 0)ans[components] = 1;
        }
    }
    for(int i = 1; i <= n; ++i)printf("%lld",ans[i]);
    return void(printf("\n"));
}

int32_t main(){
    int n;
    while(1){
        scanf("%lld",&n);   
        if(n == 0)break;
        solve(n);
    }
    return 0;
}