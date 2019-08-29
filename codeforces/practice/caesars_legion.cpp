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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const ll mod = 1e8;
const double pi = acos(-1);
ll dp[101][101][2][11];
ll k2,k1;
ll rec(ll n1, ll n2, ll type, ll k){
    if(n1 == 0 && n2 == 0)return 1;
    ll &ans = dp[n1][n2][type][k];
    if(ans != -1)return ans;
    ans = 0;
    if(type == 0){
        if(n2 > 0)ans=(ans + rec(n1,n2-1,1,1))%mod;
        if(k < k1 && n1 > 0)ans=(ans+rec(n1-1,n2,0,k+1)%mod);
    }
    else{
        if(n1 > 0)ans=(ans + rec(n1-1,n2,0,1))%mod;
        if(k < k2 && n2 > 0)ans=(ans+rec(n1,n2-1,1,k+1)%mod);
    }
    return ans;
}

int main(){
    init(dp,-1);
    ll n1,n2;
    cin >> n1 >> n2 >> k1 >> k2;
    cout << rec(n1,n2,0,0)%mod;
   return 0;
}