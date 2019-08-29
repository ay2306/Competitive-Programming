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
V<int> visited;
V<int> dist;
int n,m;

void bfs(int s = 0){
    visited = V<int> (n,0);
    dist = V<int> (n,0);
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto i: adj[u]){
            if(visited[i])continue;
            q.push(i);
            visited[i] = true;
            dist[i] = dist[u] + 1;
        }
    }
}

int main(){
    cin >> n >> m;
    adj = V<V<int> > (n);
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs();
    int mni = 0;
    for(int i = 0; i < n; ++i){
        if(dist[mni] < dist[i])mni = i;
    }
    bfs(mni);
    cout << *max_element(dist.begin(),dist.end());
    return 0;
}