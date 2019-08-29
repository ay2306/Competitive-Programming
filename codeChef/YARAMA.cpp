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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
V<V<int> > adj;
V<bool> visited;

int dfs(int s){
    if(visited[s])return 0;
    int ans = 1;
    visited[s] = true;
    for(auto i: adj[s]){
        ans+=dfs(i);
    }
    return ans;
}

ll maxSubarrayXOR(V<ll> set, int n) 
{ 
    ll index = 0; 
    for (ll i = 64-1; i >= 0; i--) 
    { 
        ll maxInd = index; 
        ll maxEle = LLONG_MIN; 
        for (ll j = index; j < n; j++) 
        { 
            if ( (set[j] & (1 << i)) != 0  
                     && set[j] > maxEle ) 
                maxEle = set[j], maxInd = j; 
        } 
        if (maxEle == LLONG_MIN) 
        continue; 
        swap(set[index], set[maxInd]); 
        maxInd = index; 
      for (ll j=0; j<n; j++) 
        { 
            if (j != maxInd && 
               (set[j] & (1 << i)) != 0) 
                set[j] = set[j] ^ set[maxInd]; 
        } 
        index++; 
    } 
    ll res = 0; 
    for (ll i = 0; i < n; i++) 
        res ^= set[i]; 
    return res; 
} 
void solve(){
    int n,m;
    cin >> n >> m;
    adj = V<V<int> > (n,V<int> ());
    visited = V<bool> (n,false);
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    V<ll> s;
    unordered_map<int,int> c;
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            int a = dfs(i);
            if(c.find(a) == c.end()){
                c[a] = 1;
                s.pb(a);
            }
        }
    }
    n = s.size();
    ll ans = maxSubarrayXOR(s,s.size());
    cout << ans ;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}