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
#define MAXN 25
using namespace std;
V<V<PII> > adj;
V<int> dist;
V<bool> visited;
void solve(){
    int n,m;
    cin >> n >> m;
    adj = V<V<PII> > (n);
    dist = V<int> (n,-1);
    visited = V<bool> (n,false);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].pb(mp(c,b));
    }
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    dist[a] = 0;
    multiset<PII> s;
    s.insert(mp(0,a));
    while(s.size()){
        int u = s.begin()->second;
        s.erase(s.begin());
        if(visited[u])continue;
        visited[u] = true;
        for(auto i : adj[u]){
            if(visited[i.S])continue;
            int v = i.S;
            int d = i.F;
            if(dist[v] == -1 || dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                s.insert(mp(dist[v],v));
            }
        }
    }
    if(dist[b] == -1)cout << "NO\n";
    else cout << dist[b] << "\n";
}

int main(){
    // FILE_READ_IN
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}