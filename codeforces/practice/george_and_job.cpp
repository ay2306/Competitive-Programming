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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;
// int n,m;
vector<ll> arr;
vector<ll> sp;
vector<vector<ll> > dp;
ll n,m,k;
int main(){
    cin >> n >> m >> k;
    arr = vector<ll> (n);
    sp = vector<ll> (n);
    dp = vector<vector<ll> >(n,vector<ll> (k+1,0));
    for(int i = 0; i < n; ++i)cin >> arr[i];
    sp[0] = arr[0];
    loop(i,1,n)sp[i]=arr[i]+sp[i-1];
    dp[m-1][1] = sp[m-1];
    for(int i = m; i < n; ++i){
        for(int j = 1; j <= k; ++j){
            dp[i][j] = max(dp[i-1][j],dp[i-m][j-1]+sp[i]-sp[i-m]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(dp[i][k],ans);
    }
    cout << ans;
    return 0;
}