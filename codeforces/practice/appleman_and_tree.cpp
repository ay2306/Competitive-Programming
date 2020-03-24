#include <bits/stdc++.h>
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
#define pb emplace_back
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
const ll N = 1e5 + 10;
const ll inf = 1e9;
const double pi = acos(-1);

int n;
V<int> g[N];
int col[N];
ll dp[N][2];
void dfs(int s, int p = -1){
    dp[s][col[s]] = 1;
    for(auto &i : g[s]){
        if(i == p)continue;
        dfs(i,s);
        dp[s][1] = ((dp[s][1]*(dp[i][1]+dp[i][0]))%MOD + (dp[s][0]*dp[i][1])%MOD)%MOD;
        dp[s][0] = (dp[s][0]*(dp[i][1]+dp[i][0]))%MOD;
    }
}
void solve(int test_case){
    scanf("%d",&n);
    loop(i,1,n){
        int a;
        scanf("%d",&a);
        g[a].pb(i);
        g[i].pb(a);
    }
    loop(i,0,n){
        cin >> col[i];
    }
    dfs(0);
    printf("%lld\n",dp[0][1]);
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
