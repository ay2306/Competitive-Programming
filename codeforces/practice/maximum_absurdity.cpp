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

int main(){
    FAST
    ll n,k,d;
    cin >> n >> k;
    vector<ll> arr(n+10,0);
    vector<ll> sp(n+10,0);
    vector<ll> dp(n+10,0);
    vector<ll> dpp(n+10,0);
    loop(i,0,n){
        cin >> d;
        sp[i+1] = sp[i]+d;
    }
    for(int i = k; i<=n;++i){
        dp[i-k+1] = sp[i]-sp[i-k];
    }
    dpp[1] = dp[1];
    for(int i = 1; i <= n-k+1; ++i){
        dpp[i] = max(dpp[i-1],dp[i]);
    }
    ll ma = -1,h=0;
    ll r = 0,l=0;
    for(int i = n-k+1; i > k; --i){
        h = dp[i];
        h+=dpp[i-k];
        if(h > ma){
            ma = h;
        }
    }
    for(int i =n-k+1; i > k; --i){
        h = dp[i];
        h+=dpp[i-k];
        if(h == ma){
            r = i;
        }
    }
    for(int i = 1; i <= r-k; ++i){
        if(dp[i] == ma-dp[r]){
            l = i;
            break;
        }
    }
    cout << l << " " << r;
    return 0;
}