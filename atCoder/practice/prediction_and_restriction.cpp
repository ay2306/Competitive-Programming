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
#define FILE_READ_OUT fr(eopen("output.txt","w",stdout);
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
const int N = 1e5+10;
ll dp[N][3];
ll r,s,p;
int n,k;
string a;

int winner(char a){
    if(a == 'r')return 1;
    if(a == 'p')return 2;
    return 0;
}
ll cost(int a){
    if(a == 0)return r;
    if(a == 1)return p;
    return s;
}
int main(){
    cin >> n >> k;
    cin >> r >> s >> p;
    cin >> a;
    loop(i,0,k){
        if(i >= a.size())break;
        dp[i][winner(a[i])] += cost(winner(a[i]));
    }
    loop(i,k,n){
        dp[i][0] = max(dp[i-k][1],dp[i-k][2]);
        dp[i][1] = max(dp[i-k][0],dp[i-k][2]);
        dp[i][2] = max(dp[i-k][1],dp[i-k][0]);
        dp[i][winner(a[i])]+=cost(winner(a[i]));
    }
    ll ans = 0;
    loop(i,0,k){
        if(i >= a.size())break;
        auto o = dp[n-1-i];
        ans+=max({o[0],o[1],o[2]});
    }
    cout << ans << "\n";
   return 0;
}