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
ll *v;
int freq[1001000];
V<ll> g[1001000];
void solve(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        freq[arr[i]]++;        
    }
    ll ans = 0,s;
    for(int i = 0; i < 1001000; ++i){
        if(freq[i]){
            s = 0;
            for(int j = 0; j < g[i].size(); ++j){
                s+=freq[g[i][j]];
            }
            ans+=s*freq[i];
        }
    }
    ans-=n;
    cout << ans << endl;
    for(int i = 0; i < n; ++i){
        freq[arr[i]]--;        
    }
}

int main(){
    v = (ll*)calloc(1001000,sizeof(ll));
    for(int i = 2; i < 1001000; ++i)if(v[i] == 0)for(int j = 1; i*j < 1001000; ++j)v[i*j]+=i;
    ll mx = 0;
    for(int i = 1; i < 1001000; ++i){
        for(int j = 1; i*j < 1001000; ++j){
            if(v[i] && (v[i*j]%v[i]==0)){
                mx++;
                g[i].pb(i*j);
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}