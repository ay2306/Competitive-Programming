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
int n,m;
V<V<PII> > adj;
V<int> dist;
V<int> ind;
V<V<int> > bucket;
int maxw;
void quick_dijkstra(int a){
    dist = V<int> (n,-1);
    ind = V<int> (n,-1);
    bucket = V<V<int> > (maxw + 1);
    dist[a] = 0;
    ind[a] = 0;
    bucket[0].pb(a);
    int w = 0;
    while(w <= maxw){
        if(bucket[w].size() == 0){
            w++;
            continue;
        }
        int u = bucket[w].back();
        bucket[w].pop_back();
        for(auto i: adj[u]){
            int d = i.F;
            int v = i.S;
            if(d + dist[u] <= maxw && (dist[v] == -1 || dist[v] > d + dist[u])){
                if(dist[v] != -1){
                    int k = bucket[dist[v]].back();
                    swap(bucket[dist[v]][ind[v]],bucket[dist[v]][ind[k]]);
                    swap(ind[k],ind[v]);
                    bucket[dist[v]].pop_back();
                }
                dist[v] = dist[u] + d;
                ind[v] = bucket[dist[v]].size();
                bucket[dist[v]].pb(v);
            }
        }
    }
}

int main(){
    // FILE_READ_IN
    FAST
    cin >> n >> m;
    maxw = n*10;
    int q;
    cin >> q;
    map<PII,int> mop;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == b)continue;
        if(mop.find(mp(a,b)) != mop.end()){
            mop[mp(a,b)] = min(mop[mp(a,b)],c);
        }
        else if(mop.find(mp(b,a)) != mop.end()){
            mop[mp(b,a)] = min(mop[mp(b,a)],c);
        }
        else{
            mop[mp(a,b)] = c;
        }
    }
    adj = V<V<PII> > (n);
    for(auto i: mop){
        adj[i.F.F].pb(mp(i.S,i.F.S));
        adj[i.F.S].pb(mp(i.S,i.F.F));
    }
    while(q--){
        int a;
        cin >> a;
        quick_dijkstra(a);
        int mx = *max_element(dist.begin(),dist.end());
        int ct = 0;
        for(auto i: dist)ct+=(i == mx);
        cout << mx << " " << ct << "\n";
    }
    return 0;
}