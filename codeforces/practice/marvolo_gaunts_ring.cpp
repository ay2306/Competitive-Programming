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

int main(){
    ll n,p,q,r;
    cin >> n >> p >> q >> r;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    V<V<ll> > dp(n,V<ll> (3,LLONG_MIN));
    dp[0][0] = p*arr[0];
    dp[0][1] = (p+q)*arr[0];
    dp[0][2] = (p+q+r)*arr[0];
    // dp[i][j] means, If i try to include j+1 of required 3 variables till i
    // example dp[4][1] maximum value p*a1 + q*a2, with a1 and a2 lie between 0..i 
    loop(i,1,n){
        dp[i][0] = max(dp[i-1][0],arr[i]*p);
        dp[i][1] = max(dp[i-1][1],max(dp[i-1][0] + arr[i]*q, arr[i]*(p+q)));
        dp[i][2] = max(dp[i-1][2],max(dp[i-1][1] + arr[i]*r,max(dp[i-1][0]+arr[i]*(q+r),arr[i]*(p+q+r))));
    }
    cout << dp[n-1][2];
    return 0;
}