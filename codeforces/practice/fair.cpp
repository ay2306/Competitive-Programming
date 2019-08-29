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

const ll maxn = 1e7;

V<V<int> > adj;
V<V<int> > item;
int main(){
    int n,m,k,s;
    cin >> n >> m >> k >> s;
    item = V<V<int> > (k+1,V<int> ());    
    adj = V<V<int> > (n+1,V<int> ());    
    for(int i = 0; i < k; ++i){
        int a;
        cin >> a;
        a--;
        item[a].pb(i);
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int c = 0; c < k; ++c){
        V<int> dist(n,maxn);
        int topQ = 0;
        V<int> q(n);
        for(auto x: item[c]){
            dist[x] = 0;
            q[topQ++] = x;
        }
        for(int i = 0; i < topQ; ++i){
            int v = q[i];
            for(auto u: adj[v]){
                if(dist[u] <= dist[v]+1)continue;
                dist[u] = dist[v] + 1;
                q[topQ++] = u;
            }
        }
    }
    return 0;
}