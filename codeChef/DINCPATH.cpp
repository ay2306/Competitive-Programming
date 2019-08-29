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

void solve(){
    int n,o;
    cin >> n >> o;
    V<ll> arr(n+1);
    map<ll,V<PLL> > adj;
    loop(i,1,n+1)cin >> arr[i];
    loop(i,0,o){
        ll a,b;
        cin >> a >> b;
        if(arr[a] > arr[b])adj[arr[a]-arr[b]].pb(mp(b,a));
        if(arr[a] < arr[b])adj[arr[b]-arr[a]].pb(mp(a,b));
    }
    V<ll> mx(2*n,0);
    V<ll> dp(2*n,0);
    for(auto &i: adj){
        if(i.F <= 0)continue;
        for(auto &j: i.S){
            mx[j.S] = 0;
        }
        for(auto &j: i.S){
            mx[j.S] = max(mx[j.S],dp[j.F]+1);
        }
        for(auto &j: i.S){
            dp[j.S] = max(mx[j.S],dp[j.S]);
            // printf("u = %lld, v = %lld, i.F = %lld, dp[v] = %lld, mx[v] = %lld\n",j.F,j.S,i.F,dp[j.S],mx[j.S]);
        }
    }
    ll ans = 0;
    for(auto &i:dp)ans = max(ans,i);
    ans++;
    cout << ans << "\n";
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}