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
V<V<int> > adj;
V<V<int> > cycles;
int n,m;

void dfs_cycle(int s, int parent, int *color, int *mark, int *par, int &cycleNumber){
    if(color[s] == 2){
        return;
    }
    if(color[s] == 1){
        cycleNumber++;
        int cur = parent;
        mark[cur] = cycleNumber;
        while(cur != s){
            cur = par[cur];
            mark[cur] = cycleNumber;
        }
        return;
    }
    par[s] = parent;
    color[s] = 1;
    for(auto i: adj[s]){
        if(i == par[s])continue;
        dfs_cycle(i,s,color,mark,par,cycleNumber);
    }
    color[s] = 2;
}

void print_cycle(int edges, int *mark, int &cycleNumber){
    for(int i = 0; i < edges; ++i){
        if(mark[i] != 0)continue;
    }
}

int main(){
    cin >> n >> m;
    int edges = m;
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    V<int> color(n);
    V<int> par(n);
    V<int> mark(n);
    int cycleNumber = 0;
    return 0;
}