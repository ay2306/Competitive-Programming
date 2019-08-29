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
int n,m,k;
V<V<int> > adj;
V<int> CLASS;

int bfs(int c){
    V<int> parent(n,-1);
    V<int> color(n,-1);
    V<int> arr(k,0);
    int ans = 0;
    queue<int> q;
    q.push(0);
    color[0] = c;
    if(c)arr[CLASS[0]] = 1;
    if(c)ans++;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto i: adj[u]){
            if(i == parent[u])continue;
            parent[i] = u;
            color[i] = 1 - color[u];
            q.push(i);
            if(color[i] == 1){
                ans++;
                arr[CLASS[i]] = 1;
            }
        }
    }
    int prod = 1;
    for(auto i: arr){
        prod *= i;
    }
    if(prod)return ans;
    for(auto i: CLASS){
        if(arr[i] == 0){
            ans++;
            arr[i] = 1;
        }
    }
    prod = 1;
    for(auto i: arr){
        prod *= i;
    }
    if(prod)return ans;
    return n+1;
}


void solve(){
    cin >> n >> m >> k;
    adj = V<V<int> > (n,V<int> ());    
    CLASS = V<int> (n);
    loop(i,0,n){
        cin >> CLASS[i];
        CLASS[i]--;
    }
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = min(bfs(1),bfs(0));
    if(ans == n+1)cout << "-1";
    else cout << ans;

}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}