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

int main(){
    int n,m;
    cin >> n >> m;
    V<V<PII> > adj(n,V<PII> ());
    V<bool> visited(n,false);
    V<ll> dist(n,-1);
    V<ll> parent(n,-1);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a].pb(mp(c,b));
        adj[b].pb(mp(c,a));
    }
    dist[0] = 0;
    multiset<PLL> s;
    s.insert(mp(0,0));
    while(s.size()){
        ll u = s.begin()->second;
        ll d = s.begin()->first;
        s.erase(s.begin());
        if(visited[u])continue;
        visited[u] = true;
        for(auto i: adj[u]){
            ll v = i.S;
            ll d = i.F;
            if(dist[v] == -1 || dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                s.insert(mp(dist[v],v));
                parent[v] = u;
            }
        }
    }
    if(dist[n-1] == -1){
        cout << -1;
        return 0;
    }
    V<ll> ans;
    int x = n-1;
    while(x != -1){
        ans.pb(x);
        x = parent[x];
    }
    for(int i = ans.size() - 1; i >= 0; --i){
        cout << ans[i] + 1 << " ";
    }
    return 0;
}