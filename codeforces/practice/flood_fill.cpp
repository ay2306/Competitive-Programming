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
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    int n;
    cin >> n;
    V<int> a(1,-1);
    V<int> b(1,-1);
    loop(i,0,n){
        int k;
        cin >> k;
        if(a.back() == k)continue;
        a.pb(k);
        b.pb(k);
    }
    reverse(b.begin()+1,b.end());
    n = a.size()-1;
    V<V<int>> dp(n+10,V<int>(n+10,0));
    loop(i,1,n+1){
        loop(j,1,n+1){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // printf("  / ");
    // loop(i,1,n+1)printf("%3d ",b[i]);
    // printf("\n");
    // loop(i,1,n+1){
    //     printf("%3d ",a[i]);
    //     loop(j,1,n+1)printf("%3d ",dp[i][j]);
    //     printf("\n");
    // }
    // cout << dp[n][n] << "\n";
    cout << n - (dp[n][n]+1)/2;
   return 0;
}