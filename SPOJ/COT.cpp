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

int n;
V<V<int> > adj;
V<int> parent;
V<int> level;
V<int> first;
V<int> arr;
V<int> w;
V<int> lca_tree;
void p_dfs(int s = 0, int p = -1){
    if(first[s] == -1)first[s] = arr.size();
    arr.pb(s);
    if(s == 0)level[0] = 0;
    else level[s] = level[p]+1;
    parent[s] = p;
    for(auto &i: adj[s]){
        if(i == p)continue;
        else{
            p_dfs(i,s);
            arr.pb(s);
        }
    }
}

void build_lca_tree(int node = 0, int start = 0, int end = arr.size()-1){
    if(start == end){
        lca_tree[node] = start;
        return;
    }
    build_lca_tree(2*node+1,start,(start+end)/2);
    build_lca_tree(2*node+2,(start+end)/2+1,end);
    if(level[arr[lca_tree[2*node+1]]]  < level[arr[lca_tree[2*node+2]]])lca_tree[node] = lca_tree[2*node+1];
    else lca_tree[node] = lca_tree[2*node+2];
}

int lca_query(int l, int r, int node = 0,int start = 0, int end = arr.size()-1){
    if(start > r || end < l)return -1;
    if(l <= start && end <= r)return lca_tree[node];
    int p1 = lca_query(l,r,2*node+1,start,(start+end)/2);
    int p2 = lca_query(l,r,2*node+2,(start+end)/2+1,end);
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    else if(level[arr[p1]] < level[arr[p2]])return p1;
    return p2;
}

int main(){
    cin >> n;
    adj = V<V<int> > (n);
    parent = V<int>(n,-1);
    level = V<int> (n,0);
    first = V<int> (n,-1);
    w = V<int> (n,-1);
    loop(i,0,n)cin >> w[i];
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    p_dfs();
    lca_tree = V<int> (arr.size()*4);
    build_lca_tree();
    return 0;
}