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
    ll dp[100100] = {0};
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = dp[3] + 2;
    for(int i = 5; i < 100100; ++i){
        dp[i] = dp[i-1] + i - 2;
    }
    int n;
    ll d;
    cin >> n >> d;
    ll ans = 0;
    vector<ll> arr(n);
    for(int i = 0; i < n; ++i)cin >> arr[i];
    for(int i = 0; i < n-1; ++i){
        ll p = lower_bound(arr.begin(),arr.end(),arr[i]+d+1) - arr.begin();
        p = p-i;
        ans+=dp[p];
        // cout << p << "  " << dp[p] << "\n";
    }
    cout << ans;
    return 0;
}