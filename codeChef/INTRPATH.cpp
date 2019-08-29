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
#define all(container) container.begin(),container.end()
#define MAXN 25
using namespace std;
int n;
V<V<int>> adj;
V<bool> visited;
set<int> path;
int src, des;
V<int> parent;
ll ans;
ll cnt;
void bfs(int s){
    visited = V<bool>(n,false);
    path = set<int> ();
    parent[s] = -1;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto &v: adj[u]){
            if(!visited[v]){
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    loop(i,0,n)visited[i] = false;
    while(des != -1){
        path.insert(des);
        visited[des] = true;
        des = parent[des];
    }
}

void dfs(int s){
    cnt++;
    visited[s] = true;
    for(auto &i: adj[s])if(!visited[i])dfs(i);
}

void solve(){
    int q;
    cin >> n >> q;
    adj = V<V<int>> (n,V<int>());
    parent = V<int> (n,-1);
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    while(q--){
        cin >> src >> des;
        src--;
        des--;
        ans = 0;
        bfs(src);
        // for(auto &i: path){
        //     cout << i << " ";
        // }
        // cout << "\n";
        for(auto &i: path){
            V<ll> pos;
            pos.pb(1);
            for(auto &j: adj[i]){
                cnt = 0;
                // printf("i = %d: ",i+1);
                if(!visited[j]){
                    // printf("%d ",j+1);
                    dfs(j);
                    pos.pb(cnt);
                }
                // printf("\n");
            }
            // printf("FOR i = %lld: ", i);
            // for(auto &j: pos)printf("%lld ",j);
            // printf("\n");
            ll prt = 0;
            for(int itr = 0; itr < pos.size(); ++itr){
                for(int jtr = itr+1; jtr < pos.size(); ++jtr){
                    prt+=((pos[itr]*pos[jtr])%MOD);
                    prt%=MOD;
                }
            }
            ans+=prt;
            ans%=MOD;
        }
        ans+=path.size();
        ans%=MOD;
        printf("%lld\n",ans);
    }

}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}