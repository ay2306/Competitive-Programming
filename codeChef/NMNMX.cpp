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
// #define MAXN 25
using namespace std;

const ll maxn = 1e4 + 10;

ll cnk[maxn][maxn];

ll power(ll a,ll n){
    if(n == 0)return 1;
    if(n == 1)return a;
    ll b = power(a,n/2);
    if(n%2 == 0)return ((b%MOD)*(b%MOD))%MOD;
    return (a%MOD*(((b%MOD)*(b%MOD))%MOD))%MOD;
}

ll C(ll n, ll r){
    return cnk[n][r];
    if(n < r)return 0;
    if(n == 0)return 0;
    if(n == 1)return n;
    if(n == r)return 1;
    if(n == r+1)return n;
    if(cnk[n][r] == 0)cnk[n][r] = C(n-1,r-1) + C(n-1,r);
    return cnk[n][r];
}

void solve(){
    ll n,k;
    cin >> n >> k;
    ll *arr = new ll[n+1];
    for(ll i = 1; i <= n; ++i)cin >> arr[i];
    sort(arr+1,arr+n+1);
    // ll *cnt = new ll[n+1];
    // for(ll i = 1; i <= n; ++i){
        // cnt[i] = 0;
        // cout << cnt[i] << " ";
    // }
    // cout << endl;
    ll ans = 1;
    for(ll i = 1; i <= n; ++i){
        // cout << arr[i] << " ";
        // cnt[i] += (C(n-i,k-1)*(C(i-1,k-1)))%(MOD-1);
        // cout << cnt[i] << " " << C(n-i,k-1) << " ";
        // cnt[i] += ;
        // cout << cnt[i] << " " << C(i-1,k-1) << " ";
        // cnt[i] = cnt[i]%(MOD-1);
        // cnt[i] = C(n-1,k-1) - cnt[i];
        // cout << cnt[i] << "\n";
        // cnt[i]%=(MOD-1);
        ll cnt = 0;
        for(ll l = 1; l < i; ++i){
            ll r = k-l-1;
            if(r <= 0){
                continue;
            }
            cnt = (cnt + cnk[i-1][l]*cnk[n-i][r])%(MOD-1);
        }
        ans = (ans*power(arr[i],cnt))%MOD;
    }
    // cout << cnk[5][2] << endl;
    // for(ll i = 1; i <= n; ++i){
    //     ll tmp = power(arr[i],cnt[i]);
    //     ans = (ans%MOD * tmp%MOD)%MOD;
    //     // cout << arr[i] << " " << cnt[i] << " " << tmp << endl;
    // }
    cout << ans << endl;
}

int main(){
    FAST
    for(ll i = 0 ; i < maxn; ++i){
        cnk[i][0] = 1;
        for(ll j = 1; j <= i; ++j){
            cnk[i][j] = (cnk[i-1][j-1] + cnk[i-1][j])%(MOD-1);
        }
    }
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}