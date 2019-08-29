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

ll dp[21][11][156];

// ll cal(ll n, ll k, ll s){
//     if(dp[n][k][s] != -1)return dp[n][k][s];

// }

ll solve(ll n, ll k, ll s){
    if(s < 0 || k < 0)return 0;
    if(n == 0)return ((s == 0 && k == 0)?1:0);
    ll &ret = dp[n][k][s];
    if(ret == -1){
        ret = solve(n-1,k,s) + solve(n-1,k-1,s-n);
    }
    return ret;
}

int main(){
    // FILE_READ_OUT
    memset(dp,-1,sizeof(dp));
    ll n,k,s;
    while(1){
        cin >> n >> k >> s;
        if(n == 0 && k == 0 && s == 0)break;
        cout << solve(n,k,s) << "\n";
    }
    return 0;
}