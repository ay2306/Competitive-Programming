/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e5;
ll n,m,l,s,t;
V<V<PLL> > adj;
V<V<ll> > edges;
V<bool> visited;
V<ll> dist;
V<PLL> Data;
int main(){
    cin >> n >> m >> l >> s >> t;
    adj = V<V<PLL> > (n+1);
    edges = V<V<ll> > (n+1,V<ll> (n+1,-1));
    visited = V<bool> (n+1,false);
    dist = V<ll> (n+1,-1);
    loop(i,0,m){
      ll a,b,c;
      cin >> a >> b >> c;
      adj[a].pb(mp(c,b));
      adj[b].pb(mp(c,a));
      edges[a][b] = c;
      edges[b][a] = c;
      Data.pb(mp(a,b));
    }
    V<ll> parent(n+1,-1);
    multiset<PLL> ms;
    dist[s] = 0;
    ms.insert(mp(0,s));
    while(ms.size()){
      ll u = ms.begin()->second;
      ms.erase(ms.begin());
      if(visited[u])continue;
      visited[u] = true;
      for(auto i: adj[u]){
        ll v = i.S;
        ll d = i.F;
        if(dist[v] == -1 || dist[v] > dist[u] + d){
          dist[v] = dist[u]+d;
          ms.insert(mp(dist[v],v));
          parent[v] = u;
        }
      }
    }
    V<PLL> eip;
    ll x = t;
    while(parent[x] != -1){
      if(edges[x][parent[x]] == 0)eip.pb(mp(x,parent[x]));
      x = parent[x];
    }
    if(dist[t] + eip.size() > l){
      printf("NO\n");
      return 0;
    }
    ll rem = l-dist[t];
    while(eip.size() > 1){
      PLL a = eip.back();
      eip.pop_back();
      edges[a.F][a.S] = 1;
      edges[a.S][a.F] = 1;
      rem--;
    }
    PLL a = eip.back();
    edges[a.F][a.S] = rem;
    edges[a.S][a.F] = rem;
    printf("YES\n");
    for(auto i: Data){
      if(edges[i.F][i.S] == 0)edges[i.F][i.S] = 100;
      printf("%lld %lld %lld\n",i.F,i.S,edges[i.F][i.S]);
    }
    return 0;
}
