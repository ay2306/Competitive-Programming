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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    V<V<int>> factors(n+1);
    loop(i,1,n+1){
        for(int j = 1; j*j <= i; ++j){
            if(i%j == 0){
                factors[i].pb(j);
                if(j*j != i){
                    factors[i].pb(i/j);
                }
            }
        }
    }
    V<V<ll>> dp(k+1,V<ll>(n+1,0));
    for(int j = 1; j <= n; ++j)dp[1][j] = 1;
    for(int i = 2; i <= k; ++i){
        for(int j = 1; j <= n; ++j){
            for(auto &fact: factors[j]){
                dp[i][j]+=dp[i-1][fact];
                dp[i][j]%=MOD;
            }
        }
    }
    ll ans = 0;
    for(auto &i: dp[k])ans = (ans+i)%MOD;
    cout << ans << "\n";
    return 0;
}