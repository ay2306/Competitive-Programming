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
V<int> arr;
V<bool> visited;
int n,m;
int ans;
void dfs(int s, int ct){
    visited[s] = true;
    ct+=arr[s];
    if(arr[s] == 0)ct = 0;
    if(ct > m)return;
    if(adj[s].size() == 1 && s != 0){
        if(ct <= m){
            ans++;
            // cout << s << "\n";
        }
        return;
    }
    for(auto i: adj[s]){
        if(!visited[i]){
            dfs(i,ct);
        }
    }
}
int main(){
    FAST
    ans = 0;
    cin >> n >> m;
    arr = V<int> (n);
    adj = V<V<int> > (n,V<int>());
    visited = V<bool> (n,false);
    loop(i,0,n)cin >> arr[i];
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    dfs(0,0);
    cout << ans;
    return 0;
}