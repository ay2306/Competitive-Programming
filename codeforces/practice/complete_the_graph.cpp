 //https://codeforces.com/problemset/problem/715/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3;

struct edge{
  int a, b;
  long long w;
  edge(int a, int b, long long w):a(a),b(b),w(w){}
};

vector<edge> e;
vector<int> g[N];
int n,m,a,b,w,l,s,t,vis[N];
long long dis[N],parent[N];
map<pair<int,int>,int> ind;
vector<int> special;
vector<int> timeChanged;
vector<int> specialIncluded[10*N];
void djikstra(int source){
  fill(vis,vis+N,false);
  fill(dis,dis+N,LLONG_MAX);
  dis[source] = 0;
  parent[source] = -1;
  multiset<pair<long long,int>> m;
  m.emplace(0,source);
  while(m.size()){
    int u = m.begin()->second;
    long long DIS = m.begin()->first;
    m.erase(m.begin());
    if(vis[u])continue;
    vis[u] = 1;
    for(auto &i: g[u]){
      int v = u^e[i].a^e[i].b;
      long long d = e[i].w;
      if(dis[v] > d+DIS){
        dis[v] = d+DIS;
        m.emplace(d+DIS,v);
        parent[v] = u;
      }
    }
  }
}

int main(){
  scanf("%d%d%d%d%d",&n,&m,&l,&s,&t);
  for(int i = 0; i < m; ++i){
    scanf("%d%d%d",&a,&b,&w);
    ind[{a,b}] = i;
    ind[{b,a}] = i;
    e.emplace_back(a,b,w);
    if(w){
      g[a].emplace_back(i);
      g[b].emplace_back(i);
    }else{
      special.emplace_back(i);
    }
  }
  sort(special.begin(),special.end());
  djikstra(s);
  if(dis[t] < l)return printf("NO\n"),0;
  for(auto &i: special){
    g[e[i].a].emplace_back(i);
    g[e[i].b].emplace_back(i);
    e[i].w = 1;
  }
  djikstra(s);
  set<int> inc;
  if(dis[t] > l)return printf("NO\n"),0;
  // for(int i = 0 ; i < n; ++i)cout << dis[i] << " ";
  // cout << endl;
  while(1){
    int cur = t, p = parent[t];
    vector<int> spec;
    while(~p){
        int id = ind[{cur,p}];
        if(binary_search(special.begin(),special.end(),id) && !inc.count(id))spec.emplace_back(id);
        cur = p;
        p = parent[p];
    }
    if(spec.size() == 0)break;
    int lst = spec.back();
    ll ch = l - dis[t];
    e[spec.back()].w += ch;
    for(int i: specialIncluded[lst])e[i].w-=ch;
    inc.emplace(spec.back());
    spec.pop_back();
    for(int i: spec)specialIncluded[i].emplace_back(lst);

    djikstra(s);
  }
  for(int i : special){
    if(inc.count(i))continue;
    e[i].w = (ll)2e9;
  }
  printf("YES\n");
  for(auto i: e)printf("%d %d %lld\n",i.a,i.b,i.w);
  return 0;
}
