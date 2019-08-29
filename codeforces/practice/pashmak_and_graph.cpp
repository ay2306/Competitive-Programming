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

const ll N = 1e5 + 10;
V<PLL> adj[N];
ll dp[3*N];
ll mx[3*N];
int main(){
    FAST
    int n,m;
    cin >> n >> m;
    loop(i,0,m){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[c].pb(mp(a,b));
    }
    loop(i,0,N){
        for(auto &j: adj[i]){
            mx[j.S] = 0;
        }
        for(auto &j: adj[i]){
            mx[j.S] = max(mx[j.S],dp[j.F]+1);
        }
        for(auto &j: adj[i]){
            dp[j.S] = max(mx[j.S],dp[j.S]);
        }
    }
    ll ans = 0;
    loop(i,0,3*N){
        ans = max(ans,dp[i]);
    }
    cout << ans;
  return 0;
}
