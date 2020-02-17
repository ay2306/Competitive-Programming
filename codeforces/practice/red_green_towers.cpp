#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 2e5+10;
const ll inf = 1e9;
const double pi = acos(-1);

ll dp[2][maxn];

int main(){
    int r,g;
    scanf("%d%d",&r,&g);
    int h = 1;
    while(((h*(h+1)) >> 1) <= r+g)h++;
    h--;
    dp[0][0] = 1;
    int a[maxn] = {0};
    loop(i,1,h+1){
        ll lim = min((h*(h+1)) >> 1,g)+1;
        loop(j,0,lim){
            dp[1][j] = ((r >= ((i*(i+1))>>1) - j) ? dp[0][j]:0) + (j >= i ? dp[0][j-i]:0);
            dp[1][j] %= MOD;
            a[j] = dp[1][j];
        }
        loop(j,0,lim)dp[0][j]=a[j];
    }
    ll ans = 0;
    loop(i,0,g+1)ans=(ans+dp[1][i])%MOD;
    cout << ans << "\n";
   return 0;
}