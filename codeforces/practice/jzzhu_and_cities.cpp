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

const ll inf = 1e18;

int main(){
  ll n,o,k;
  cin >> n >> o >> k;
  V<V<PII> > adj(n+1);
  V<ll> dist(n+1,inf);
  while(o--){
    ll a,b,c;
    cin >> a >> b >> c;
    adj[a].pb(mp(c,b));
    adj[b].pb(mp(c,a));
  }
  unordered_map<int,int> m;
  loop(i,0,k){
    ll a,b;
    cin >> a >> b;
    m[a] = 1;
    dist[a] = min(dist[a],b);
  }
  multiset<PLL> q;
  loop(i,2,n+1){
    if(m[i] == 1){
      q.insert(mp(dist[i],i));
    }
  }
  dist[1] = 0;
  q.insert(mp(0,1));
  V<bool> vis(n+1,false);
  while(q.size()){
    ll u = q.begin()->second;
    ll d1 = q.begin()->first;
    q.erase(q.begin());
    if(d1 != dist[u])continue;
    if(vis[u])continue;
    vis[u] = true;
    for(auto i = adj[u].begin(); i != adj[u].end(); ++i){
      ll v = i->second;
      if(vis[v])continue;
      ll d = i->first;
      if(dist[u] + d == dist[v])m[v] = 0;
      else if(dist[v] == inf || dist[v] > dist[u] + d){
        m[v] = 0;
        dist[v] = dist[u] + d;
        q.insert(mp(dist[v],v));
      }
    }
  }
  ll ans = 0;
  for(auto i: m){
    ans+=i.second;
  }
  cout << k-ans;
}
