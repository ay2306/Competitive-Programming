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
V<bool> visited;
V<int> arr;
bool ans;

void dfs(int i, int a){
    if(!ans)return;
    visited[i] = true;
    arr[i] = a;
    for(auto k:adj[i]){
        if(!visited[k.first])dfs(k.first,k.second^a);
        else{
            if(arr[k.first] != (arr[i]^k.second)){
                // cout << "FAILED at 2\n";
                // printf("i = %d, arr[i] = %d, k = (%d,%d), arr[k.first] = %d\n",i,k.F,k.S,arr[k.F]);
                ans = false;
                return;
            }
        }
    }
}

void solve(){
    ans = true;
    int n,q;
    cin >> n >> q;
    adj = V<V<PII> > (n,V<PII>());
    visited = V<bool> (n,false);
    arr = V<int> (n,-1);
    map<PII,int> m;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        if(a == b){
            if(c == 1)ans=false;
            continue;
        }
        if(m.find(mp(b,a)) != m.end() && m[mp(a,b)]!=c){
            // cout << "FAILED at 1\n";
            ans = false;
        }
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }

    for(int i = 0; i < n && ans; ++i){
        if(!visited[i]){
            dfs(i,1);
        }
    }
    if(ans)cout << "yes\n";
    else cout << "no\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}