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
#define all(a) a.begin(),a.end()
using namespace std;

const ll maxn = 1e5;
const ll inf = 1e18;
const ll max_height = 3e5+10;
V<V<int>> adj;
V<V<PLL>> queries;
V<ll> res;
V<ll> tree;
V<ll> lazy;
int n,q;

void update(int l, int r, ll val, int node = 0, int start = 0, int end = max_height-1){
    if(start > r || end < l)return ;
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(start != end){
            lazy[2*node + 1] += lazy[node];
            lazy[2*node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l <= start && end <= r){
        tree[node] += val;
        if(start != end){
            lazy[2*node+1] += val;
            lazy[2*node+2] += val;
        }
        return;
    }
    update(l,r,val,2*node+1,start,(start+end)/2);
    update(l,r,val,2*node+2,(start+end)/2+1,end);
}

ll query(int l, int r, int node = 0, int start = 0, int end = max_height-1){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(start != end){
            lazy[2*node + 1] += lazy[node];
            lazy[2*node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return -inf;
    if(l <= start && end <= r)return tree[node];
    return max(query(l,r,2*node+1,start,(start+end)/2),query(l,r,2*node+2,(start+end)/2+1,end));
}


void dfs(int currentNode, int parent, int height){
    for(auto &i: queries[currentNode]){
        update(height,min(max_height-1,height+i.F),i.S);
    }
    res[currentNode] = query(height,height);
    for(auto &i: adj[currentNode]){
        if(i != parent)dfs(i,currentNode,height+1);
    }
    for(auto &i: queries[currentNode]){
        update(height,min(max_height-1,height+i.F),-i.S);
    }
}

int main(){
    FAST
    cin >> n;
    adj = V<V<int>> (n);
    queries = V<V<PLL>> (n);
    res = V<ll> (n,0);
    tree = V<ll> (4*max_height,0);
    lazy = V<ll> (4*max_height,0);
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> q;
    while(q--){
        int v;
        ll k,d;
        cin >> v >> k >> d;
        queries[v-1].pb(mp(k,d));
    }
    dfs(0,0,0);
    for(auto &i: res){
        cout << i << " ";
    }
  return 0;
}
