/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 998244353
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
ll dp[1010][1010];
ll c(ll n, ll r){
    if(n < r || n == 0)return 0;
    if(n == r)return 1; 
    if(r == 1)return n;
    if(dp[n][r] != 0)return dp[n][r];
    dp[n][r] = (c(n-1,r) + c(n-1,r-1))%MOD;
    return dp[n][r];
}
int main(){
    ll n;
    cin >> n;
    map<ll,int> s;
    ll ans = 0;
    loop(i,0,n){
        ll a;
        cin >> a;
        if(a < 0)continue;
        ans+=c(n-i-1,a);
        ll k = s[a];
        k = (k-1)*k;
        k/=2;
        cout << c(n-i-1,a) << endl;
        // ans-=k;
        ans%=MOD;
        s[a]++;
    }
    cout << ans;
    return 0;
}